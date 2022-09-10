# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 11:06:28 2021

@author: baugstein
"""

import pandas as pd
import matplotlib.pyplot as plt


dataNone = pd.read_csv('outputNone.txt',sep='\s+',header=None)
dataCoulomb = pd.read_csv('outputCoulomb.txt',sep='\s+',header=None)
dataVolker = pd.read_csv('outputVoker.txt',sep='\s+',header=None)
dataCos = pd.read_csv('outputCos7.txt',sep='\s+',header=None)



def plotArrayFromFile(data,title):  
    x = data[0]
    y = data[1]
    z = data[2]
    plt.plot(x, y,'r',label='x')
    plt.plot(x, z,'b--',label='y') 
    plt.title(title + ' distance',fontsize = 20)
    plt.xlabel("time",fontsize = 15)
    plt.ylabel("distance",fontsize = 15)
    plt.legend(loc='upper right', frameon=False)
    plt.show()

plotArrayFromFile(pd.DataFrame(dataNone),'None')
plotArrayFromFile(pd.DataFrame(dataCoulomb),'Coulomb')
plotArrayFromFile(pd.DataFrame(dataVolker),'Volker')
plotArrayFromFile(pd.DataFrame(dataCos),'Cos7')


