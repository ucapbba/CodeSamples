# -*- coding: utf-8 -*-
"""
Created on Sun Apr 10 12:13:27 2022

@author: baugstein
"""
from PIL import Image


im = Image.open("Image/ATI.jpg")
width, height = im.size
cut = 200
left = cut
top = cut
right = width--cut
bottom = height-cut
im1 = im.crop((left, top, right, bottom))
im1.show()