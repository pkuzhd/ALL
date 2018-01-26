#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <vector>

class student
{
public:
	student(std::string &str);
	student();
	~student();
private:
	std::string name;
	std::string id;
	std::string password;
	std::vector<std::string> course_selceted;

};
#endif // !_STUDENT_H_



