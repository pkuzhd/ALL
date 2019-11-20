/* Q3.1 中缀表达式的值
** by TYY
** 2019.9.27
** last edit: 2019.10.10
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;


// 用于计算的函数
int calculate(char op, int num1, int num2)
{
	switch (op)
	{
		case '-': return num1 - num2;
		case '+': return num1 + num2;
		case '*': return num1 * num2;
		case '/': return num1 / num2;
		default: return 1;
	}
}


int main(int argc, char const *argv[])
{
	// 操作的优先级
	map<char, int> opPri; 
	opPri['('] = 0;
	opPri[')'] = 0;
	opPri['-'] = 1;
	opPri['+'] = 1;
	opPri['*'] = 2;
	opPri['/'] = 2;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		// 用于存储操作数与操作符的栈
		stack<int> nums;
		stack<char> ops;
		// 读取字符串并获取其长度
		string expression;
		cin >> expression;
		int len = expression.length(); 
		for (int j = 0; j < len; ++j) {
			// 如果是数字则存入栈
			if (expression[j] >= '0' && expression[j] <= '9') {
				string curNum;
				curNum += expression[j];
				while(j < len && expression[j+1] >= '0' && expression[j+1] <= '9') 
				{
					j++;
					curNum += expression[j];
				}
				nums.push(atoi(curNum.c_str()));
			} else {
				// 左括号直接入栈
				if (expression[j] == '(')
					ops.push('(');
					// 右括号计算括号内的值
				else if (expression[j] == ')') {
					while ('(' != ops.top()) {
						char curOp = ops.top();
						ops.pop();
						int num2 = nums.top();
						nums.pop();
						int num1 = nums.top();
						nums.pop();
						nums.push(calculate(curOp, num1, num2));
					}
					ops.pop();
					}
				// 运算符
				// 运算符栈不为空
				else if (!ops.empty()) {
				char preOp = ops.top();
					// 如果前一个运算符的优先级大于等于当前运算符 则计算前一个运算符
					if (opPri[preOp] >= opPri[expression[j]]) {
						ops.pop();
						int num2 = nums.top();
						nums.pop();
						int num1 = nums.top();
						nums.pop();
						nums.push(calculate(preOp, num1, num2));
						ops.push(expression[j]);
					}
					// 前一个运算符优先级更小则直接入栈
					else
						ops.push(expression[j]);
				}
				else
					ops.push(expression[j]);
			}
		}

		// 处理最后栈中剩余的元素
		while (nums.size() > 1) {
			char curOp = ops.top();
			ops.pop();
			int num2 = nums.top();
			nums.pop();
			int num1 = nums.top();
			nums.pop();
			nums.push(calculate(curOp, num1, num2));
		}
		int final = nums.top();
		std::cout << final << endl;
	}
	return 0;
}
