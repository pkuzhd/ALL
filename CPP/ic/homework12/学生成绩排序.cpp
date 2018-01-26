// 学生成绩排序
// pkuzhd
// 2017.12.21
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


const double EPS = 1e-6;

struct Student
{
	string id;
	string name;
	int age;
	char sex;                 // 性别 'F' 或 'M' 
	double homeworkGrade;     // 平时作业 
	double midExamGrade;      // 期中成绩 
	double practiceGrade;     // 实验题 
	double finalExamGrade;    // 期末成绩 
	double finalGrade;        // 总成绩 
};

int cmp(void const* a, void const* b)
{
	return ((((const Student*)a)->finalGrade > ((const Student*)b)->finalGrade)
		|| (fabs(((const Student*)a)->finalGrade - ((const Student*)b)->finalGrade) < EPS && ((const Student*)a)->id < ((const Student*)b)->id)) ? -1 : 1;
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	Student *sz_student = new Student[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> sz_student[i].id
			>> sz_student[i].name
			>> sz_student[i].age
			>> sz_student[i].sex
			>> sz_student[i].homeworkGrade
			>> sz_student[i].midExamGrade
			>> sz_student[i].practiceGrade
			>> sz_student[i].finalExamGrade;
		sz_student[i].finalGrade = sz_student[i].homeworkGrade*0.15 + sz_student[i].midExamGrade*0.15 + sz_student[i].practiceGrade*0.10 + sz_student[i].finalExamGrade*0.60;
	}
	qsort(sz_student, n, sizeof(Student), cmp);

	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(10) << sz_student[i].id
			<< left << setw(10) << sz_student[i].name
			<< right << setw(2) << sz_student[i].age << " "
			<< sz_student[i].sex << " "
			<< fixed << setprecision(2) << setw(6) << sz_student[i].finalGrade
			<< endl;
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		if (sz_student[i].sex == 'F')
			cout << left << setw(10) << sz_student[i].id
			<< left << setw(10) << sz_student[i].name
			<< right << setw(2) << sz_student[i].age << " "
			<< sz_student[i].sex << " "
			<< fixed << setprecision(2) << setw(6) << sz_student[i].finalGrade
			<< endl;
	}
	delete[] sz_student;
	return 0;
}