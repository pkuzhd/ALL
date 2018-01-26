//****************************
//*例程：陶陶摘苹果         **
//*作者：pkuzhd             **
//*时间：2017.10.15         **
//****************************

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int szHeight[10]={0};// 记录苹果的高度
	for (int i = 0; i < 10; ++i)
	{
		// 输入苹果的高度
		cin >> szHeight[i];
	}
	int height;// 记录陶陶的身高
	cin >> height;
	int num=0;// 记录苹果数量
	for (int i = 0; i < 10; ++i)
	{
		if (szHeight[i]<=height+30)
			++num;
	}
	cout << num;
	return 0;
}