#include <iostream>
#include <fstream>
#include <string>
#include "Binary_Tree.h"

std::string decode_morse(std::string morse) {
return "wut";
}

std::string encode_morse(std::string morse) {
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
  return 0;
}
