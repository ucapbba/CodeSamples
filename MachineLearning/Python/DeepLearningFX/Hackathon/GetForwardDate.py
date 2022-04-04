# -*- coding: utf-8 -*-

import pandas as pd
import matplotlib.pyplot as plt

print('Reading trade data....')
data_set = pd.read_excel('Data/TradesConvertible2.xlsx',na_values='ND')
print('Done')
print(data_set.tail(40))
print(data_set.info()) #now see float 64 (aside from time serie)

data_set['days']=(data_set['Value Date']-data_set['Trade Date']).dt.days
#data_set = data_set[data_set['days']>20]
data_set['days30'] = data_set['days'].rolling(30).mean()
data_set['days60'] = data_set['days'].rolling(60).mean()




fig, ax = plt.subplots(figsize=(12, 12))
ax.set(xlabel="Date",
       ylabel="Forward Date",
       title="Forward Date")
plt.xticks(rotation=70)
#plt.plot(data_set['Trade Date'],data_set['days'])
plt.plot(data_set['Trade Date'],data_set['days30'])
plt.plot(data_set['Trade Date'],data_set['days60'])