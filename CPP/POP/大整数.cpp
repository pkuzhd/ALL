#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class hugeint
{
public:
	hugeint();
	hugeint(const hugeint &);
	hugeint(const int &);
	hugeint(const char *number)
	{
		if (number[0] == '-')
		{
			negative = true;
			num = new char[strlen(number)];
			strcpy(num, number + 1);
			num[strlen(number) - 1] = '\0';
			return;
		}
		negative = false;
		num = new char[strlen(number) + 1];
		strcpy(num, number);
		num[strlen(number)] = '\0';
	}
	~hugeint();
	friend ostream &operator<<(ostream &out, const hugeint &number)
	{
		if (number.negative)
			out << '-';
		out << number.num;
		return out;
	}
	friend istream &operator>>(istream &in, hugeint &number)
	{
		string temp;
		in >> temp;
		number = temp.c_str();
		return in;
	}
	hugeint &operator=(const hugeint &number)
	{
		if (this == &number)
			return *this;
		delete[] num;
		num = new char[strlen(number.num) + 1];
		strcpy(num, number.num);
		num[strlen(number.num)] = '\0';
		return *this;
	}
	hugeint &operator=(const char *number)
	{
		delete[] num;
		*this = hugeint(number);
		return *this;
	}
	hugeint operator+(const hugeint &number)
	{
		hugeint temp;
		if (negative == number.negative)
		{
			int size1 = strlen(num);
			int size2 = strlen(number.num);
			int msize = (size1 > size2) ? size1 : size2;

			char *t_str = new char[msize + 1];
			int t = 0;
			if (size1 > size2)
			{
				int i = size1 - 1;
				t_str[msize] = '\0';
				for (; i >= msize - size2; --i)
				{
					t_str[i] = '0' + num[i] - '0' + number.num[i - msize + size2] - '0' + t;
					t = 0;
					if (t_str[i] - '0' >= 10)
					{
						t_str[i] -= 10;
						t = 1;
					}
				}
				for (; i >= 0; --i)
				{
					t_str[i] = '0' + num[i] - '0' + t;
					t = 0;
					if (t_str[i] - '0' >= 10)
					{
						t_str[i] -= 10;
						t = 1;
					}
				}
			}
			else
			{
				int i = size2 - 1;
				t_str[msize] = '\0';
				for (; i >= msize - size1; --i)
				{
					t_str[i] = '0' + num[i - msize + size1] - '0' + number.num[i] - '0' + t;
					t = 0;
					if (t_str[i] - '0' >= 10)
					{
						t_str[i] -= 10;
						t = 1;
					}
				}
				for (; i >= 0; --i)
				{
					t_str[i] = '0' + number.num[i] - '0' + t;
					t = 0;
					if (t_str[i] - '0' >= 10)
					{
						t_str[i] -= 10;
						t = 1;
					}
				}
			}
			if (t == 1)
			{
				delete[]temp.num;
				temp.num = new char[msize + 2];
				strcpy(temp.num + 1, t_str);
				temp.num[0] = '1';
			}
			else
			{
				delete[]temp.num;
				temp.num = new char[msize + 1];
				strcpy(temp.num, t_str);
			}
			delete[] t_str;
			temp.negative = negative;
			return temp;
		}
		int t_compare = abs_compare(number);
		if (t_compare == 0)
		{
			return temp;
		}
		else if (t_compare == 1)
		{
			int size1 = strlen(num);
			int size2 = strlen(number.num);

			int i = size1 - 1;
			int t = 0;
			char *t_str = new char[size1 + 1];
			t_str[size1] = '\0';
			for (; i >= size1 - size2; --i)
			{
				t_str[i] = '0' + num[i] - number.num[i - size1 + size2] + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (; i >= 0; --i)
			{
				t_str[i] = '0' + num[i] - '0' + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (i = 0; t_str[i] == '0'; ++i)
				;

			delete[]temp.num;
			temp.num = new char[size1 - i + 1];
			strcpy(temp.num, t_str + i);
			temp.num[size1 - i] = '\0';
			temp.negative = negative;
			delete[]t_str;
			return temp;
		}
		else
		{
			int size2 = strlen(num);
			int size1 = strlen(number.num);

			int i = size1 - 1;
			int t = 0;
			char *t_str = new char[size1 + 1];
			t_str[size1] = '\0';

			for (; i >= size1 - size2; --i)
			{
				t_str[i] = '0' + number.num[i] - num[i - size1 + size2] + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (; i >= 0; --i)
			{
				t_str[i] = '0' + number.num[i] - '0' + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (i = 0; t_str[i] == '0'; ++i)
				;

			delete[]temp.num;
			temp.num = new char[size1 - i + 1];
			strcpy(temp.num, t_str + i);
			temp.num[size1 - i] = '\0';
			temp.negative = !negative;
			delete[]t_str;
			return temp;
		}

	}
	hugeint operator+(const int &number)
	{
		return *this + hugeint(number);
	}
	friend hugeint operator+(int num2, const hugeint &num1)
	{
		return hugeint(num2) + num1;
	}
	hugeint operator-(const hugeint &number)
	{
		if (negative != number.negative)
		{
			hugeint temp = number;
			temp.negative = negative;
			return temp + *this;
		}
		int t_compare = abs_compare(number);
		if (t_compare == 0)
		{
			hugeint temp(0);
			return temp;
		}
		else if (t_compare == 1)
		{
			hugeint temp;
			int size1 = strlen(num);
			int size2 = strlen(number.num);

			int i = size1 - 1;
			int t = 0;
			char *t_str = new char[size1 + 1];
			t_str[size1] = '\0';
			for (; i >= size1 - size2; --i)
			{
				t_str[i] = '0' + num[i] - number.num[i - size1 + size2] + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (; i >= 0; --i)
			{
				t_str[i] = '0' + num[i] - '0' + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (i = 0; t_str[i] == '0'; ++i)
				;
			
			delete[]temp.num;
			temp.num = new char[size1 - i + 1];
			strcpy(temp.num, t_str + i);
			temp.num[size1 - i] = '\0';
			temp.negative = negative;
			delete[]t_str;
			return temp;
		}
		else
		{
			hugeint temp;
			int size2 = strlen(num);
			int size1 = strlen(number.num);

			int i = size1 - 1;
			int t = 0;
			char *t_str = new char[size1 + 1];
			t_str[size1] = '\0';

			for (; i >= size1 - size2; --i)
			{
				t_str[i] = '0' + number.num[i] - num[i - size1 + size2] + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (; i >= 0; --i)
			{
				t_str[i] = '0' + number.num[i] - '0' + t;
				t = 0;
				if (t_str[i] - '0' < 0)
				{
					t_str[i] += 10;
					t = -1;
				}
			}
			for (i = 0; t_str[i] == '0'; ++i)
				;

			delete[]temp.num;
			temp.num = new char[size1 - i + 1];
			strcpy(temp.num, t_str + i);
			temp.num[size1 - i] = '\0';
			temp.negative = !negative;
			delete[]t_str;
			return temp;
		}
	}
	hugeint operator*(const hugeint &number)
	{
		hugeint temp;
		int size1 = strlen(num);
		int size2 = strlen(number.num);
		int size = size1 + size2;
		int *t_int = new int[size];
		for (int i = 0; i < size; ++i)
		{
			t_int[i] = 0;
		}
		for (int i = size1 - 1; i >= 0; --i)
		{
			for (int j = size2 - 1; j >= 0; --j)
			{
				int index = size - (size1 - i) - (size2 - j) + 1;
				t_int[index] += (num[i] - '0') * (number.num[j] - '0');
			}
		}
		int t = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			t_int[i] += t;
			t = t_int[i] / 10;
			t_int[i] %= 10;
		}
		int i = 0;
		for (; i < size; ++i)
		{
			if (t_int[i] != 0)
				break;
		}
		if (i == size)
		{
			;
		}
		else
		{
			delete[] temp.num;
			int begin = i;
			temp.num = new char[size - begin + 1];
			for (; i < size; ++i)
			{
				temp.num[i - begin] = '0' + t_int[i];
			}
			temp.num[size - begin] = '\0';
		}
		delete[] t_int;
		temp.negative = negative ^ number.negative;
		return temp;
	}
	hugeint operator^(const int &number)
	{
		if (number == 0)
			return hugeint(0);
		hugeint temp = *this;
		for (int i = 1; i < number; ++i)
		{
			temp = temp * *this;
		}
		if (negative && number % 2)
			temp.negative = true;
		else
			temp.negative = false;
		return temp;
	}
	int abs_compare(const hugeint &number)
	{
		int size1 = strlen(num);
		int size2 = strlen(number.num);
		if (size1 > size2)
			return 1;
		if (size1 < size2)
			return -1;
		for (int i = 0; i < size1; ++i)
		{
			if (num[i] > number.num[i])
				return 1;
			if (num[i] < number.num[i])
				return -1;
		}
		return 0;
	}
	bool operator<(const hugeint &number)
	{
		if (negative && !number.negative)
			return true;
		if (!negative && number.negative)
			return false;
		return abs_compare(number) == -1;
	}
	bool operator>(const hugeint &number)
	{
		if (negative && !number.negative)
			return false;
		if (!negative && number.negative)
			return true;
		return abs_compare(number) == 1;

	}
	bool operator==(const hugeint &number)
	{
		if (negative != number.negative)
			return false;
		return abs_compare(number) == 0;

	}

private:
	char *num;
	bool negative;
};

hugeint::hugeint()
{
	negative = false;
	num = new char[2];
	num[0] = '0';
	num[1] = '\0';
}
hugeint::hugeint(const hugeint &other)
{
	negative = other.negative;
	num = new char[strlen(other.num) + 1];
	strcpy(num, other.num);
	num[strlen(other.num)] = '\0';
}
hugeint::hugeint(const int &other)
{
	int t;
	if (other == 0)
	{
		negative = false;
		num = new char[2];
		num[0] = '0';
		num[1] = '\0';
		return;
	}
	else if (other < 0)
	{
		negative = true;
		t = -other;

	}
	else
	{
		negative = false;
		t = other;
	}
	char temp[20];
	int i = 0;
	while (t > 0)
	{
		temp[i] = '0' + t % 10;
		t /= 10;
		++i;
	}
	num = new char[i + 1];
	--i;
	int j = 0;
	while (i >= 0)
	{
		num[j] = temp[i];
		--i;
		++j;
	}
	num[j] = '\0';
	 
}
hugeint::~hugeint()
{
	if (num)
		delete[] num;
}

int main(int argc, const char *argv[])
{
	cout << hugeint("100000000") + hugeint("-1000000000000") << endl;
	cout << hugeint("-100000000") + hugeint("1000000000000") << endl;
	cout << hugeint("-100000000") + hugeint("-1000000000000") << endl;
	cout << hugeint("100000000") + hugeint("1000000000000") << endl;
	return 0;
}