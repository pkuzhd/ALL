// Caesar 密码
// pkuzhd
// 2017.12.18
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char dict[26] = { 'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U' };
	string str;
	while (getline(cin, str))
	{
		if (str == "START" || str == "END")
			continue;
		if (str == "ENDOFINPUT")
			break;
		else
		{
			for (auto ch : str)
			{
				
				if (ch <= 'Z' && ch >= 'A')
					cout << dict[ch - 'A'];
				else
					cout << ch;
			}
			cout << endl;
		}
	}
	return 0;
}