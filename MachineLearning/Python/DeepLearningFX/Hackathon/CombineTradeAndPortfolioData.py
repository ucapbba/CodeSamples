# -*- coding: utf-8 -*-

import datetime as dt
from datetime import timedelta
import matplotlib.pyplot as plt

import pandas as pd

print('Reading FX folio data')
data_set_folio_FX = pd.read_excel('Data/Portfolio_data3_convert_USD_only.xlsx',na_values='ND')
print('Done')
folio_column_delta = 'More Columns.Asset Fx Delta'
data_set_folio_FX=data_set_folio_FX[data_set_folio_FX['More Columns.GroupByLevel1Value']=='AMERICAN DOLLAR']

print('Reading Share folio data')
data_set_folio_value = pd.read_excel('Data/Portfolio_data3_convert_shares_filtered.xlsx',na_values='ND')  #contains everything - not well analysed
print('Done')
folio_column_value = 'More Columns.Market Value'

print('Reading trade data....')
data_set_trade = pd.read_excel('Data/TradesConvertible2.xlsx',na_values='ND')
print('Done')
print(data_set_trade.tail(40))
print(data_set_trade.info()) #now see float 64 (aside from time serie)
trade_column = 'Net Amount'

dates = pd.date_range('14/01/2020', periods=720, freq='D')
trade_df_all = pd.DataFrame(columns=['Date',trade_column,folio_column_delta,folio_column_value])

traderowindex=0

for idx,date in enumerate(dates):
    print(idx)
    
    FXDelta=0
    MarketValue=0
    rowfolio= data_set_folio_FX.loc[data_set_folio_FX['Date']==date]
    if not rowfolio.empty:
         value_sum = rowfolio.sum()
         FXDelta = value_sum[folio_column_delta]
   
    rowfoliovalue= data_set_folio_value.loc[data_set_folio_value['Date']==date]
    if not rowfoliovalue.empty:
         market_value_sum = rowfolio.sum()
         MarketValue = market_value_sum[folio_column_value]
        
        
    rowtrade= data_set_trade.loc[data_set_trade['Trade Date']==date]
    if not rowtrade.empty:
        value_sum = rowtrade.sum()
        amount = value_sum[trade_column]
        isUSDvsEUR = rowtrade['Hierarchy'][traderowindex]=='   EUR versus USD'
        print(date)
        print(isUSDvsEUR)
        if isUSDvsEUR== False: #reverse amount for USD vs EUR (same for EUR vs USD)
          amount=-amount
        #dict = {'Date': date,target_column : amount}
        #newrow = pd.DataFrame(date,amount)
        trade_df_all = trade_df_all.append({'Date': date,trade_column : amount,folio_column_delta:FXDelta,folio_column_value:MarketValue}, ignore_index = True)
        traderowindex+=len(rowtrade) #pretty sure this is horrific coding practice
    else:
        trade_df_all = trade_df_all.append({'Date': date,trade_column : 0,folio_column_delta:FXDelta,folio_column_value:MarketValue}, ignore_index = True)


'''trade_df_all['dt']=pd.trade_df_all(data_set['Trade Date'],format='%d/%m/%Y')
data_set.sort_values(by='dt')'''

# Show plot trade
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(trade_df_all['Date'],trade_df_all[trade_column],label = 'Trade', color = "red")
ax.set(xlabel="Trade Date",
       ylabel="Net Amount",
       title="Trade Data")
# Show plot folio
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(trade_df_all['Date'],trade_df_all[folio_column_delta],label = 'Folio FX Delta', color = "blue")
ax.set(xlabel="Trade Date",
       ylabel="FX Delta",
       title="Folio Data")

# Show plot folio - Market Value
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(trade_df_all['Date'],trade_df_all[folio_column_value],label = 'Market Value', color = "green")
ax.set(xlabel="Trade Date",
       ylabel="Market Value",
       title="Folio Data")

# Show plot
fig, ax = plt.subplots(figsize=(12, 12))
plt.plot(trade_df_all['Date'],trade_df_all[trade_column],label = 'Trade', color = "red")
plt.plot(trade_df_all['Date'],trade_df_all[folio_column_delta],label = 'Folio FX Delta', color = "blue")

plt.rc('legend', fontsize = 15)
plt.legend()
ax.set(xlabel="Trade Date",
       ylabel="Net Amount",
       title="All Data (without market value)")
plt.xticks(rotation=70)
