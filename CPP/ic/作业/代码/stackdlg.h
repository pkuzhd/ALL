#ifndef STACKDLG_H
#define STACKDLG_H

#include "data.h"
#include <QDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QMainWindow>

class StackDlg : public QWidget
{
    Q_OBJECT

public:
    StackDlg(QWidget *parent = 0);
    ~StackDlg();
    mydata my_data;
private:
    // 当前登录的学生的学号
    QString cur_id;

    // 整体为堆栈窗体
    QStackedWidget *stack;

    // 开始界面需要的成员
    QWidget *start;
    QLabel *label_welcome;
    QLabel *block;
    QPushButton *button_teacher;
    QPushButton *button_student;
    QPushButton *button_quit;
    QVBoxLayout *startLayout;
    QVBoxLayout *buttonLayout;

    // 教务界面需要的成员
    QWidget *teacher;
    QStackedWidget *teacher_stack;
    QHBoxLayout *teacherLayout;
    QVBoxLayout *teacher_buttonLayout;
    QPushButton *add_lesson;
    QPushButton *del_lesson;
    QPushButton *edit_lesson;
    QPushButton *seek_lesson;
    QPushButton *goto_start;
    QWidget *t_blank;

    // 教师查看界面
    QWidget *seek_lesson_QW;
    QTableWidget *seek_lesson_table;
    QListWidget *seek_lesson_list;
    QGridLayout *seek_lesson_layout;

    // 添加课程
    QWidget *add_lesson_QW;
    QLabel *lesson_name_label;
    QLineEdit *lesson_name_edit;
    QLabel *teacher_name_label;
    QLineEdit *teacher_name_edit;
    QLabel *collage_name_label;
    QComboBox *collage_name_combobox;
    QLabel *n_total_label;
    QLineEdit *n_total_edit;
    QLabel *add_lesson_isright_label;
    QPushButton *add_lesson_submit;
    QPushButton *add_lesson_return;
    QGridLayout *add_lesson_layout;
    QHBoxLayout *add_lesson_button_layout;

    // 删除课程
    QWidget *del_lesson_QW;
    QLabel *del_lesson_isright;
    QTableWidget *del_lesson_table;
    QGridLayout *del_lesson_layout;
    QPushButton *del_lesson_submit;
    QPushButton *del_lesson_cancel;

    // 修改课程
    QWidget *edit_lesson_QW;
    QLabel *edit_lesson_label;
    QLabel *edit_lesson_isright;
    QLineEdit *edit_lesson_line;
    QPushButton *edit_lesson_submit;
    QPushButton *edit_lesson_cancel;
    QListWidget *edit_lesson_list;
    QGridLayout *edit_lesson_layout;
    QGridLayout *edit_lesson_edit_layout;


    // 学生界面需要的成员
    QWidget *student;
    QStackedWidget *student_stack;
    QHBoxLayout *studentLayout;
    QVBoxLayout *student_buttonLayout;
    QLabel *student_name;
    QPushButton *choose_lesson;
    QPushButton *quit_lesson;
    QPushButton *selcected_lesson;
    QPushButton *goto_start2;
    QWidget *s_blank;

    // 学生查看界面
    QWidget *selected_lesson_QW;
    QTableWidget *selected_lesson_table;
    QGridLayout *selected_lesson_layout;

    // 学生选课界面
    QWidget *choose_lesson_QW;
    QTableWidget *choose_lesson_table;
    QGridLayout *choose_lesson_layout;
    QPushButton *choose_lesson_submit;
    QPushButton *choose_lesson_cancel;

    // 学生退课界面
    QWidget *quit_lesson_QW;
    QTableWidget *quit_lesson_table;
    QGridLayout *quit_lesson_layout;
    QPushButton *quit_lesson_submit;
    QPushButton *quit_lesson_cancel;

    // 教务登入界面需要的成员
    QWidget *teacher_password;
    QLabel *teacher_password_label;
    QLabel *teacher_password_isright;
    QLabel *teacher_password_block;
    QLineEdit *teacher_password_edit;
    QPushButton *goto_start3;
    QPushButton *teacher_signin;
    QVBoxLayout *teacher_passwordLayout;
    QHBoxLayout *teacher_password_editLayout;
    QHBoxLayout *teacher_password_isrightLayout;
    QHBoxLayout *teacher_password_buttonLayout;

    // 学生登入界面需要的成员
    QWidget *student_password;
    QLabel *student_id_label;
    QLabel *student_password_label;
    QLabel *student_password_isright;
    QLabel *student_password_block;
    QLineEdit *student_id_edit;
    QLineEdit *student_password_edit;
    QPushButton *goto_start4;
    QPushButton *student_signin;
    QPushButton *goto_register;
    QVBoxLayout *student_passwordLayout;
    QHBoxLayout *student_id_editLayout;
    QHBoxLayout *student_password_editLayout;
    QHBoxLayout *student_password_isrightLayout;
    QHBoxLayout *student_password_buttonLayout;

    // 学生注册界面需要的成员
    QWidget *student_register; // 学生注册整体界面
    QLabel *register_name_label; // 姓名标签
    QLabel *register_id_label; // 学号标签
    QLabel *register_password_label; // 密码标签
    QLabel *register_password2_label; // 重复密码标签
    QLabel *register_password_isright; // 提示密码不一致标签
    QLabel *register_password_block; // 空标签
    QLineEdit *register_name_edit; // 姓名编辑栏
    QLineEdit *register_id_edit; // 学号编辑栏
    QLineEdit *register_password_edit; // 密码编辑栏
    QLineEdit *register_password2_edit; // 重复密码编辑栏
    QPushButton *goto_start5; // 返回按钮
    QPushButton *register_signin; // 注册并登录按钮
    QVBoxLayout *register_passwordLayout; // 整体纵向布局
    QHBoxLayout *register_name_editLayout; // 姓名横向布局
    QHBoxLayout *register_id_editLayout; // 学号横向布局
    QHBoxLayout *register_password_editLayout; // 密码横向布局
    QHBoxLayout *register_password2_editLayout; // 重复密码横向布局
    QHBoxLayout *register_password_isrightLayout; // 提示密码不一致横向布局
    QHBoxLayout *register_buttonLayout; // 按钮横向布局

    void set_start_mode();
    void set_teacher_mode();
    void set_student_mode();
    void set_teacher_password();
    void set_student_password();
    void set_student_register();
    void set_add_lesson();
    void set_del_lesson();
    void set_edit_lesson();
    void set_seek_lesson();
    void del_lesson_load_table();
    void seek_lesson_load_list();
    void clear_add_lesson();
    void clear_del_lesson();
    void clear_edit_lesson();
    void clear_seek_lesson();
    void set_choose_lesson();
    void set_quit_lesson();
    void set_selected_lesson();
    void choose_lesson_load_table();
    void quit_lesson_load_table();
    void selected_lesson_load_table();
private slots:
    void push_teacher();
    void push_student();
    void push_goto_start();
    void push_goto_start2();
    void push_goto_start3();
    void push_goto_start4();
    void push_goto_start5();
    void push_teacher_signin();
    void push_student_signin();
    void push_goto_register();
    void push_register_signin();
    void diff_password();
    void push_add_lesson();
    void push_add_lesson_cancel();
    void push_add_lesson_submit();
    void push_del_lesson();
    void push_del_lesson_cancel();
    void push_del_lesson_submit();
    void push_edit_lesson();
    void push_seek_lesson();
    void seek_lesson_load_table(int);
    void push_choose_lesson();
    void push_choose_lesson_submit();
    void push_choose_lesson_cancel();
    void push_quit_lesson();
    void push_quit_lesson_submit();
    void push_quit_lesson_cancel();
    void push_selcected_lesson();
};

#endif // STACKDLG_H
