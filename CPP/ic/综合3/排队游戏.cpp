#include <iostream>
#include <string>
#include <stack>

using namespace std;



int main(int argc, char *argv[])
{
	string str;
	cin >> str;
	stack<int> s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(') // ����С�к�����ջ
		{
			s.push(i);
		}
		else // ����СŮ���ͳ�ջ
		{
			cout << s.top() << " " << i << endl;
			s.pop();
		}
	}
	return 0;
}