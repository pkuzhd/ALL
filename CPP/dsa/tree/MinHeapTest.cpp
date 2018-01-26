#include <iostream>
#include <vector>
#include "MinHeap.h"

using std::cout;
using std::endl;

template <class T>
class MinHeap;

int main(int argc, char const *argv[])
{
	MinHeap<int> heap;
	int num[9] = {1, 23, 5, 634, 34, 123, 35, 76788, 2323};
	for (int i = 0; i < 9; ++i)
	{
		heap.Insert(num[i]);
	}
	while (!heap.isEmpty()) {
		cout << heap.RemoveMin() << endl;
	}
	return 0;
}
