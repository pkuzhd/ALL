#ifndef DATA_CPP
#define DATA_CPP

#include "data.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

mydata::mydata()
{
    // 通过文件是否存在来判断是否为第一次使用选课系统
    QFileInfo fi("data");
    bool file_flag;
    if (!fi.isFile())
        file_flag = false;
    else
        file_flag = true;

    QFile data_file("data");
    if (!file_flag) // 第一次使用选课系统, 不读文件
        ;
    else
    {
        if (data_file.open(QIODevice::ReadWrite))
        {
            QTextStream fin(&data_file);
            fin >> password; // 初始密码
            fin >> n_course; // 课程数量
            fin >> n_student; // 学生数量
            for (int i = 0; i < n_course; ++i)
            {
                int t_idx = v_course.size();
                QString t_name, t_teacher, t_collage;
                int t_total, t_selected;
                fin >> t_name >> t_collage >> t_teacher;
                fin >> t_total >> t_selected;
                v_course.push_back(course(t_name, t_teacher, t_collage, t_total));
                for (int j = 0; j < t_selected; ++j)
                {
                    QString t_id;
                    fin >> t_id;
                    v_course[t_idx].v_id.push_back(t_id);
                    map_student[t_id].course_selceted.push_back(t_name);
                }
            }
            for (int i = 0; i < n_student; ++i)
            {
                QString t_name, t_id, t_password;
                fin >> t_name >> t_id >> t_password;
                map_student[t_id].id = t_id;
                map_student[t_id].name = t_name;
                map_student[t_id].password = t_password;
            }
            data_file.close();
        }
    }
}
void mydata::save()
{
    QFile data_file("data");
    if (data_file.open(QIODevice::ReadWrite))
    {
        QTextStream fout(&data_file);
        fout << password << " " << endl; // 初始密码
        fout << v_course.size() << " " << endl; // 课程数量
        fout << map_student.size() << " " << endl; // 学生数量
        for (auto it = v_course.begin(); it != v_course.end(); ++it)
        {
            fout << it->name << " " << it->college << " " << it->teacher << " ";
            fout << it->n_total << " " << it->v_id.size() << " ";
            for (auto jt = it->v_id.begin(); jt != it->v_id.end(); ++jt)
            {
                fout << *jt;
                fout << " ";
            }
            fout << endl;
        }
        for (auto it = map_student.begin(); it != map_student.end(); ++it)
        {
            fout << it.value().name << " " << it.value().id << " " << it.value().password << " " << endl;
        }
        data_file.close();
    }
}
QString mydata::get_password()
{
    return password;
}
void mydata::set_password(const QString &_password)
{
    password = _password;
}
bool mydata::add_lesson(QString name, QString teacher, QString collage, int total)
{
    // 在添加课程之前先看是否有相同教师相同名称的课程
    for (auto it = v_course.begin(); it != v_course.end(); ++it)
    {
        if (it->name == name && it->teacher == teacher)
            return false;
    }
    v_course.push_back(course(name, teacher, collage, total));
    return true;
}
#endif


