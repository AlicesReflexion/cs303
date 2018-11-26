#include <iostream>
#include <fstream>
#include <string>
#include "Binary_Tree.h"

std::string decode_morse(std::string morse, const Binary_Tree<char>& morse_tree) {
return "wut";
}

std::string encode_morse(std::string text, const Binary_Tree<char>& morse_tree) {
return "wut";
}

Binary_Tree<char> create_morse_tree(std::string filename) {
  Binary_Tree<char> morse_tree;
  std::ifstream file;

  file.open(filename);
  file.close();
  return morse_tree;
}

int main() {
  Binary_Tree<char> morse_tree = create_morse_tree("morse.txt");
  std::string encoded = encode_morse("this is a test", morse_tree);
  std::string decoded = decode_morse(encoded, morse_tree);
  std::cout << encoded << " " << decoded << std::endl;
  return 0;
}
