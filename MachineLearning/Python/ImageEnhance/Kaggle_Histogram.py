# -*- coding: utf-8 -*-
"""
https://www.kaggle.com/code/hrmello/intro-to-image-processing-image-enhancement-pt-1
"""
import cv2
import numpy as np
import matplotlib.pyplot as plt
from skimage import io #scikit-image

# read the image from a link
# opencv doesn't directly read images from an url, so we will use
# skimage module to read it first
img = io.imread("http://www.dphclub.com/tutorials/images/war-time-1.jpg", as_gray=True)
plt.figure(figsize=(12,8))
plt.imshow(img, cmap="gray");

'''
NOTE: it is important to check the values of intensities before going on the analysis. 
Here, for instance, intensities are normalized, i.e. they range from 0 to 1 rather than 0 to 255,
so we need to convert it back to the latter so openCV works properly. That's why I multiply 
the entire image by 255 and convert it to np.uint8 (a format supported by OpenCV).
'''
# transform it to a numpy array 
img_arr = (np.round(np.array(img)*255)).astype(np.uint8)

# flatten
img_arr = img_arr.flatten()

# plot histogram
plt.figure(0)
plt.hist(img_arr, bins = 256, range = [0,256])
plt.title("Number of pixels in each intensity value")
plt.xlabel("Intensity")
plt.ylabel("Number of pixels")
plt.show()

img_eq = cv2.equalizeHist((img*255).astype(np.uint8))
plt.figure(figsize=(12,8))
plt.imshow(img_eq, cmap = "gray");