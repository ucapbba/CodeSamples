# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 11:06:28 2021

@author: baugstein
"""

import pandas as pd
data = pd.read_csv('output.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt

time = data[0]
x_jupyter= data[4]
y_jupyter = data[5]
x_saturn= data[7]
y_saturn = data[8]
x_uranus= data[10]
y_uranus = data[11]
x_pluto= data[16]
y_pluto = data[17]

value = x_jupyter[0]

plt.plot(time, x_jupyter,'r',label='x_jupyter')
plt.plot(time, y_jupyter,'b--',label='y_jupyter')
plt.plot(time, x_pluto,'r',label='x_pluto')
plt.plot(time, y_pluto,'b--',label='y_pluto')
plt.xlabel("time")
plt.legend(loc='upper right', frameon=False)
plt.show()

ax = plt.axes(projection='3d')
ax.set_xlabel('time')
ax.set_ylabel('x')
ax.set_zlabel('y');
ax.scatter3D(time, x_jupyter, y_jupyter,c=time,s=1, cmap='Greens');
ax.scatter3D(time, x_saturn, y_saturn, c=time,s=1,cmap='Reds');
ax.scatter3D(time, x_uranus, y_uranus, c=time,s=1,cmap='Blues');