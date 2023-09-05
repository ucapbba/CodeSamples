# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 15:34:14 2023

@author: baugstein
"""
from sklearn import metrics
import FunctionsGenerator as genFun
import FunctionsDiscriminator as disFun
from matplotlib import pyplot

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

# create and save a plot of generated images (reversed grayscale)
def save_plot(examples, epoch, n=10):
 # plot images
 for i in range(n * n):
     # define subplot
     pyplot.subplot(n, n, 1 + i)
     # turn off axis
     pyplot.axis('off')
     # plot raw pixel data
     pyplot.imshow(examples[i, :, :, 0], cmap='gray_r')
     # save plot to file
     filename = 'generated_plot_e%03d.png' % (epoch+1)
     pyplot.savefig(filename)
     pyplot.close()
 
# evaluate the discriminator, plot generated images, save generator model
def summarize_performance(epoch, g_model, d_model, dataset, latent_dim, n_samples=100):
 # prepare real samples
 X_real, y_real = disFun.generate_real_samples(dataset, n_samples)
 # evaluate discriminator on real examples
 _, acc_real = d_model.evaluate(X_real, y_real, verbose=0)
 # prepare fake examples
 x_fake, y_fake = genFun.generate_fake_samples(g_model, latent_dim, n_samples)
 # evaluate discriminator on fake examples
 _, acc_fake = d_model.evaluate(x_fake, y_fake, verbose=0)
 # summarize discriminator performance
 print('>Accuracy real: %.0f%%, fake: %.0f%%' % (acc_real*100, acc_fake*100))
 # save plot
 save_plot(x_fake, epoch)
 # save the generator model tile file
 filename = 'generator_model_%03d.h5' % (epoch + 1)
 g_model.save(filename)
