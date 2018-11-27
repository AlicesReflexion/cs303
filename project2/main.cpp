#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Binary_Tree.h"

std::string decode_morse(std::string morse, const Binary_Tree<char>& morse_tree) {
return "wut";
}

std::string encode_morse(std::string text, const Binary_Tree<char>& morse_tree) {
return "wut";
}

bool sort_by_length(const std::string &i, const std::string &j) {
  return j.length() > i.length();
}

Binary_Tree<char> create_morse_tree(std::string filename) {
  Binary_Tree<char> morse_tree;
  std::ifstream file;

  file.open(filename);
  std::vector<std::string> lines;
  if (file.is_open()) {
    std::string line;
    while(getline(file,line)){
      lines.push_back(line);
    }
  }
  file.close();
  //std::sort doesn't include sorting the element for some reason.
  //This is a quick hack around that.
  std::sort(lines.begin(), lines.end(), sort_by_length);
  std::sort(lines.begin(), lines.end(), sort_by_length);

  BTNode<char> root ('^');
  BTNode<char>* rootPointer = &root;
  BTNode<char>* current = &root;
  for (unsigned int i = 0; i < lines.size(); i++) {
    std::cout << lines[i] << std::endl;
    if (lines[i].size() <= 3) {
      if (lines[i][1] == '.')
        current->left = new BTNode<char>(lines[i][0]);
      else
        current->right = new BTNode<char>(lines[i][0]);
    }
    else {
      for (unsigned int k = 1; k < lines[i].length() - 2; k++) {
        if(lines[i][k] == '.')
          current = (current->left);
        if(lines[i][k] == '_')
          current = (current->right);
      }
      if (lines[i][lines[i].size() - 2] == '.') {
        current->left = new BTNode<char>(lines[i][0]);
      }
      else {
        current->right = new BTNode<char>(lines[i][0]);
      }
    }
    current = rootPointer;
  }
  morse_tree.setRoot(rootPointer);
  return morse_tree;
}

int main() {
  Binary_Tree<char> morse_tree = create_morse_tree("morse.txt");
  std::string encoded = encode_morse("this is a test", morse_tree);
  std::string decoded = decode_morse(encoded, morse_tree);
  std::cout << encoded << " " << decoded << std::endl;
  return 0;
}
