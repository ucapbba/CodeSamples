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
x = data[1]
plt.plot(t, x,'r',label='position')
plt.xlabel("time")
plt.legend(loc='upper right', frameon=False)
plt.show()