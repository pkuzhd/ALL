#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	int len = 0;
	int *number;
	char numbers[100];
	stack <int> numstack;
	cin >> numbers;
	for (int i = 0; ; ++i)
	{
		if (numbers[i]=='\0')
		{
			len = i;
			break;
		}
	}

	number = new int[len];
	for (int i = 0; i < len; ++i)
	{
		number[i] = numbers[i] - '0';
	}
	for (int i = 0; i < len;)
	{
		int k = 0;
		for (int j = i; j < len; ++j)
		{
			int temp = (number[j]+k*10)/2;
			k = k*10 + number[j] - temp*2;
			number[j] = temp;
		}
		numstack.push(k);
		if (number[i]==0)
		{
			++i;
		}
	}

	while(!numstack.empty())
	{
		cout << numstack.top();
		numstack.pop();
	}

	delete [] number;
	return 0;
}