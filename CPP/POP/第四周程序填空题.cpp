#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	Complex() { r = i = 0; }
	Complex &operator=(char *str)
	{
		if (strlen(str) == 0)
		{
			r = i = 0;
			return *this;
		}
		double real = 0, image = 0;
		int k;
		for (k = 0; str[k] != '\0' && str[k] != '+'; ++k)
		{
			if (str[k] == 'i')
			{
				image = real;
				real = 0;
				r = real;
				i = image;
				return *this;
			}
			real = real * 10 + str[k] - '0';
		}
		++k;
		for (; str[k] != '\0'; ++k)
		{
			if (str[k] == 'i')
			{
				r = real;
				i = image;
				return *this;
			}
			image = image * 10 + str[k] - '0';
		}
		r = real;
		i = image;
		return *this;
	}
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	return 0;
}