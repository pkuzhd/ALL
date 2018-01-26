//****************************
//*例程：矩阵乘法           **
//*作者：pkuzhd             **
//*时间：2017.9.28          **

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	int **array = new int*[a];
	for (int i = 0; i < a; ++i)
		array[i] = new int[b];


	for (int i = 0; i < a; ++i)
		delete [] array[i];
	delete [] array;
	return 0;
}
