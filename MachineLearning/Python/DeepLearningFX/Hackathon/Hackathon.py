import pandas as pd
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'


#-----------------------------------------
#folio indicators
#-----------------------------------------
folio_df = pd.read_csv('Data/Portfolio_data.csv',engine = 'python')

print(folio_df.tail(40))
print(folio_df.info()) #now see float 64 (aside from time serie)

#todo - filter for specific position / take largest empty position
folio_df=folio_df[folio_df['GroupByCriteriaValues']=='AMERICAN DOLLAR']
folio_df=folio_df[folio_df['Indicator']=='Asset Fx Delta']

#sum all positions 
#folio_df=folio_df[folio_df['GroupByCriteriaValues']!=''] #doesn't filter

folio_plot=pd.melt(folio_df, id_vars=['Date'], value_vars=['Result'])

fig = px.line(folio_plot, x='Date', y='value', color='variable')
# Show plot 
#fig.show()


from prophet import Prophet
from pylab import rcParams
import matplotlib.pyplot as plt
#-----------------------------------------
#Prophet - Model folio indicators 
#-----------------------------------------
folio_df_2 = folio_df[['Date','Result']]
item1=folio_df_2
item1.columns = ['ds','y']
item1.y = item1.y.astype('float')
item1.ds = item1.ds
item1.sort_values('ds')
rcParams['figure.figsize'] = 20,5
plt.plot(item1.ds, item1.y)
plt.xlabel("Date")
plt.ylabel("MarketValue ($Millions)")
ph = Prophet()
ph.fit(item1)
forecast1=ph.predict(item1)
figure = ph.plot(forecast1)
figure.show()



#-----------------------------------------
#trade indicators
#-----------------------------------------
trade_df = pd.read_excel('Data/Trade_data.xlsx')
print(trade_df.tail(40))
print(trade_df.info()) #now see float 64 (aside from time serie)
#trade_df=trade_df[trade_df['Hierarchy']=='   EUR versus USD'] #to filter on specific trades
dates = pd.date_range('04/01/2021', periods=365, freq='D')
print(trade_df.iloc[0]['Trade Date'])

trade_df_all = pd.DataFrame()

for idx,date in enumerate(dates):
  
    value= trade_df.loc[trade_df['Trade Date']==date]
    if not value.empty:
        value_sum = value.sum()
        amount = value_sum['Net Amount']
        dict = {'Date': date,'Trade Amount' : amount}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
    else:
        dict = {'Date': date,'Trade Amount' : 0}
        trade_df_all = trade_df_all.append(dict, ignore_index = True)
       
trade_plot=pd.melt(trade_df_all, id_vars=['Date'], value_vars=['Trade Amount'])
fig = px.line(trade_plot, x='Date', y='value', color='variable')
# Show plot 
fig.show()

#-----------------------------------------
#Prophet - Model trade indicators 
#-----------------------------------------
item1=trade_df_all
item1.columns = ['ds','y']
item1.y = item1.y.astype('float')
item1.ds = item1.ds.astype('datetime64')

rcParams['figure.figsize'] = 20,5
plt.plot(item1.ds, item1.y)
plt.xlabel("Date")
plt.ylabel("MarketValue ($Millions)")
ph = Prophet()
ph.fit(item1)
forecast1=ph.predict(item1)
figure = ph.plot(forecast1)
figure.show()