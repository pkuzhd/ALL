#include <iostream>

using namespace std;

int len(char *);


int main(int argc, char const *argv[])
{
	int n = 0;
	char strWord[100];
	cin >> n;
	gets(strWord);	
	for (int i = 0; i < n; ++i)
	{
		gets(strWord);
		for (int i = 0; i < len(strWord); ++i)
		{
			if ((strWord[i]<'z'&&strWord[i]>='a')||(strWord[i]<'Z'&&strWord[i]>='A'))
			{
				cout << char(strWord[i]+1);
			}
			else if (strWord[i]=='z'||strWord[i]=='Z')
			{
				cout << char(strWord[i]-'z'+'a');
			}
			else
				cout << char(strWord[i]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

int len(char *str)
{
	for (int i = 0; ; ++i)
	{
		if (str[i]=='\0')
		{
			return i;
		}
	}
}