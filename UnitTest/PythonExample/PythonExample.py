# -*- coding: utf-8 -*-
"""
Created on Thu Jun 27 09:56:29 2024

@author: baugstein
"""

import matplotlib.pyplot as plt

# Data to display on the plot
x = [1, 2, 3]
y = [2, 4, 1]

# Create the plot
plt.plot(x, y)
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('My first graph!')

# Display the plot
plt.show()