# -*- coding: utf-8 -*-
"""
Created on Tue Aug  8 09:45:29 2023

@author: baugstein
"""
from keras.datasets import mnist
from sklearn import metrics

def stat_data(y_test,test_preds): #NOTE TO SELF - these definitions are for the binary case
    cnf_matrix = metrics.confusion_matrix(y_test, test_preds)
    #Precision - proportion of positive identification that are actually correct
    precision = metrics.precision_score(y_test, test_preds,average='macro')
    print("Precision:", precision)
    print("INDICATORS")
    #Accuracy - number of correct predictions/total number of predictions
    accuracy = metrics.accuracy_score(y_test, test_preds)
    print("Accuracy:", accuracy)
    #Sensitivity - how well the model can detect positive instances
    sensitivity = metrics.recall_score(y_test, test_preds,average='macro')
    print("Sensitivity:", sensitivity)    
    #Specificity . proportion of true negatives that are correctly identified by the model
    specificity =  cnf_matrix[0][0]/(cnf_matrix[0][0]+ cnf_matrix[0][1])
    print("Specificity:", specificity)
    return precision, accuracy, sensitivity, specificity


print("Load the MNIST dataset")
(train_x, y_train), (test_x, y_test) = mnist.load_data() #much quicker than fetch_openml('mnist_784',version=1)
print("done")

x_train = train_x.reshape((train_x.shape[0], -1)) #creates 2d array -1 is a automatic reshape flag
x_test = test_x.reshape((test_x.shape[0], -1))

print(x_train.shape)
print(y_train.shape)


import matplotlib.pyplot as plt
some_digit = train_x[0]
some_digit_image = some_digit.reshape(28,28)
plt.imshow(some_digit_image,cmap = "binary")
print(y_train[0])

y_train_5 = (y_train == 5)
y_test_5 = (y_test == 5)


from sklearn.linear_model import SGDClassifier
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
precision, accuracy, sensitivity, specificity = stat_data(y_test,y_prediction)

