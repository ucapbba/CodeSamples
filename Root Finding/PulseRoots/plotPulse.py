# -*- coding: utf-8 -*-
"""
Created on Sun Aug 22 22:19:21 2021

@author: baugstein
"""

import pandas as pd
data = pd.read_csv('outputTimes.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt
t = data[0]
A = data[1]
E = data[2]
dE = data[3]
plt.plot(t, A,'r--')
plt.plot(t, E,'b--')
#plt.plot(t, dE,'g--')
plt.xlabel("(laser periods)")
plt.ylabel("amplitude")
plt.show()