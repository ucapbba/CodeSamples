import pandas as pd
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'

from prophet import Prophet
from pylab import rcParams
import matplotlib.pyplot as plt
import lightgbm as lgb #popular model choice
import seaborn as sns #alternative charting function
#-----------------------------------------
#folio indicators
#-----------------------------------------
'''folio_df = pd.read_csv('Data/Portfolio_data.csv',engine = 'python')

print(folio_df.tail(40))
print(folio_df.info()) #now see float 64 (aside from time serie)

#todo - filter for specific position / take largest empty position
folio_df=folio_df[folio_df['GroupByCriteriaValues']=='AMERICAN DOLLAR']
folio_df=folio_df[folio_df['Indicator']=='Asset Fx Delta']

#sum all positions 
#folio_df=folio_df[folio_df['GroupByCriteriaValues']!=''] #doesn't filter

folio_plot=pd.melt(folio_df, id_vars=['Date'], value_vars=['Result'])

fig = px.line(folio_plot, x='Date', y='value', color='variable')
# Show plot 
fig.show()
'''
#-----------------------------------------
#Gradient Boosting - Model folio indicators 
#-----------------------------------------
#x_train = folio_df[folio_df['date'] <= 'nope'] #dataset WAY too small test train and validate
#Same will be true for LTSM
#y_train = x_train['AUSTRALIA - AUSTRALIAN DOLLAR/US$']


#-----------------------------------------
#trade indicators
#-----------------------------------------
trade_df = pd.read_excel('Data/Trade_data.xlsx')
print(trade_df.tail(40))
print(trade_df.info()) #now see float 64 (aside from time serie)
#trade_df=trade_df[trade_df['Hierarchy']=='   EUR versus USD'] #to filter on specific trades
dates = pd.date_range('04/01/2021', periods=365, freq='D')
print(trade_df.iloc[0]['Trade Date'])

trade_df_all = pd.DataFrame()

for idx,date in enumerate(dates):
  
    value= trade_df.loc[trade_df['Trade Date']==date]
    if not value.empty:
        value_sum = value.sum()
        amount = value_sum['Net Amount']
        dict = {'Date': date,'Trade Amount' : amount}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
    else:
        dict = {'Date': date,'Trade Amount' : 0}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
       
trade_plot=pd.melt(trade_df_all, id_vars=['Date'], value_vars=['Trade Amount'])
fig = px.line(trade_plot, x='Date', y='value', color='variable')
# Show plot 
fig.show()


x_train = trade_df_all[trade_df_all['Date'] <= '2022-01-02']
#The variable we want to predict is AUD to USD rate.
y_train = x_train['Trade Amount']

#define train columns to use in model
train_cols = trade_df_all['Trade Amount']

#The LGBM model needs a train and validation dataset to be fed into it, let's use Nov 2019
x_val = trade_df_all[(trade_df_all['Date'] > '2022-01-02') & (trade_df_all['Date'] <= '2022-03-03')]
y_val = x_val['Trade Amount']

#Setup the data in the necessary format the LGB requires
train_set = lgb.Dataset(x_train['Date'], y_train)
val_set = lgb.Dataset(x_val['Date'], y_val)

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

