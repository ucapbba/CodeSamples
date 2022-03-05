# -*- coding: utf-8 -*-

"""
Created on Mon Aug 16 17:23:00 2021

@author: baugstein
"""
import matplotlib.pyplot as plt
import numpy as np


# Create the vectors X and Y
x = np.array(range(100))
a=1
y = a*(1-x)

# Create the plot
plt.plot(x,y)

# Show the plot
plt.show()


from numpy import arange
from pylab import meshgrid,cm,imshow,contour,clabel,colorbar,title,show

def z_func1(x,y):
    return 1-x

# the function that I'm going to plot
def z_func2(x,y):
    return 10*(y-x*x)
 
x = arange(-3.0,3.0,0.1)
y = arange(-3.0,3.0,0.1)
X,Y = meshgrid(x, y) # grid of point
Z = z_func2(X, Y) # evaluation of the function on the grid

im = imshow(Z,cmap=cm.RdBu) # drawing the function
# adding the Contour lines with labels
cset = contour(Z,arange(-1,1.5,0.2),linewidths=2,cmap=cm.Set2)
clabel(cset,inline=True,fmt='%1.1f',fontsize=10)
colorbar(im) # adding the colobar on the right
# latex fashion title
title('$z=10(y-x^2)$')
show()


from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, Z, rstride=1, cstride=1, 
                      cmap=cm.RdBu,linewidth=0, antialiased=False)

ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()