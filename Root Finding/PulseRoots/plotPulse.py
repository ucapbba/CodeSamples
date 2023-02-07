# -*- coding: utf-8 -*-
"""
Created on Sun Aug 22 22:19:21 2021

@author: baugstein
"""
import pandas as pd
import matplotlib.pyplot as plt

pulse = pd.read_csv('output/pulse.txt',sep='\s+',header=None)
pulse = pd.DataFrame(pulse)
crossings = pd.read_csv('output/crossings.txt',sep='\s+',header=None)
crossings = crossings[0].values
maxima = pd.read_csv('output/maxima.txt',sep='\s+',header=None)
maxima = maxima[0].values

t = pulse[0]
A = pulse[1]
E = pulse[2]
dE = pulse[3]
#plt.plot(t, A,'r--')
plt.plot(t, E,'r-')
#plt.plot(t, dE,'g--')
plt.xlabel("(laser periods)")
plt.ylabel("amplitude")
plt.axhline(y=0.0, color='black', linestyle='-')

for crossing in crossings:
    plt.axvline(x=crossing, color='black', linestyle='--')
for maximum in maxima:
    plt.axvline(x=maximum, color='b', linestyle='--')

plt.show()