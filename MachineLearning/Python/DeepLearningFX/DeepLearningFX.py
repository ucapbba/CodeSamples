# -*- coding: utf-8 -*-
"""
Created on Fri Mar 11 08:07:09 2022

@author: baugstein
"""

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import plotly.graph_objects as go
from plotly import __version__
from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot
import plotly.io as pio
from pandas.plotting import scatter_matrix
import matplotlib.pyplot as plt

import datetime
from datetime import date

pio.renderers.default='browser'
rates = pd.read_csv('Foreign_Exchange_Rates.csv')

print(rates.tail(40))

fig = go.Figure()
'''
fig.add_trace(go.Scatter(
                x=rates['Time Serie'],
                y=rates['EURO AREA - EURO/US$'],
                name="EUR/USD",
                line_color='orange'))'''

#remove NDs from array
rates.drop(rates[rates['GBPUSD'] == 'ND'].index, inplace = True)
fig.add_trace(go.Scatter(
                x=rates['Time Series'],
                y=rates['GBPUSD'],
                name="GBP/USD",
                line_color='green'))


fig.update_layout(title_text="Daily Exchange Rates (2000 - 2019)")
fig.show()

rates[rates!='ND']
print(rates.iloc[0])
print(rates.iloc[0][3])

dates = rates["Time Series"]
GBPUSD= rates["GBPUSD"]
plt.plot(dates,GBPUSD)
plt.show()




