// 人工智能
// pkuzhd
// 2018.01.05
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	double d, g, y;
	int T, pd, py, pg, cas = 0;
	cin >> T;
	getchar();
	while (T--)
	{
		string str, s;
		getline(cin, str);
		py = str.find("U="); // 寻找U的位置
		pd = str.find("I="); // 寻找I的位置
		pg = str.find("P="); // 寻找P的位置
		if (py != string::npos&&pd != string::npos)
		{
			int j;
			for (int i = py + 2;; i++)
			{
				if (str[i] == 'V' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double m = atof(s.c_str());
			if (str[j] == 'm')
				m /= 1000;
			if (str[j] == 'M')
				m *= 1000000;
			if (str[j] == 'k')
				m *= 1000;
			s.clear();
			for (int i = pd + 2;; i++)
			{
				if (str[i] == 'A' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double mm = atof(s.c_str());
			if (str[j] == 'm')
				mm /= 1000;
			if (str[j] == 'M')
				mm *= 1000000;
			if (str[j] == 'k')
				mm *= 1000;
			printf("Problem #%d\nP=%.2lfW\n\n", ++cas, m*mm);
		}
		if (pg != string::npos&&pd != string::npos)
		{
			int j;
			for (int i = pg + 2;; i++)
			{
				if (str[i] == 'W' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double m = atof(s.c_str());
			if (str[j] == 'm')
				m /= 1000;
			if (str[j] == 'M')
				m *= 1000000;
			if (str[j] == 'k')
				m *= 1000;
			s.clear();
			for (int i = pd + 2;; i++)
			{
				if (str[i] == 'A' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double mm = atof(s.c_str());
			if (str[j] == 'm')
				mm /= 1000;
			if (str[j] == 'M')
				mm *= 1000000;
			if (str[j] == 'k')
				mm *= 1000;
			printf("Problem #%d\nU=%.2lfV\n\n", ++cas, m / mm);
		}
		if (pg != string::npos&&py != string::npos)
		{
			int j;
			for (int i = pg + 2;; i++)
			{
				if (str[i] == 'W' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double m = atof(s.c_str());
			if (str[j] == 'm')
				m /= 1000;
			if (str[j] == 'M')
				m *= 1000000;
			if (str[j] == 'k')
				m *= 1000;
			s.clear();
			for (int i = py + 2;; i++)
			{
				if (str[i] == 'V' || str[i] == 'm' || str[i] == 'k' || str[i] == 'M')
				{
					j = i;
					break;
				}
				else
					s += str[i];
			}
			double mm = atof(s.c_str());
			if (str[j] == 'm')
				mm /= 1000;
			if (str[j] == 'M')
				mm *= 1000000;
			if (str[j] == 'k')
				mm *= 1000;
			printf("Problem #%d\nI=%.2lfA\n\n", ++cas, m / mm);
		}
	}
	return 0;
}
