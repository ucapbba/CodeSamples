# -*- coding: utf-8 -*-
"""
Created on Sun Aug 22 22:19:21 2021

@author: baugstein
"""

import pandas as pd
data = pd.read_csv('outputTimes.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt
x = data[0]
y = data[1]
plt.plot(x, y,'r--')
plt.xlabel("ionisation time (laser periods)")
plt.ylabel("return time (laser periods)")
plt.show()