# -*- coding: utf-8 -*-
"""
Created on Sat Mar 12 06:41:57 2022

@author: baugstein
"""
import warnings
import numpy as np
import array


x = np.array([0.0, 1.0, 2.0, 3.0,  4.0,  5.0])
y = np.array([0.0, 0.8, 0.9, 0.1, -0.8, -1.0])
z = np.polyfit(x, y, 3)
print(z)
p = np.poly1d(z)

print(p(0.5))
print(p(3.5))
print(p(10))

p30 = np.poly1d(np.polyfit(x, y, 30))
import matplotlib.pyplot as plt
xp = np.linspace(-2, 5, 100)
_ = plt.plot(x, y, '.', xp, p(xp), '-', xp, p30(xp), '--')

plt.show()