// by TYY
// 20190926

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Polynomial {
public:
    int coefficient;
    int exponent;
};


// 用于排序的函数
bool sortBy(const Polynomial p1, const Polynomial p2)
{
    return p1.exponent > p2.exponent;
}


int main(int argc, const char *argv[])
{
    // 需要相加的多项式对数
    int n;
    cin >> n;
    // 进行循环
    for (int i = 0; i < n; ++i)
    {
        int coefficient, exponent;              // 系数与指数
        vector<Polynomial> curPolynomial;       // 当前多项式

        // 存储输入数据
        for (int j = 0; j < 2; ++j)
        {
            while (true) 
            {
                cin >> coefficient >> exponent;
                if (exponent < 0)
                    break;
                Polynomial temp;
                temp.coefficient = coefficient;
                temp.exponent = exponent;
                curPolynomial.push_back(temp);
            }
        }

        // 排序
        sort(curPolynomial.begin(), curPolynomial.end(), sortBy);

        // 输出（并相加）
        for (int j = 0; j < curPolynomial.size(); ++j)
        {
            coefficient = curPolynomial[j].coefficient;
            exponent = curPolynomial[j].exponent;
            // 最后一个直接输出
            if (j == curPolynomial.size() - 1)
            {
                if (coefficient != 0)
                    cout << "[ " << coefficient << ' ' << exponent << " ]";
            }
            else
            {
                int k = 1;
                for (; j+k < curPolynomial.size(); ++k)
                {
                    if (exponent == curPolynomial[j+k].exponent)
                    {
                        coefficient += curPolynomial[j+k].coefficient;
                    }
                    else
                        break;
                }
                j += k-1;
                if (coefficient == 0)
                    continue;
                cout << "[ " << coefficient << ' ' << exponent << " ]";
                if (j < curPolynomial.size() - 1)
                    cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}