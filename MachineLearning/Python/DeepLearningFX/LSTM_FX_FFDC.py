# -*- coding: utf-8 -*-
"""
Created on Wed Mar 16 07:49:04 2022

@author: baugstein
"""

import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
from pylab import rcParams
import seaborn as sns
import pygal

#Machine Learning Libraries -- sklearn and keras

from sklearn.ensemble import RandomForestRegressor

from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error, explained_variance_score
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Activation, Input, LSTM, Dense

forex_df = pd.read_csv('HackathonData.csv',engine = 'python')

df_clean =forex_df[['ds','y']]
item1=df_clean 
item1.columns = ['ds','y']
item1.y = item1.y.astype('float')
item1.ds = item1.ds.astype('datetime64')

rcParams['figure.figsize'] = 20,5
plt.plot(item1.ds, item1.y)
plt.xlabel("Date")
plt.ylabel("MarketValue ($Millions)")

#Generate Technical indicators (Simple/Exponential Moving Averages)
df_clean ['sma5'] = df_clean ['y'].rolling(5).mean()
df_clean ['sma2'] = df_clean ['y'].rolling(2).mean()
df_clean ['sma3'] = df_clean ['y'].rolling(3).mean()
df_clean ['ema5'] = df_clean ['y'].ewm(span=5,min_periods=0,adjust=False,ignore_na=False).mean()
df_clean ['ema2'] = df_clean ['y'].ewm(span=2,min_periods=0,adjust=False,ignore_na=False).mean()
df_clean ['ema3'] = df_clean ['y'].ewm(span=3,min_periods=0,adjust=False,ignore_na=False).mean()

#Remove first 5 data points since will contain NaN from SMA5/EMA5
df_clean = df_clean.iloc[5:]
df_clean.head()

colormap = plt.cm.RdPu
plt.figure(figsize=(15,15))
plt.title('Pearson correlation of features', y=1.05, size=15)
sns.heatmap(df_clean.corr(), linewidths=0.1, vmax=1.0, square=True, cmap=colormap, linecolor='white', annot=True)
plt.show()

# Create Input and Target Data:
#Set number of days to predict ahead and an option to scale our data
future_prediction_days = 1
scale_data = True

#Create Forward column that has the shifted price
df_feat=df_clean
df_feat['Forward'] = df_feat['y'].shift(-1 * future_prediction_days)
df_feat = df_feat[:-1 * future_prediction_days]

#Create Direction column to get binary shifted price direction
def get_direction(row1, row2):
    if row2 >= row1:
        return 1
    else:
        return 0
    
df_feat['Direction'] = df_feat[['y', 'Forward']].apply(lambda i: get_direction(i[0], i[1]), axis=1)
df_feat['date']=pd.to_datetime(forex_df['ds'])
dates_index = df_feat.columns.tolist().index('date')
target_index = df_feat.columns.tolist().index('Forward')
#dataset = df_feat.values.astype('float32')

#Separate the Input from the Target  #TODO - what is X?
#X = df_feat[:, dates_index]
useless_cols = ['date','Forward','ds']
#define train columns to use in model
train_cols = df_feat.columns[~df_feat.columns.isin(useless_cols)]

X = df_feat[train_cols]
y = df_feat['Forward']


# Feature Analysis against Target:
plt.figure(figsize=(15,5))
corr = df_feat.iloc[:,:-1].corr()
sns.heatmap(corr[corr.index == 'Forward'], linewidths=0.1, vmax=1.0, square=True, cmap=colormap, linecolor='white', annot=True);


# Feature Importance:
#Build and Train a Random Forest with 100 estimators
forest = RandomForestRegressor(n_estimators = 100)
forest = forest.fit(X, y)

#Extract the feature column names and feature importances for the columns
column_list = df_feat.columns.values.tolist()
importances = forest.feature_importances_

#Zip the column names and importances togther and then sort them
col_imp = list(zip(column_list,importances))
sorted_col_imp = sorted(col_imp,key=lambda i: i[1],reverse=True)

#Create a pygal bar chart to plot the feature importances
bc = pygal.Bar(width=500, height=300, explicit_size=True)
bc.title = 'Forex Feature Importances'
for i in range(len(importances)):
    bc.add(sorted_col_imp[i][0], sorted_col_imp[i][1])
bc.render_in_browser()

# Train/Test Split:
#Set the percentage for training data
pct_train = .8

#Get the X,Y train/test sets
X_train = X[0:int(len(X)*pct_train)]
y_train = y[0:int(len(y)*pct_train)]
X_test = X[int(len(X)*pct_train):]
y_test = y[int(len(y)*pct_train):]

#Reshape our data into time series for an LSTM model
#X_train = X_train.reshape((X_train.shape[0],1,20))
#X_test = X_test.reshape((X_test.shape[0],1,20))

# Create Model:
model = Sequential()
model.add(LSTM(20, input_shape=(X_train.shape[1], X_train.shape[2]), return_sequences=True))
model.add(LSTM(20, return_sequences=True))
model.add(LSTM(10, return_sequences=True))
model.add(Dropout(0.2))
model.add(LSTM(4, return_sequences=False))
model.add(Dense(4, kernel_initializer='uniform', activation='relu'))
model.add(Dense(1, kernel_initializer='uniform', activation='relu'))
model.compile(loss='mean_squared_error', optimizer='adam', metrics=['mae', 'mse'])

print("Model Summary: ")
print(model.summary())
print("+++++++++++++++++++++++++++++++++++++++")

# Train Neural Network:
model.fit(X_train, y_train, epochs=100, batch_size=256)

# Train Set Performance:
#Get Training MSE
mse = model.history.history['mse']

#Build Line chart to show performance
line_chart = pygal.StackedLine(fill=True,width=500, height=300, explicit_size=True,
                              x_labels_major_every=10, show_minor_x_labels=False, x_label_rotation=45)
line_chart.title = 'Training Error'
line_chart.x_labels = [str(i) for i in range(100)]
line_chart.xlabel = 'Epoch'
line_chart.add('MSE', mse)
line_chart.render_in_browser()

# Test Set Performance:
#Obtain Predictions on our Test Set
preds = model.predict(X_test)

#Get Evaluation Metrics -- MSE, MAE, R2 Score, and Explained Variance Score
print("Model evaluation metrics: ")
print("Test MSE:",mean_squared_error(y_true=y_test,y_pred=preds))
print("Test MAE:  ",mean_absolute_error(y_true=y_test,y_pred=preds))
print("Test R2 Score: ",r2_score(y_pred=preds,y_true=y_test))
print("Explained Variance Score: ",explained_variance_score(y_pred=preds,y_true=y_test))
print("+++++++++++++++++++++++++++++++++++++++")

#Convert Preds and Actual Values on Test Set to Flat List for Plotting
preds_flat = preds.flatten().tolist()
y_test_flat = y_test.flatten().tolist()

#Plot Predictions vs Actual
line_chart = pygal.Line(width=500, height=300, explicit_size=True,x_labels_major_every=150, show_minor_x_labels=False, x_label_rotation=45)
line_chart.title = 'Test Predictions vs Actual'
line_chart.x_labels = df['Date'][::-1].iloc[int(0.8*len(df)):].tolist()
line_chart.add('Preds', preds_flat)
line_chart.add('Actual',  y_test_flat)
line_chart.render_in_browser()

# Save Model:
model.save('EUR_USD_1_Day_Forecast_2.h5')
print("Model saved to disk: EUR_USD_1_Day_Forecast_2.h5")