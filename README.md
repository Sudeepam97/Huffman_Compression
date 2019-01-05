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

This is a reason why Huffman's algorithm is not good to losslessly compress files that are already very small (say a few bytes) in size.
