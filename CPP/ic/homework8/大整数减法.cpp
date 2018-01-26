// 大整数减法
// pkuzhd
// 2017.11.11

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;  

int main()  
{  
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char num1[101], num2[101];
        cin >> num1 >> num2;
        int len1 = strlen(num1);
        int len2 = strlen(num2);
        int k = 0;
        for (int j = 1; j <= len2; ++j)
        {
            if (num1[len1-j]+k >= num2[len2-j])
            {
                num1[len1-j] = num1[len1-j]+k - (num2[len2-j]-'0');
                k = 0;
            }
            else
            {    
                num1[len1-j] = 10 + num1[len1-j]+k - (num2[len2-j]-'0');
                k = -1;
            }
        }
        for (int j = len2+1; k==-1; ++j)
        {
            if (num1[len1-j]+k>='0')
            {
                num1[len1-j] = num1[len1-j]+k;
                k = 0;
            }
            else
            {    
                num1[len1-j] = 10 + num1[len1-j]+k;
                k = -1;
            }
        }
        int flag = true;
        for (int j = 0; j < len1; ++j)
            if (flag && num1[j]=='0')
                continue;
            else
            {
                flag = false;
                cout << num1[j];
            }
        cout << endl;

    }
    return 0;  
}
