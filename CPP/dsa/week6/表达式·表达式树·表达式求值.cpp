#include <iostream>
#include <stack>
#include <cstdio>

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
    int data[26]={0};
	string str;
	cin >> str;
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
    {
        char c;
        int num;
        cin >> c >> num;
        data[c-'a'] = num;
    }
    int len = str.size();
    char *chr = new char[n];
    int *sum = new int[n];
    int *parent = new int[n];
    int *left = new int[n];
    int *right = new int[n];
    int treeSize = 0;
    int now=0;
    parent[now] = -1;
    left[now] = -1;
    right[now] = -1;
    for (int i = 0; i < len; ++i)
    {
        switch (str[i])
        {
        case '(':
            ++treeSize;
            left[now] = treeSize;
            parent[treeSize] = now;
            left[treeSize] = -1;
            right[treeSize] = -1;
            now = left[now];
            break;
        case ')':
            now = parent[now];
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            chr[now] = str[i];
            ++treeSize;
            right[now] = treeSize;
            parent[treeSize] = now;
            left[treeSize] = -1;
            right[treeSize] = -1;
            now = right[now];
            break;
        default:
            chr[now] = str[i];
            now = parent[now];
            break;


        }
    }

	return 0;
}
