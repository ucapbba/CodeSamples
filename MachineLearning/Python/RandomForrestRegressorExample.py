# -*- coding: utf-8 -*-
"""
Created on Fri Mar 18 07:09:53 2022

@author: baugstein
"""
from sklearn.ensemble import RandomForestRegressor
from sklearn.datasets import make_regression
import matplotlib.pyplot as plt
import pandas as pd
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'

X, y = make_regression(n_features=4, n_informative=2, random_state=0, shuffle=False)

df = pd.DataFrame(X)
df_y = pd.DataFrame(y)
df.columns = ['1','2','3','4']
df['y']=df_y
df.sort_values(by=['1'])
df_long=pd.melt(df, id_vars=['1'], value_vars=['y'])
# plotly 
fig = px.line(df_long, x='1', y='value', color='variable')
# Show plot 
fig.show()


regr = RandomForestRegressor(max_depth=2, random_state=0)
regr.fit(X, y)
#RandomForestRegressor(...)

print(regr.predict([[0, 0, 0, 0]]))
