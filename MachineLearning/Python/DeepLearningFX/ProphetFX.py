# -*- coding: utf-8 -*-
"""
Created on Sat Mar 12 07:28:22 2022

@author: baugstein
"""
import gc
from tqdm import tqdm
import numpy as np
import pandas as pd
from pylab import rcParams
import matplotlib.pyplot as plt
from sklearn.metrics import mean_squared_error
from scipy.stats import probplot

import datetime as dt
from datetime import date
from datetime import timedelta
from fbprophet import Prophet

import os
import warnings
warnings.filterwarnings("ignore")

data0 = pd.read_csv("Foreign_Exchange_Rates.csv")
data0[-5:]