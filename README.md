# Huffman_Compression
This project uses the Huffman's algorithm to compress text files and images. Here’s what you should do to see it work:

Make sure you have the following dependencies installed:
- g++ (v4:7.3.0-3ubuntu2)
- python3 (3.6.7)
- NumPy (v1.15.4)
- SciPy (v1.1.0)

Also, either changge the input path in the code, or make sure that the path of your sample text files is `Compression/data_to_compress/text_file.txt` and the path of your sample images is `Compression/data_to_compress/image.tiff`

To compress a file, fire up your terminal at the top directory of this project, and type:
```sh
cd Compression
chmod +x compress.sh
./compress.sh
```
Now, look inside a newly created directory called **output** to see the results.
- **compressed_data.txt**: This file containd the actual compressed data. 
- **code_map.txt**: Contains each unique value present in the original data file and it's corosponding Huffman Code.
- **key.txt**: Extra information required to decompress data. See `compress_data.cpp` for details.

**NOTE:** Due to the headers involved, Huffman's algorithm is not good for compressing files that are already very few bytes in size.

Then you must physically move the contents *(ctrl+c --> ctrl+v)* of this directory to the `/Decompression` directory. The physical movement is just my way of representing the movement of compressed data (say from one machine to another). 

Now, for decompression `cd` to `/Decompression`, and type:
```sh
g++ decompress_data.cpp -o decompress.o
./decompress.o
```
This, generates the original text file for a compressed text file, and a text file containing the raw pixel values for an image.

Note that the size of an image is dependent on what format it is saved in. The only true size of an image is equal to **(number of pixels in the image * colour depth)**. This is what the size of an uncompressed bitmap or an uncompressed TIFF is.

However, modern image viewing softwares can interpret all types of image formats such as JPEGs and PNGs. Essentially, these formats denote a form of compression that has been applied on the original uncompressed image and most of these compression techniques are much better than Huffman's algorithm.

Therefore, although with a text file, you can actually see the difference in size by comparing the original file and the output files. With images, you have to either arrange an uncompressed TIFF or, compare the actual size **(number of pixels in the image * colour depth)** of a JPEG or a PNG or any other such format with the output.
