//****************************
//*例程：出栈序列统计       **
//*作者：pkuzhd             **
//*时间：2017.10.12         **
//****************************

// 通过模拟出栈计算

#include <iostream>
#include <stack>

using namespace std;

int calcSum(stack<int>, stack<int>);

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	stack<int> qNum;
	stack<int> sNum;
	for (int i = n; i > 0; --i)
		qNum.push(i);
	cout << calcSum(qNum, sNum);
	return 0;
}

int calcSum(stack<int> qNum, stack<int> sNum)
{
	int sum=0;
	if (!qNum.empty() || !sNum.empty())
	{
		if (!qNum.empty())
		{
			// 进栈
			sNum.push(qNum.top());
			qNum.pop();
			sum += calcSum(qNum, sNum);
			qNum.push(sNum.top());
			sNum.pop();

			if (!sNum.empty())
			{
				// 出栈
				int temp = sNum.top();
				sNum.pop();
				sum += calcSum(qNum, sNum);
				sNum.push(temp);
			}
		}
		else
		{
			while (!sNum.empty())
				sNum.pop();
			return 1;
		}
		return sum;
	}
}
