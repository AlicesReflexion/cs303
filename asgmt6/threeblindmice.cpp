// HuffTrees.cpp : Defines the entry point for the console application.
//

#include "Huffman_Tree.h"
#include <iostream>
#include <string>

int main()
{
	Huff_Data<std::string> three(3, "three");
  Huff_Data<std::string> blind(3, "blind");
  Huff_Data<std::string> mice(3, "mice");
  Huff_Data<std::string> see(3, "see");
  Huff_Data<std::string> how(2, "how");
  Huff_Data<std::string> they(3, "they");
  Huff_Data<std::string> run(2, "run");
  Huff_Data<std::string> all(1, "all");
  Huff_Data<std::string> ran(1, "ran");
  Huff_Data<std::string> after(1, "after");
  Huff_Data<std::string> the(1, "the");
  Huff_Data<std::string> farmers(1, "farmer's");
  Huff_Data<std::string> wife(1, "wife");
  Huff_Data<std::string> who(1, "who");
  Huff_Data<std::string> cut(1, "cut");
  Huff_Data<std::string> off(1, "off");
  Huff_Data<std::string> their(1, "their");
  Huff_Data<std::string> tails(1, "tails");
  Huff_Data<std::string> with(1, "with");
  Huff_Data<std::string> a(2, "a");
  Huff_Data<std::string> carving(1, "carving");
  Huff_Data<std::string> knife(1, "knife");
  Huff_Data<std::string> did(1, "did");
  Huff_Data<std::string> you(1, "you");
  Huff_Data<std::string> ever(1, "ever");
  Huff_Data<std::string> such(1, "such");
  Huff_Data<std::string> sight(1, "sight");
  Huff_Data<std::string> in(1, "in");
  Huff_Data<std::string> your(1, "your");
  Huff_Data<std::string> life(1, "life");
  Huff_Data<std::string> as(1, "as");
	
	
	std::ostringstream code;
	std::vector<Huff_Data<std::string>> huff_Data {three,blind,mice,see,how,they,run,all,ran,after,the,farmers,wife,who,cut,off,their,tails,with,a,carving,knife,did,you,ever,such,sight,in,your,life,as};
	Huffman_Tree<std::string> huff_tree;
	huff_tree.build_tree(huff_Data);
	huff_tree.print_code(code);
	std::string result = code.str();
	

	result = huff_tree.decode("101111001000101111001000101011011100101001010110111001010010011101001110010011011110100000000010111100111011111111101011101101011001000111000100001101100111100101001101001001010011111111110111000110101101111001000");
std::cout << result;
	return 0;
}

