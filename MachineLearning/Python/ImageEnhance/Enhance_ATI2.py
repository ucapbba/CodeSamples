# -*- coding: utf-8 -*-
"""
Created on Sun Apr 10 12:00:07 2022

@author: baugstein
"""
# -*- coding: utf-8 -*-

import cv2 
import numpy as np
import matplotlib.pyplot as plt
from skimage import io #scikit-image

img = cv2.imread("Image/ATIcropped.jpg")  
#img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
plt.figure(figsize=(12,8))
plt.imshow(img);

'''
NOTE: it is important to check the values of intensities before going on the analysis. 
Here, for instance, intensities are normalized, i.e. they range from 0 to 1 rather than 0 to 255,
so we need to convert it back to the latter so openCV works properly. That's why I multiply 
the entire image by 255 and convert it to np.uint8 (a format supported by OpenCV).
'''
# transform it to a numpy array 
#img_arr = (np.round(np.array(img)*255)).astype(np.uint8)
img_arr = (np.round(np.array(img))).astype(np.uint8)
# flatten
img_arr = img_arr.flatten()

# plot histogram
plt.figure(0)
plt.hist(img_arr, bins = 256, range = [0,256])
plt.title("Number of pixels in each intensity value")
plt.xlabel("Intensity")
plt.ylabel("Number of pixels")
plt.show()

#img_eq = cv.equalizeHist((img).astype(np.uint8))
#plt.figure(figsize=(12,8))
#plt.imshow(img_eq);

clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
clahe_img = clahe.apply((img*255).astype(np.uint8))
plt.figure(figsize=(10,7))
plt.imshow(clahe_img, cmap="gray");