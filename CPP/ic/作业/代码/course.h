#ifndef COURSE_H
#define COURSE_H

#include "student.h"
#include <QApplication>
#include <QVector>


class course
{
public:
    course(QString _name, QString _teacher, QString _college, int _n_total);
    course();
    void add_student(QString _id);
    void del_student(QString _id);
    bool change_total(int total);
    QString name;
    QString teacher;
    QString college;
    int n_total;
    int n_selected;
    QVector<QString> v_id;
    bool operator == (const course &another);
};

#endif // COURSE_H
