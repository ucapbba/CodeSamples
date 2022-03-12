# -*- coding: 
'''
sample from https://www.kaggle.com/stpeteishii/rand-us-exchage-rates-prophet
'''
import gc
from tqdm import tqdm
import numpy as np
import pandas as pd
from pylab import rcParams
import matplotlib.pyplot as plt
from sklearn.metrics import mean_squared_error
from scipy.stats import probplot

import datetime as dt
from datetime import date
from datetime import timedelta
from prophet import Prophet

import os
import warnings
warnings.filterwarnings("ignore")

data0 = pd.read_csv("Foreign_Exchange_Rates.csv")
data0[-5:]

print(data0.info())

cols=data0[data0['SOUTH AFRICA - RAND/US$']=='ND'].index.tolist()
print(cols)

data0=data0.drop(index=cols)
print(data0.columns)

data1=data0[['Time Serie','EURO AREA - EURO/US$']]

item1=data1

item1.columns = ['ds','y']
item1.y = item1.y.astype('float')
item1.ds = item1.ds.astype('datetime64')

rcParams['figure.figsize'] = 20,5
plt.plot(item1.ds, item1.y)

ph = Prophet()
ph.fit(item1)
forecast1=ph.predict(item1)
figure = ph.plot(forecast1)
figure.show()

from datetime import timedelta
start0 = dt.datetime.strptime('2019-01-01','%Y-%m-%d').date()
end0   = dt.datetime.strptime('2021-12-31','%Y-%m-%d').date()
print((end0-start0).days)

def daterange(start,end):
    for i in range((end-start).days):
        return start+timedelta(i)  
    
dates0=[]
for i in range((end0-start0).days):
    dates0+=[(start0+timedelta(i)).strftime('%Y-%m-%d') ]
print(dates0[0:10])

dates0_df=pd.DataFrame(dates0)
dates0_df.columns=['ds']
dates0_df

ph = Prophet()
ph.fit(item1[-365*2:])
forecast3=ph.predict(dates0_df)
figure = ph.plot(forecast3)
figure.show()