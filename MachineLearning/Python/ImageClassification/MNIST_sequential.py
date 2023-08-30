import pandas as pd
import numpy as np
import Functions as fun

from sklearn.model_selection import train_test_split
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import classification_report

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import InputLayer, Dense, Dropout
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import CategoricalCrossentropy
from tensorflow.keras.metrics import CategoricalAccuracy, AUC
from tensorflow.keras.utils import to_categorical
from tensorflow.keras.callbacks import EarlyStopping, ReduceLROnPlateau
from keras.datasets import mnist
from sklearn import metrics


print("Load the MNIST dataset")
(train_x, y_train), (test_x, y_test) = mnist.load_data() #much quicker than fetch_openml('mnist_784',version=1)
print("done")

y_test_basic = y_test
x_train = train_x.reshape((train_x.shape[0], -1)) #creates 2d array -1 is a automatic reshape flag
x_test = test_x.reshape((test_x.shape[0], -1))

y_train = to_categorical(y_train) #note for a range 1 - 10 this will create 10 new columns and for "2" a "1" will be in third column
y_test = to_categorical(y_test)

print("creating model (squential)")
model = Sequential(name="MNIST_model")

model.add(InputLayer(input_shape=(x_train.shape[1],)))
model.add(Dense(128, activation='relu'))
model.add(Dropout(0.05))
model.add(Dense(128, activation='relu'))
model.add(Dropout(0.05))
model.add(Dense(64, activation='relu'))
model.add(Dense(10, activation='softmax'))

print("compiling")
model.compile(
    optimizer=Adam(),
    loss=CategoricalCrossentropy(),
    metrics=[CategoricalAccuracy(), AUC()]
)

earlyStopping = EarlyStopping(monitor='val_loss', patience=6)
reduceLROnPlateau = ReduceLROnPlateau(patience=5)

print("fitting")
model.fit(
    x_train,
    y_train,
    batch_size=4,
    epochs=10,
    validation_split=0.15,
    verbose=1,
    callbacks=[earlyStopping, reduceLROnPlateau]
)


print("done fitting")

y_prediction = model.predict(x_test)
y_prediction = np.argmax(y_prediction, axis=1)
print("analysising stats")
precision, accuracy, sensitivity, specificity = fun.stat_data(y_test_basic,y_prediction)

print("done")

