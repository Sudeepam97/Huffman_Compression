import numpy as np
from scipy.misc import imread, imresize

img = imread('data_to_compress/standard.tiff', mode = 'RGB')
f = open('../decompression/size.txt', 'w')
f.write(str(img.shape[0]) + '\t' + str(img.shape[1]))
f.close()
img = img.reshape(img.size)
np.savetxt('data_to_compress/image.txt', img, fmt = "%d")

