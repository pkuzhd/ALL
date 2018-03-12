#ifndef DATA_H
#define DATA_H

#include "course.h"
#include "student.h"
#include <QApplication>
#include <QVector>
#include <QMap>


// 关于data文件的说明:
// 第一行为教务登录的密码password
// 第二行为课程数量n_course
// 第三行为学生数量n_student
// 接下来有n_course行, 每行为一个课程的数据, 课程数据依次为(以空格隔开):
// 课程名称 开课院系 开课老师 总人数 已选人数n_selected n_selected个已选学生的学号
// 接下来有n_student行, 每行为一个学生的数据, 学生数据依次为(以空格隔开):
// 姓名 学号 密码(后面的不需要, 因为可以通过课程信息来推出来)(已选课程数量n_selected n_selected个已选课程名称)
class mydata
{
public:
    QVector<course> v_course; // 课程数据
    QMap<QString, student> map_student; // 学生数据

    mydata();
    void save(); // 保存数据到文件
    QString get_password(); // 获取密码
    void set_password(const QString &_password); // 设置密码
    bool add_lesson(QString name, QString teacher, QString collage, int total);


private:
    int n_course = 0; // 课程数
    int n_student = 0; // 学生数
    QString password = "12345"; // 教务密码

};

#endif // DATA_H
