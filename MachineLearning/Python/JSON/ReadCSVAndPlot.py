# -*- coding: utf-8 -*-
"""
Created on Mon Mar 14 18:43:59 2022

@author: baugstein
"""
import pandas as pd
import matplotlib.pyplot as plt
from pylab import rcParams

data0 = pd.read_csv("df_reduced.csv")
data3=data0[['Date','Market Value']]
item1=data3
item1.columns = ['ds','y']
item1.y = item1.y.astype('float')
item1.ds = item1.ds.astype('datetime64')
rcParams['figure.figsize'] = 20,5
plt.xlabel("Date")
plt.ylabel("MarketValue ($Millions)")
plt.plot(item1.ds, item1.y)
