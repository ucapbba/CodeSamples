# example of loading the mnist dataset
from keras.datasets import mnist
from matplotlib import pyplot
import FunctionsDiscriminator as discFun
from keras.utils.vis_utils import plot_model

# load the images into memory
(trainX, trainy), (testX, testy) = mnist.load_data()
# summarize the shape of the dataset
print('Train', trainX.shape, trainy.shape)
print('Test', testX.shape, testy.shape)

# plot images from the training dataset
for i in range(25):
 # define subplot
 pyplot.subplot(5, 5, 1 + i)
 # turn off axis
 pyplot.axis('off')
 # plot raw pixel data
 pyplot.imshow(trainX[i], cmap='gray_r')
#uncomment to plot
#pyplot.show()

# define the discriminator model
model = discFun.define_discriminator()
# load image data
dataset = discFun.load_real_samples()
# fit the model
discFun.train_discriminator(model, dataset)

# size of the latent space
'''latent_dim = 100
# create the discriminator
d_model = fun.define_discriminator()
# create the generator
g_model = fun.define_generator(latent_dim)
# create the gan
gan_model = fun.define_gan(g_model, d_model)
# load image data
dataset = fun.load_real_samples()
# train model
fun.train(g_model, d_model, gan_model, dataset, latent_dim)'''