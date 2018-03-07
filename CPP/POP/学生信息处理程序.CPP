#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
	string name;
	int age;
	int id;
	float score[4];
	float average; 
public:
	void input()
	{
		string str, t_str;
		getline(cin, name, ',');
		for (int i = 0; i < 5; ++i)
		{
			getline(cin, t_str, ',');
			str += t_str + ' ';
		}
		getline(cin, t_str);
		str += t_str + ' ';
		istringstream s_sin(str);
		s_sin >> age >> id >> score[0] >> score[1] >> score[2] >> score[3];
	}
	void calculate()
	{
		average = (score[0] + score[1] + score[2] + score[3]) / 4;
	}
	void output()
	{
		cout << name << ',' << age << ',' << id << ',' << average << endl;
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}