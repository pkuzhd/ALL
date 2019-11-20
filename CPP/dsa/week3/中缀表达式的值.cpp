//****************************
//*例程：中缀表达式的值     **
//*作者：pkuzhd             **
//*时间：2017.10.13         **
//****************************

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int calc(char op, int num1, int num2)
{
	switch (op)
	{
		case '+':return num1+num2;
		case '-':return num1-num2;
		case '*':return num1*num2;
		case '/':return num1/num2;
	}
}

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	for (int kk = 0; kk < n; ++kk)
	{
		stack<char> stackOp;
		stack<int> stackNum;
		char strExp[700];
		cin >> strExp;
		int len = strlen(strExp);
		for (int i = 0; i < len; ++i)
		{
			// 如果是操作数
			if (strExp[i]<='9' && strExp[i]>='0')
			{
				int j = i+1;
				int tempNum = strExp[i]-'0';
				// 如果是最后一个字符
				while (j != len && strExp[j]<='9' && strExp[j]>='0')
				{
					tempNum = tempNum*10+strExp[j]-'0';
					++j;
					++i;
				}
				stackNum.push(tempNum);
			}
			else // 如果是操作符
			{
				switch (strExp[i])
				{
				case '-':
					if (i==0 || strExp[i-1]=='(')
					{
						stackNum.push(0);
					}
				case '+':
					while (!stackOp.empty() && stackOp.top()!='(')
					{
						char tempOp = stackOp.top();
						stackOp.pop();
						int num2 = stackNum.top();
						stackNum.pop();
						int num1 = stackNum.top();
						stackNum.pop();
						stackNum.push(calc(tempOp, num1, num2));
					}
					stackOp.push(strExp[i]);
					break;
				case '*':
				case '/':
					while (!stackOp.empty() && stackOp.top()!='(' && stackOp.top()!='+' && stackOp.top()!='-')
					{
						char tempOp = stackOp.top();
						stackOp.pop();
						int num2 = stackNum.top();
						stackNum.pop();
						int num1 = stackNum.top();
						stackNum.pop();
						stackNum.push(calc(tempOp, num1, num2));
					}
					stackOp.push(strExp[i]);
					break;
				case '(':
					stackOp.push(strExp[i]);
					break;
				case ')':
					while (stackOp.top()!='(')
					{
						char tempOp = stackOp.top();
						stackOp.pop();
						int num2 = stackNum.top();
						stackNum.pop();
						int num1 = stackNum.top();
						stackNum.pop();
						stackNum.push(calc(tempOp, num1, num2));
					}
					stackOp.pop();
					break;
				}
			}
		}
		while (!stackOp.empty())
		{
			char tempOp = stackOp.top();
			stackOp.pop();
			int num2 = stackNum.top();
			stackNum.pop();
			int num1 = stackNum.top();
			stackNum.pop();
			stackNum.push(calc(tempOp, num1, num2));
		}
		cout << stackNum.top() << endl;
	}
	return 0;
}

