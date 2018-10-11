#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int n, k, p, ans;
int cnt[52], f[52], last[52], now, c, v;
int main()
{
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> v;
		if (v <= p)  			  //咖啡店的最低消费不超过p		
			now = i;  		  //记住满足条件的咖啡店的位置 
		if (now >= last[c])   	//如果咖啡店在右边，则左边相同色调的客栈数就是该色调的方案数 
			f[c] = cnt[c];
		ans += f[c];  		//累加方案数 
		cnt[c]++;  			//相同色调的客栈数+1 
		last[c] = i;  		//该种色调最后出现的位置 
	}
	printf("%d\n", ans);  	//可选的住宿方案的总数
	return 0;
}
