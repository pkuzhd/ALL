#include <iostream>

using namespace std;

int kk = 0;

int findNum(int num[], int length, int idx)
{
	

	int *left = &num[1];
	int *right = &num[length - 1];
	while (left < right)
	{
		while (left < right && *left <= num[0])
		{
			++left;
		}
		while (left < right && *right >= num[0])
		{
			--right;
		}
		if (left < right)
		{
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}
	if (*left < num[0])
	{
		int temp = *left;
		*left = num[0];
		num[0] = temp;
	}
	else
	{
		--left;
		int temp = *left;
		*left = num[0];
		num[0] = temp;
	}



	if (left - num == idx)
		return num[idx];
	else if (left - num < idx)
		return findNum(left + 1, length - (left - num + 1), idx - (left - num + 1));
	else
		return findNum(num, left - num, idx);
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int  i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	int mid;
	if (n > 1)
		mid = findNum(num, n, n / 2);
	else
		mid = num[0]; 
	cout << mid << endl;
	delete [] num;
	return 0;
}