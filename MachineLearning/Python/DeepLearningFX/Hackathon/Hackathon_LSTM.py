#Importing Libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'
import openpyxl
#%matplotlib inline
from datetime import date

#Reading dataset
data_set = pd.read_excel('Data/Trade_data.xlsx', na_values='ND')

dates = pd.date_range('04/01/2021', periods=365, freq='D')
trade_df_all = pd.DataFrame()

for idx,date in enumerate(dates):

    value= data_set.loc[data_set['Trade Date']==date]
    if not value.empty:
        value_sum = value.sum()
        amount = value_sum['Net Amount']
        dict = {'Date': date,'Trade Amount' : amount}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
    else:
        dict = {'Date': date,'Trade Amount' : 0}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)

#Data frame
df = trade_df_all['Trade Amount']
#Preprocessing data set
df = np.array(df).reshape(-1,1)

from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()
df = scaler.fit_transform(df)

#Training and test sets
train = df[:200]
test = df[200:]

print(train.shape)
print(test.shape)

def get_data(data, look_back):
  datax, datay = [],[]
  for i in range(len(data)-look_back-1):
    datax.append(data[i:(i+look_back),0])
    datay.append(data[i+look_back,0])
  return np.array(datax) , np.array(datay)

look_back = 1

x_train , y_train = get_data(train, look_back)
print(x_train.shape)
print(y_train.shape)

x_test , y_test = get_data(test,look_back)
print(x_test.shape)
print(y_test.shape)

#Processing train and test sets for LSTM model
x_train = x_train.reshape(x_train.shape[0],x_train.shape[1], 1)
x_test = x_test.reshape(x_test.shape[0],x_test.shape[1], 1)
print(x_train.shape)
print(x_test.shape)

#Defining the LSTM model
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense,LSTM

n_features=x_train.shape[1]
model=Sequential()
model.add(LSTM(100,activation='relu',input_shape=(n_features,1)))
model.add(Dense(1))

print(model.summary())

#Compiling
model.compile(optimizer='adam', loss = 'mse')

#Training
model.fit(x_train,y_train, epochs = 20, batch_size=1)

y_pred = model.predict(x_test)

#Visualizing the results
plt.figure(figsize=(10,5))
plt.title('LSTM',fontsize = 20)
plt.plot(y_test , label = 'Actual', color = "darkblue",linestyle="dotted")
plt.plot(y_pred , label = 'Predicted', color = "red")
plt.rc('legend', fontsize = 15)
plt.xlim(0.0,160)
plt.xticks(fontsize = 15)
plt.yticks(fontsize = 15)
plt.grid(True)
plt.legend()