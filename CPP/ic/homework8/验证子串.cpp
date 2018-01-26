// 验证子串
// pkuzhd
// 2017.11.11

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	char str1[101];
	char str2[101];
	cin >> str1 >> str2;
	if (strlen(str1) > strlen(str2))
	{
		char temp[101];
		strcpy(temp, str2);
		strcpy(str2, str1);
		strcpy(str1, temp);
	}
	for (int i = 0; str2[i]!='\0'; ++i)
	{
		bool flag = true;
		for (int j = 0; str1[j]!='\0'; ++j)
		{
			if (str1[j] != str2[i+j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << str1 << " is substring of " << str2 << endl;
			return 0;
		}
	}
	cout << "No substring" << endl;
	return 0;
}