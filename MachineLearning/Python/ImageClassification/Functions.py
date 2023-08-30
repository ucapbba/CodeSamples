# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 15:34:14 2023

@author: baugstein
"""
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
