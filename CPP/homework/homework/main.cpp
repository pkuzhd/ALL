
#include <cstdio>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "course.h"
#include "student.h"

#define PASSWOAD_HASH 2282126479029740061

using std::cout;
using std::endl;
using std::cin;
using std::hash;
using std::string;
using std::ofstream;

string ch(const string str, int n)
{
	string temp;
	for (int i = 0; i < n; ++i)
		temp += str;
	return temp;
}

void print_mode()
{
	system("cls");
	cout << ch("\n", 12);
	cout << ch(" ", 52) << "欢迎使用选课系统" << endl << endl;
	cout << ch(" ", 56) << "1.教务" << endl;
	cout << ch(" ", 56) << "2.学生" << endl;
	cout << ch(" ", 56) << "3.退出" << endl;
}

void print_teacher_mode()
{
	system("cls");
	cout << ch("\n", 14);
	cout << ch(" ", 56) << "1.添加课程" << endl;
	cout << ch(" ", 56) << "2.删除课程" << endl;
	cout << ch(" ", 56) << "3.修改课程" << endl;
	cout << ch(" ", 56) << "4.查看结果" << endl;
	cout << ch(" ", 56) << "5.返回" << endl;
}

void print_student_mode()
{
	system("cls");
	cout << ch("\n", 14);
	cout << ch(" ", 56) << "1.选课" << endl;
	cout << ch(" ", 56) << "2.退课" << endl;
	cout << ch(" ", 56) << "3.查看" << endl;
	cout << ch(" ", 56) << "4.返回" << endl;
}

void print_password(int num = 0)
{
	system("cls");
	cout << ch("\n", 14);
	cout << ch(" ", 52) << "请输入密码:";
	for (int i = 0; i < num; ++i)
		cout << '*';
}

bool passward(string str)
{
	hash<string> h;
	return h(str) == PASSWOAD_HASH;
}

int main(int argc, char *argv[])
{
	// ofstream student_out("data\\student");
	// ofstream course_out("data\\course");
	char c;
	while (true)
	{
		print_mode();
		while (c = _getch())
		{
			if (c == '1')
			{
				// 实现输入密码并判断密码
				print_password();
				string tempStr;
				while ((c = _getch()) != '\r')
				{
					if (c >= '0' && c <= '9')
					{
						tempStr += c;
						cout << '*';
					}
					else if (c == '\b' && tempStr.size() > 0)
					{
						tempStr.pop_back();
						print_password(tempStr.size());
					}
				}
				if (passward(tempStr))
				{
					print_teacher_mode();
				}
				else
					break;

			}
			else if (c == '2')
			{
				print_student_mode();
			}
			else if (c == '3')
				return 0;
		}
	}
	return 0;
}