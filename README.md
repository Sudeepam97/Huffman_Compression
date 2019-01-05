# Huffman_Compression
This project uses the Huffman's algorithm to compress text files and images. Here’s what you can do to see it work:

Make sure you have the following dependencies installed (within brackets are the specific versions that I had installed):
- g++ (v4:7.3.0-3ubuntu2)
- python3 (3.6.7)
- NumPy (v1.15.4)
- SciPy (v1.1.0)

Now, to compress a file, fire up your terminal at the top directory of this project, and type:
```
>> cd Compression
>> chmod +x compress.sh
>> ./compress.sh
```
You can now look inside a newly created directory called **output** to see the results. We will *physically move the contents (ctrl+c --> ctrl+v) of this file* to the Decompression directory later on to obtain the orignal data back. This physical movement represents the movement of compressed data (from, say one computer to another). We'll discuss this in a moment, for now, here's what you will see:

- **compressed_data.txt**: You cannot really read the contents of this file, but this is the file which contains the actual data. 
- **code_map.txt**: Contains each unique value present in the original raw data file and it's corosponding Huffman Code.
- **key.txt**: This file contains some additional information that is needed with the code map to obtain the original data back.

Technically, **compressed_data.txt** is our compressed data file. However, it is important to note that all three of these files are essential to obtain the orignal data back, and therefore, if we are deploying this algorithm in the real world, we should compare the combined size of these three files to the original file and should not limit ourselves by comparing the size of compressed_data.txt and the original file only.

This is a reason why Huffman's algorithm is not good to compress files that are already very small (say a few bytes) in size.

Now, witnessing text compression first hand with this implementation is pretty straightforward, but image compression is slightly more complicated. One needs to understand that the size of an image is dependent on what format it is saved in. The only true size of an image is equal to **(number of pixels in the image * colour depth)**. This is what the size of an uncompressed bitmap or an uncompressed TIFF is.

However, modern image viewing softwares can interpret all types of image formats such as JPEGs and PNGs. Essentially, these formats denote a form of compression that has been applied on the original uncompressed image and most of these compression techniques, infact, **use the Huffman's algorithm as a starting point,** and therefore, are better than it.

Therefore, although with a text file, you can actually see the difference in size by comparing the original file and the output file that this code has produced, but with images, due to the above reason, you have to either arrange an uncompressed TIFF (like the one that I have used here) or, compare the actual size **(number of pixels in the image * colour depth)** of a JPEG or a PNG or any other such format with the output.

That being said, to decompress the compressed data file that this program has produced, move the contents of the output directory to the directory called **Decompression** and *cd* to it, then type:
```
g++ decompress_data.cpp -o decompress.o
./decompress.o
```
This, generates the original text file for a compressed text file, and a text file containing the raw pixel values for an image.
