#include <iostream>
#include <vector>
#include "HuffmanTree.h"

using std::cout;
using std::endl;

template <class T>
class HuffmanTree;

int main(int argc, char const *argv[])
{
	MinHeap<int> heap;
	int num[9] = {1, 23, 5, 634, 34, 123, 35, 76788, 2323};
	HuffmanTree<int> ht(num, 9);
	return 0;
}
