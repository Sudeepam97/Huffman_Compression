mkdir -p output
g++ -c read_text_file.cpp
g++ -c read_image.cpp
g++ -c get_codes.cpp
g++ -c create_huffman_tree.cpp
g++ -c compress_data.cpp
g++ main.cpp -o main.o read_text_file.o read_image.o create_huffman_tree.o get_codes.o compress_data.o

read -p "Press '1' to compress text and '2' to compress an image: " -n1 choice
printf "\n\n"

if [ "$choice" = "2" ]
then
  python3 read_image.py
fi

./main.o $choice
