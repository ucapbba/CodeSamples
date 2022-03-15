# -*- coding: utf-8 -*-
"""
Created on Mon Mar 14 17:21:11 2022

@author: baugstein
"""
import json 
import pandas as pd
from pylab import rcParams
import matplotlib.pyplot as plt

'''for understanding only - requires specific JSON file to run'''
with open('TimeSeriesFromLive.json') as json_file:
    print("loading JSON")
    data = json.load(json_file)
    datenew = data['value']
    print("Converting dict to df")
    df = pd.DataFrame(data['value']) #takes a long time
    print("Done")
    data1=df[['Date','Market Value','GroupByLevel1Value']]  
    
    data2=data1[data1['GroupByLevel1Value'].isna()]
    data2=data2[['Date','Market Value']]
    print(data2.dtypes)
    data2['Date']=pd.to_datetime(data2['Date'])
    print(data2.dtypes)
    data2.sort_values(by='Date', inplace=True)
    data2=data2[data2['Market Value']<10]
    item1=data2
    
    data2.to_csv('df_reduced.csv') 
    data3=data2[['Date','Market Value']]
    item1=data3
    item1.columns = ['ds','y']
    item1.y = item1.y.astype('float')
    item1.ds = item1.ds.astype('datetime64')

    rcParams['figure.figsize'] = 20,5
    plt.plot(item1.ds, item1.y)
