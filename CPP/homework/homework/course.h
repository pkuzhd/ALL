#pragma once
#ifndef _COURSE_H_
#define _COURSE_H_
#include <string>

class course
{
public:
	course(std::string &n);
	~course();
private:
	std::string name;
	int studentNum;
};

#endif // !_COURSE_H_