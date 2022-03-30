import pandas as pd
import plotly.express as px #alternative charting function
import plotly.io as pio #graphs do not work in Spyder
pio.renderers.default='browser'

from prophet import Prophet
from pylab import rcParams
import matplotlib.pyplot as plt

#-----------------------------------------
#folio indicators
#-----------------------------------------
folio_df = pd.read_excel('Data/Portfolio_data3_convert.xlsx',na_values='ND')

print(folio_df.tail(40))
print(folio_df.info()) 

#todo - filter for specific position / take largest empty position
target_column = 'More Columns.Asset Fx Delta in %'
folio_df=folio_df[folio_df['More Columns.GroupByLevel1Value']=='AMERICAN DOLLAR']
folio_df_normal = folio_df[folio_df[target_column]<=10]

folio_plot=pd.melt(folio_df_normal, id_vars=['Date'], value_vars=target_column)

fig = px.line(folio_plot, x='Date', y='value', color='variable')
# Show plot 
#fig.show()

#-----------------------------------------
#Prophet - Model folio indicators 
#-----------------------------------------
folio_df_2 = folio_df_normal[['Date',target_column]]
item2=folio_df_2
item2.columns = ['ds','y']
item2.y = item2.y.astype('float')
item2.ds = item2.ds#.astype('datetime64')
item2.sort_values('ds')
rcParams['figure.figsize'] = 20,5
plt.plot(item2.ds, item2.y)
plt.xlabel("Date")
plt.ylabel("MarketValue ($Millions)")
ph = Prophet()
ph.fit(item2)
forecast1=ph.predict(item2)
figure = ph.plot(forecast1)
figure.show()


import datetime as dt
from datetime import timedelta
start0 = dt.datetime.strptime('2021-12-03','%Y-%m-%d').date()
end0   = dt.datetime.strptime('2022-06-30','%Y-%m-%d').date()
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
ph.fit(item2[-365*2:])
forecast3=ph.predict(dates0_df)
figure = ph.plot(forecast3)
figure.show()


'''
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
#fig.show()



#-----------------------------------------
#Prophet - Model trade indicators 
#-----------------------------------------
item1=trade_df_all
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
print(forecast1[['ds', 'yhat', 'yhat_lower', 'yhat_upper']].tail())
figure = ph.plot(forecast1)
fig2 = ph.plot_components(forecast1) #need ore data
figure.show()

##from prophet.plot import plot_plotly, plot_components_plotly -- not working 
#plot_plotly(ph, forecast1) 
#plot_components_plotly(ph, forecast1)

'''



