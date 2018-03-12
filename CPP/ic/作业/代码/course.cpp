#ifndef COURSE_CPP
#define COURSE_CPP
#include "course.h"

course::course(QString _name, QString _teacher, QString _college, int _n_total)
{
    name = _name;
    college = _college;
    teacher = _teacher;
    n_total = _n_total;
    n_selected = 0;
}
course::course()
{

}
void course::add_student(QString _id)
{
    v_id.push_back(_id);
}
void course::del_student(QString _id)
{
    v_id.removeOne(_id);
}

bool course::change_total(int total)
{
    return true;
}
bool course::operator == (const course &another)
{
    return name == another.name && teacher == another.teacher;
}
#endif
