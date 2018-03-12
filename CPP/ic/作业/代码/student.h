#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"
#include <QApplication>
#include <QVector>

class student
{
public:
    student();
    QString name;
    QString id;
    QString password;
    QVector<QString> course_selceted;
};

#endif // STUDENT_H
