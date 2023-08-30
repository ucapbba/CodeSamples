# -*- coding: utf-8 -*-
"""
Created on Tue Aug  8 09:45:29 2023

@author: baugstein
"""
from keras.datasets import mnist
from sklearn import metrics
import Functions as fun
import matplotlib.pyplot as plt
from sklearn.linear_model import SGDClassifier

print("Load the MNIST dataset")
(train_x, y_train), (test_x, y_test) = mnist.load_data() #much quicker than fetch_openml('mnist_784',version=1)
print("done")

x_train = train_x.reshape((train_x.shape[0], -1)) #creates 2d array -1 is a automatic reshape flag
x_test = test_x.reshape((test_x.shape[0], -1))

print(x_train.shape)
print(y_train.shape)

some_digit = train_x[0]
some_digit_image = some_digit.reshape(28,28)
plt.imshow(some_digit_image,cmap = "binary")
print(y_train[0])

y_train_5 = (y_train == 5)
y_test_5 = (y_test == 5)

sgd_clf = SGDClassifier(random_state=42,n_jobs=12) #uses 12 cores 
print("fitting data")
sgd_clf.fit(x_train,y_train)

y_prediction = sgd_clf.predict(x_test)
print("Actual Values")
for ele in y_test:
    print(ele)
print("Predicted Values")
for ele in y_prediction:
    print(ele)

print("analysising stats")
precision, accuracy, sensitivity, specificity = fun.stat_data(y_test,y_prediction)

