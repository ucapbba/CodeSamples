import pandas as pd
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'

from prophet import Prophet
from pylab import rcParams
import matplotlib.pyplot as plt
import lightgbm as lgb #popular model choice
import seaborn as sns #alternative charting function
import matplotlib.dates as mdates

#-----------------------------------------
#folio indicators
#-----------------------------------------
data_set = pd.read_csv('Data/Portfolio_data2.csv',engine = 'python')
print(data_set.tail(40))
print(data_set.info()) #now see float 64 (aside from time serie)
#trade_df=trade_df[trade_df['Hierarchy']=='   EUR versus USD'] #to filter on specific trades
#dates = pd.date_range('04/01/2021', periods=365, freq='D')

data_set=data_set[data_set['GroupByCriteriaValues']=='AMERICAN DOLLAR']
data_set=data_set[data_set['Indicator']=='Asset Fx Delta']

#data_set=pd.melt(data_set, id_vars=['Date'], value_vars=['Result'])

data_set['lag_t1'] = data_set['Result'].transform(lambda x: x.shift(1))
data_set['lag_t5'] = data_set['Result'].transform(lambda x: x.shift(5))
def get_direction(row1, row2):
    if row2 >= row1:
        return 1
    else:
        return 0   
data_set['Direction1'] = data_set[['lag_t1', 'Result']].apply(lambda i: get_direction(i[0], i[1]), axis=1)
data_set['Direction5'] = data_set[['lag_t5', 'Result']].apply(lambda i: get_direction(i[0], i[1]), axis=1)
#data_set['ResultChange'] = data_set['Result'].transform(lambda x: x.shift(1))
data_set['sma5'] = data_set['Result'].rolling(5).mean()
data_set['rolling_mean_t1_t14'] = data_set['lag_t1'].rolling(14,min_periods=1).mean()
from datetime import datetime
data_set['dt']=pd.to_datetime(data_set['Date'],format='%d/%m/%Y')
data_set.info()
data_set['week'] = data_set['dt'].dt.week 
data_set['day'] = data_set['dt'].dt.day
data_set['month'] = data_set['dt'].dt.month
data_set['dayofweek'] = data_set['dt'].dt.dayofweek




# Show plot 
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(data_set['Date'],data_set['Result'])
plt.plot(data_set['Date'],data_set['sma5'])
plt.plot(data_set['Date'],data_set['rolling_mean_t1_t14'])
ax.set(xlabel="Date",
       ylabel="Asset Value FX Delta",
       title="Time Series")

every_nth = 10
for n, label in enumerate(ax.xaxis.get_ticklabels()):
    if n % every_nth != 0:
        label.set_visible(False)

plt.xticks(rotation=70)
print("plotting graph - takes around 10 seconds ...... ")
#plt.show()
print("done")
#fig = px.line(data_set, x='Date', y='value', color='variable')     
#fig.show()

useless_cols = ['dt','Date','GroupByCriteriaNames','GroupByCriteriaValues','Indicator','Unnamed: 5']
train_cols = data_set.columns[~data_set.columns.isin(useless_cols)]
date='02/01/2022'
x_train = data_set[:100]
#The variable we want to predict is AUD to USD rate.
y_train = x_train['Result']#.to_frame()

#The LGBM model needs a train and validation dataset to be fed into it
x_val = data_set[100:150]
y_val = x_val['Result']#.to_frame()

#We shall test the model on data it hasn't seen before or been used in the training process
test = data_set[150:350]

#Setup the data in the necessary format the LGB requires
train_set = lgb.Dataset(x_train[train_cols], y_train)
val_set = lgb.Dataset(x_val[train_cols], y_val)

#Set the model parameters
params = {
        "objective" : "regression", # regression is the type of business case we are running
        "metric" :"rmse", #root mean square error is a standard metric to use
#         "force_row_wise" : True,
        "learning_rate" : 0.05, #the pace at which the model is allowed to reach it's objective of minimising the rsme.
#         "sub_feature" : 0.8,
#         "sub_row" : 0.75,
#         "bagging_freq" : 1,
        "lambda_l1" : 0.1, #lambda_l1 worked better than l2 in this case, as we have high number of features this makes sense (L1 or Lasso reduces some terms to 0 weight, whereas L2 or ridge includes all)
#         "nthread" : 4
        'verbosity': 1, 
#         'num_iterations' : 300,
        'num_leaves': 100, # minimum number of leaves in each boosting round
        "min_data_in_leaf": 25, #minimum amount of data in the leaf nodes or last value of the tree
        "early_stopping": 50, #if the model does not improve after this many consecutive rounds, call a halt to training
#         "max_bin" = 
        "sub_sample" : 0.025, #sampling feature to reduce overfitting
#         "boosting":"dart",
}

#Run the model
m_lgb = lgb.train(params, train_set, num_boost_round = 2500, valid_sets = [train_set, val_set], verbose_eval = 50)

#plot feature importance
feature_imp = pd.DataFrame({'Value':m_lgb.feature_importance(),'Feature':train_cols})
plt.figure(figsize=(20, 10))
sns.set(font_scale = 1)
sns.barplot(x="Value", y="Feature", data=feature_imp.sort_values(by="Value", 
                                                    ascending=False)[0:40])
plt.title('LightGBM Features (avg over folds)')
plt.tight_layout()
plt.savefig('lgbm_importances-01.png')
plt.show()

#generate predictions on test data
y_pred = m_lgb.predict(test[train_cols])
test['Result_pred'] = y_pred

#view the test data in chart form
#df_long=pd.melt(test, id_vars=['Date'], value_vars=['Result', 'Result_pred'])

# plotly 
#fig = px.line(df_long, x='Date', y='value', color='variable')

fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(test['Date'],test['Result_pred'],'b--')
plt.plot(test['Date'],test['Result'],'r--')
ax.set(xlabel="Date",
       ylabel="Asset Value FX Delta",
       title="Time Series")
every_nth = 10
for n, label in enumerate(ax.xaxis.get_ticklabels()):
    if n % every_nth != 0:
        label.set_visible(False)

plt.xticks(rotation=70)

print("plotting graph - takes around 10 seconds ...... ")
plt.show()
print("done")

# Show plot 
#fig.show()
