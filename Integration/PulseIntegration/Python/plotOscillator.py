# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 11:06:28 2021

@author: baugstein
"""

import pandas as pd
import matplotlib.pyplot as plt
data = pd.read_csv('../output.txt',sep='\s+',header=None)
data = pd.DataFrame(data)


t = data[0]
AInt = data[1]
A = data[3]
A2Int = data[2]
A2 = data[4]
plt.plot(t, AInt,'r',label='AInt')
plt.plot(t, A,'b',label='AField')
#plt.plot(t, A2Int,'r',label='A2Int')
#plt.plot(t, A2,label='A2')
plt.xlabel("time (cycles)")
plt.legend(loc='upper right', frameon=False)
plt.show()