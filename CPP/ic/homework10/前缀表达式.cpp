// 前缀表达式
// pkuzhd
// 2017.11.13

#include <iostream>
#include <cstdlib>

using namespace std;

double calc()
{
	char temp[20];
	cin >> temp;
	switch (temp[0])
	{
	case '+':
		return calc() + calc();
	case '-':
		return calc() - calc();
	case '*':
		return calc() + calc();
	case '/':
		return calc() / calc();
	default:
		return atof(temp);
	}
}

int main(int argc, const char *argv[])
{
	printf("%f\n", calc());
	return 0;
}
