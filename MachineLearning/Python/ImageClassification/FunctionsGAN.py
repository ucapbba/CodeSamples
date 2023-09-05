import FunctionsGenerator as genFun
import FunctionsDiscriminator as disFun
import Functions as fun
from numpy import vstack
from keras.models import Sequential
from numpy import ones
from tensorflow.keras.optimizers import Adam

# define the combined generator and discriminator model, for updating the generator
def define_gan(g_model, d_model):
 # make weights in the discriminator not trainable
 d_model.trainable = False
 # connect them
 model = Sequential()
 # add generator
 model.add(g_model)
 # add the discriminator
 model.add(d_model)
 # compile model
 opt = Adam(lr=0.0002, beta_1=0.5)
 model.compile(loss='binary_crossentropy', optimizer=opt)
 return model

# train the composite model
def train_gan(gan_model, latent_dim, n_epochs=100, n_batch=256):
 # manually enumerate epochs
 for i in range(n_epochs):
      #prepare points in latent space as input for the generator
      x_gan = genFun.generate_latent_points(latent_dim, n_batch)
      # create inverted labels for the fake samples
      y_gan = ones((n_batch, 1))
      # update the generator via the discriminator's error
      gan_model.train_on_batch(x_gan, y_gan)
      
# train the generator and discriminator
def train(g_model, d_model, gan_model, dataset, latent_dim, n_epochs=100, n_batch=256):
 bat_per_epo = int(dataset.shape[0] / n_batch)
 half_batch = int(n_batch / 2)
 # manually enumerate epochs
 for i in range(n_epochs):
  # enumerate batches over the training set
  for j in range(bat_per_epo):
      # get randomly selected 'real' samples
      X_real, y_real = disFun.generate_real_samples(dataset, half_batch)
      # generate 'fake' examples
      X_fake, y_fake = genFun.generate_fake_samples(g_model, latent_dim, half_batch)
      # create training set for the discriminator
      X, y = vstack((X_real, X_fake)), vstack((y_real, y_fake))
      # update discriminator model weights
      d_loss, _ = d_model.train_on_batch(X, y)
      # prepare points in latent space as input for the generator
      X_gan = genFun.generate_latent_points(latent_dim, n_batch)
      # create inverted labels for the fake samples
      y_gan = ones((n_batch, 1))
      # update the generator via the discriminator's error
      g_loss = gan_model.train_on_batch(X_gan, y_gan)
      # summarize loss on this batch
      print('>%d, %d/%d, d=%.3f, g=%.3f' % (i+1, j+1, bat_per_epo, d_loss, g_loss))
      # evaluate the model performance, sometimes
      if (i+1) % 10 == 0:
          fun.summarize_performance(i, g_model, d_model, dataset, latent_dim)