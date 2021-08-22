# -*- coding: utf-8 -*-
"""
Created on Sun Aug 22 08:02:20 2021

@author: baugstein
"""
import matplotlib.pyplot as plt
import numpy as np

def z_func1(t,E0,w,t0):
    return E0/(w*w)*np.cos(w*t) + E0/w*np.sin(w*t0)*(t - t0) - E0/(w*w)*np.cos(w*t0);

def v_func1(t,E0,w,t0):
    return -E0/w*np.sin((w*t))+E0/w*np.sin(w*t0)

def laser(t):
    return np.cos(t)

E0 = 0.5
w=0.057
t0=np.pi/6
Up = E0*E0/4/w/w
t = np.arange(0,10*np.pi/w,0.1)   # start,stop,step
z = z_func1(t,E0,w,t0)
v=v_func1(t,E0,w,t0)


plt.plot(t,z,'r')
plt.plot(t,0.5*v*v,'b')
plt.plot(t,200*np.cos(w*t),'g')
plt.axhline(y=3.17*Up,color='b',linestyle='-')
plt.show()