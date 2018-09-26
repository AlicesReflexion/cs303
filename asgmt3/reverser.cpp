#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

string reverse(string original) {
  stack<string> words;
  string word = "";
  string reversed_string = "";
  stringstream ss;
  ss.str(original);

  while(ss >> word)
    words.push(word);
  while(words.size() != 0){
    reversed_string = reversed_string + words.top() + " ";
    words.pop();
  }
  return reversed_string;
}

int main(int argc, char** argv) {
  string original = "";
  if(argc == 1){
    getline(cin, original);
    cout << reverse(original) << endl;
  }
  else {
    cout << reverse(argv[1]) << endl;
  }
  return 0;
}

