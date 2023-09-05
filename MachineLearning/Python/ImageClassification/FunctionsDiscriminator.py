# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 15:34:14 2023

@author: baugstein
"""
#from sklearn import metrics
from keras.datasets import mnist
import numpy as np
import random as ran
# example of defining the discriminator model
from keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from keras.layers import Dense
from keras.layers import Conv2D
from keras.layers import Flatten
from keras.layers import Dropout
from keras.layers import LeakyReLU

# define the standalone discriminator model

def define_discriminator(in_shape=(28,28,1)):
    model = Sequential()
    model.add(Conv2D(64, (3,3), strides=(2, 2), padding='same', input_shape=in_shape))
    model.add(LeakyReLU(alpha=0.2))
    model.add(Dropout(0.4))
    model.add(Conv2D(64, (3,3), strides=(2, 2), padding='same'))
    model.add(LeakyReLU(alpha=0.2))
    model.add(Dropout(0.4))
    model.add(Flatten())
    model.add(Dense(1, activation='sigmoid'))
    # compile model
    opt = Adam(lr=0.0002, beta_1=0.5)
    model.compile(loss='binary_crossentropy', optimizer=opt, metrics=['accuracy'])
    return model

def load_real_samples():
 # load mnist dataset
 (trainX, _), (_, _) = mnist.load_data()
 # expand to 3d, e.g. add channels dimension
 X = np.expand_dims(trainX, axis=-1)
 # convert from unsigned ints to floats
 X = X.astype('float32')
 # scale from [0,255] to [0,1]
 X = X / 255.0
 return X

# select real samples
def generate_real_samples(dataset, n_samples):
 # choose random instances
 ix =[]
 for x in range(n_samples):
     x = ran.randint(0, dataset.shape[0])#, n_samples)
     ix.append((x))
 # retrieve selected images
 X = dataset[ix]
 # generate 'real' class labels (1)
 y = np.ones((n_samples, 1))
 return X, y

# generate n fake samples with class labels
def generate_fake_samples(n_samples):
 # generate uniform random numbers in [0,1]
 X=[]
 for x in range(28 * 28 * n_samples):
     x = ran.randint(0,28 * 28 * n_samples)
     x=x/(28 * 28 * n_samples)
     X.append((x))
 X = np.array(X)
 # reshape into a batch of grayscale images
 X = X.reshape((n_samples, 28, 28, 1))
 # generate 'fake' class labels (0)
 y = np.zeros((n_samples, 1))
 return X, y

from numpy.random import randn
# generate points in latent space as input for the generator
def generate_latent_points(latent_dim, n_samples):
 # generate points in the latent space
 x_input = randn(latent_dim * n_samples)
 # reshape into a batch of inputs for the network
 x_input = x_input.reshape(n_samples, latent_dim)
 return x_input


# train the discriminator model
def train_discriminator(model, dataset, n_iter=100, n_batch=256):
 half_batch = int(n_batch / 2)
 # manually enumerate epochs
 for i in range(n_iter):
     # get randomly selected 'real' samples
     X_real, y_real = generate_real_samples(dataset, half_batch)
     # update discriminator on real samples
     _, real_acc = model.train_on_batch(X_real, y_real)
     # generate 'fake' examples
     X_fake, y_fake = generate_fake_samples(half_batch)
     # update discriminator on fake samples
     _, fake_acc = model.train_on_batch(X_fake, y_fake)
     # summarize performance
     print('>%d real=%.0f%% fake=%.0f%%' % (i+1, real_acc*100, fake_acc*100))
 
