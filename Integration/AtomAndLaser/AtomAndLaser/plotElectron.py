# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 11:06:28 2021

@author: baugstein
"""

import pandas as pd
data = pd.read_csv('output.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt

x = data[0]
y = data[1]
z = data[2]
plt.plot(x, y,'r',label='x')
plt.plot(x, z,'b--',label='y')
plt.xlabel("time")
plt.legend(loc='upper right', frameon=False)
plt.show()