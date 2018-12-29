mkdir compressed
g++ -c read_text_file.cpp
g++ -c create_list.cpp
g++ -c extract_min.cpp
g++ -c create_parent.cpp
g++ -c insert_new.cpp
g++ -c create_huffman_tree.cpp
g++ -c traverse_tree.cpp
g++ -c compress_data.cpp
g++ main.cpp -o main.o read_text_file.o create_list.o extract_min.o \
create_parent.o insert_new.o create_huffman_tree.o traverse_tree.o \
compress_data.o
