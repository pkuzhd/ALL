// 集合运算
// pkuzhd
// 2017.12.12
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n;
	int *numA = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", numA + i);
		//cin >> numA[i];
	}
	cin >> m;
	int *numB = new int[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", numB + i);
		//cin >> numB[i];
	}


	int i = 0, j = 0;
	//while (i < n && j < m)
	//{
	//	if (numA[i] == numB[j])
	//	{
	//		++i, ++j;
	//	}
	//	else if (numA[i] < numB[j])
	//	{
	//		cout << numA[i];
	//		++i;
	//		break;
	//	}
	//	else
	//	{
	//		cout << numB[j];
	//		++j;
	//		break;
	//	}
	//}
	while (i < n && j < m)
	{
		if (numA[i] == numB[j])
		{
			++i, ++j;
		}
		else if (numA[i] < numB[j])
		{
			cout << numA[i] << " " ;
			++i;
		}
		else
		{
			cout << numB[j] << " " ;
			++j;
		}
	}
	if (i < n)
	{
		while (i < n)
		{
			cout << numA[i] << " ";
			++i;
		}
	}
	else
	{
		cout << numB[j] << " " ;
		++j;
	}

	cout << endl;

	delete[] numA;
	delete[] numB;
	return 0;
}