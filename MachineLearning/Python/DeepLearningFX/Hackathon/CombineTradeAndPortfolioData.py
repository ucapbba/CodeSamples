# -*- coding: utf-8 -*-

import datetime as dt
from datetime import timedelta
import matplotlib.pyplot as plt

import pandas as pd

print('Reading folio data')
data_set = pd.read_excel('Data/Portfolio_data3_convert.xlsx',na_values='ND')
print('Done')



print('Reading trade data....')
data_set = pd.read_excel('Data/TradesConvertible2.xlsx',na_values='ND')
print('Done')

target_column = 'Net Amount'
dates = pd.date_range('15/01/2020', periods=720, freq='D')
trade_df_all = pd.DataFrame()

for idx,date in enumerate(dates):

    value= data_set.loc[data_set['Trade Date']==date]
    if not value.empty:
        value_sum = value.sum()
        amount = value_sum[target_column]
        dict = {'Date': date,target_column : amount}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
    else:
        dict = {'Date': date,target_column : 0}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)


'''trade_df_all['dt']=pd.trade_df_all(data_set['Trade Date'],format='%d/%m/%Y')
data_set.sort_values(by='dt')'''

# Show plo
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(trade_df_all['Date'],trade_df_all[target_column])

ax.set(xlabel="Trade Date",
       ylabel="Net Amount",
       title="Time Series")
plt.xticks(rotation=70)
