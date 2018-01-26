// 数制转换
// pkuzhd
// 2017.11.11

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int from, to;
	char str[101];
	cin >> from >> str >> to;
	long long number = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = number*from + str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'z')
			number = number*from + str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'Z')
			number = number*from + str[i] - 'A' + 10;
	}
	char result[101];
	int i;
	if (number == 0)
	{
		cout << 0 <<endl;
		return 0;
	}
	for (i = 0; number != 0; ++i)
	{
		result[i] = num[number % to];
		number /= to;
	}
	result[i] = '\0';
	int end = i-1;
	for (int j = 0; j < end - j; ++j)
	{
		char t = result[j];
		result[j] = result[end-j];
		result[end-j] = t;
	}
	cout << result << endl;
	return 0;
}
