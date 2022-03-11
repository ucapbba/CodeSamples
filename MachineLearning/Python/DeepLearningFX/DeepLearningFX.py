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

fig.add_trace(go.Scatter(
                x=rates['Time Series'],
                y=rates['GBPUSD'],
                name="GBP/USD",
                line_color='green'))


fig.update_layout(title_text="Daily Exchange Rates (2000 - 2019)")
#fig.show()

def generate_dates(numdays):
    #Get todays date and all number of numdays previous and convert them to a string in Year-Month-Day Format
    base = datetime.datetime.today()
    date_list = [(base - datetime.timedelta(days=x)).strftime("%Y-%m-%d") for x in range(0, numdays)]
    return date_list


rates_clean = rates._get_numeric_data()
years = 20
dates = generate_dates(numdays=365*years)
print("Dates Sample: ", dates[0:10])
print(rates.iloc[0])
print(rates.iloc[0][3])



datescunt = rates["Time Series"]
GBPUSD= rates["GBPUSD"]

GBPUSDcleaned = [ x for x in GBPUSD if x.isdigit() ]
rates[rates["Time Series"].apply(lambda x: x.isnumeric())]
print(GBPUSD)

for i,j in rates.iterrows():
    print(i)
    print(j[2])


