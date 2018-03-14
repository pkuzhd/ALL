#include "stackdlg.h"
#include <QApplication>
#include <QDebug>
#include <QHeaderView>
#include <QtAlgorithms>

StackDlg::StackDlg(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr(u8"选课系统 by pkuzhd"));

    // 开始界面
    set_start_mode();
    set_teacher_mode();
    set_student_mode();
    set_teacher_password();
    set_student_password();
    set_student_register();

    // 主堆栈窗体
    stack = new QStackedWidget(this);
    stack->setMaximumSize(800, 450);
    stack->setMinimumSize(800, 450);
    stack->addWidget(start);
    stack->addWidget(teacher);
    stack->addWidget(student);
    stack->addWidget(teacher_password);
    stack->addWidget(student_password);
    stack->addWidget(student_register);

    // 主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(20);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);
    mainLayout->setStretchFactor(stack, 2);

    // 临时设置
    // stack->setCurrentIndex(1);

}

void StackDlg::set_start_mode()
{
    label_welcome = new QLabel(tr(u8"欢迎使用选课系统!"));
    block = new QLabel();
    label_welcome->setAlignment(Qt::AlignCenter);
    button_teacher = new QPushButton(tr(u8"教务"));
    button_student = new QPushButton(tr(u8"学生"));
    button_quit = new QPushButton(tr(u8"退出"));
    // 设置大小
    QSize button_size(120, 40);
    QSize label_size(400, 60);
    QFont label_font("AR PL KaitiM GB", 24);
    QFont button_font("AR PL KaitiM GB", 16);
    label_welcome->setMinimumSize(label_size);
    label_welcome->setMaximumSize(label_size);
    block->setMinimumSize(label_size);
    block->setMaximumSize(label_size);
    button_teacher->setMinimumSize(button_size);
    button_teacher->setMaximumSize(button_size);
    button_student->setMinimumSize(button_size);
    button_student->setMaximumSize(button_size);
    button_quit->setMinimumSize(button_size);
    button_quit->setMaximumSize(button_size);
    label_welcome->setFont(label_font);
    button_teacher->setFont(button_font);
    button_student->setFont(button_font);
    button_quit->setFont(button_font);


    start = new QWidget(this);
    startLayout = new QVBoxLayout(start);
    buttonLayout = new QVBoxLayout(start);
    startLayout->addWidget(label_welcome);
    startLayout->addWidget(block);
    buttonLayout->addWidget(button_teacher);
    buttonLayout->addWidget(button_student);
    buttonLayout->addWidget(button_quit);
    startLayout->addLayout(buttonLayout, 2);
    buttonLayout->setAlignment(Qt::AlignHCenter);
    startLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(20);
    connect(button_teacher, SIGNAL(clicked(bool)), this, SLOT(push_teacher()));
    connect(button_student, SIGNAL(clicked(bool)), this, SLOT(push_student()));
    connect(button_quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
void StackDlg::set_teacher_mode()
{
    teacher = new QWidget(this);
    teacherLayout = new QHBoxLayout(teacher);
    teacher_buttonLayout = new QVBoxLayout();
    teacher_stack = new QStackedWidget();
    t_blank = new QWidget();
    teacher_stack->setFixedSize(650, 450);

    add_lesson = new QPushButton(tr(u8"添加课程"));
    del_lesson = new QPushButton(tr(u8"删除课程"));
    edit_lesson = new QPushButton(tr(u8"修改课程"));
    seek_lesson = new QPushButton(tr(u8"查看结果"));
    goto_start = new QPushButton(tr(u8"返回"));

    set_add_lesson();
    set_del_lesson();
    set_edit_lesson();
    set_seek_lesson();
    teacher_stack->addWidget(seek_lesson_QW);
    teacher_stack->addWidget(add_lesson_QW);
    teacher_stack->addWidget(del_lesson_QW);


    QSize button_size(120, 40);
    QSize label_size(400, 60);
    QFont label_font("AR PL KaitiM GB", 24);
    QFont button_font("AR PL KaitiM GB", 16);
    add_lesson->setMinimumSize(button_size);
    add_lesson->setMaximumSize(button_size);
    add_lesson->setFont(button_font);
    del_lesson->setMinimumSize(button_size);
    del_lesson->setMaximumSize(button_size);
    del_lesson->setFont(button_font);
    edit_lesson->setMinimumSize(button_size);
    edit_lesson->setMaximumSize(button_size);
    edit_lesson->setFont(button_font);
    seek_lesson->setMinimumSize(button_size);
    seek_lesson->setMaximumSize(button_size);
    seek_lesson->setFont(button_font);
    goto_start->setMinimumSize(button_size);
    goto_start->setMaximumSize(button_size);
    goto_start->setFont(button_font);

    teacher_buttonLayout->addWidget(add_lesson);
    teacher_buttonLayout->addWidget(del_lesson);
    teacher_buttonLayout->addWidget(edit_lesson);
    teacher_buttonLayout->addWidget(seek_lesson);
    teacher_buttonLayout->addWidget(goto_start);

    teacher_buttonLayout->setAlignment(Qt::AlignCenter);
    teacherLayout->addLayout(teacher_buttonLayout);
    teacherLayout->addWidget(teacher_stack);
    //teacherLayout->setStretchFactor(teacher_buttonLayout, 1);
    //teacherLayout->setStretchFactor(teacher_stack, 5);
    teacherLayout->setSpacing(10);

    connect(add_lesson, SIGNAL(clicked(bool)), this, SLOT(push_add_lesson()));
    connect(del_lesson, SIGNAL(clicked(bool)), this, SLOT(push_del_lesson()));
    connect(edit_lesson, SIGNAL(clicked(bool)), this, SLOT(push_edit_lesson()));
    connect(seek_lesson, SIGNAL(clicked(bool)), this, SLOT(push_seek_lesson()));
    connect(goto_start, SIGNAL(clicked(bool)), this, SLOT(push_goto_start()));
}
void StackDlg::set_student_mode()
{
    student = new QWidget(this);
    s_blank = new QWidget();
    studentLayout = new QHBoxLayout(student);
    student_buttonLayout = new QVBoxLayout();
    student_stack = new QStackedWidget();
    student_stack->setFixedSize(650, 450);

    set_choose_lesson();
    set_quit_lesson();
    set_selected_lesson();

    student_stack->addWidget(selected_lesson_QW);
    student_stack->addWidget(choose_lesson_QW);
    student_stack->addWidget(quit_lesson_QW);

    student_name = new QLabel(tr(u8""));
    choose_lesson = new QPushButton(tr(u8"选课"));
    quit_lesson = new QPushButton(tr(u8"退课"));
    selcected_lesson = new QPushButton(tr(u8"查看"));
    goto_start2 = new QPushButton(tr(u8"返回"));
    student_name->setAlignment(Qt::AlignCenter);

    QSize button_size(120, 40);
    QSize label_size(400, 60);
    QFont label_font("AR PL KaitiM GB", 24);
    QFont button_font("AR PL KaitiM GB", 16);
    student_name->setMinimumSize(button_size);
    student_name->setMaximumSize(button_size);
    student_name->setFont(button_font);
    choose_lesson->setMinimumSize(button_size);
    choose_lesson->setMaximumSize(button_size);
    choose_lesson->setFont(button_font);
    quit_lesson->setMinimumSize(button_size);
    quit_lesson->setMaximumSize(button_size);
    quit_lesson->setFont(button_font);
    selcected_lesson->setMinimumSize(button_size);
    selcected_lesson->setMaximumSize(button_size);
    selcected_lesson->setFont(button_font);
    goto_start2->setMinimumSize(button_size);
    goto_start2->setMaximumSize(button_size);
    goto_start2->setFont(button_font);

    student_buttonLayout->addWidget(student_name);
    student_buttonLayout->addWidget(choose_lesson);
    student_buttonLayout->addWidget(quit_lesson);
    student_buttonLayout->addWidget(selcected_lesson);
    student_buttonLayout->addWidget(goto_start2);

    student_buttonLayout->setAlignment(Qt::AlignCenter);
    studentLayout->addLayout(student_buttonLayout);
    studentLayout->addWidget(student_stack);
    studentLayout->setSpacing(10);
    connect(choose_lesson, SIGNAL(clicked(bool)), this, SLOT(push_choose_lesson()));
    connect(quit_lesson, SIGNAL(clicked(bool)), this, SLOT(push_quit_lesson()));
    connect(selcected_lesson, SIGNAL(clicked(bool)), this, SLOT(push_selcected_lesson()));
    connect(goto_start2, SIGNAL(clicked(bool)), this, SLOT(push_goto_start2()));
}
void StackDlg::set_teacher_password()
{
    teacher_password = new QWidget(this);
    teacher_password_label = new QLabel(tr(u8"密码: "));
    teacher_password_isright = new QLabel(tr(u8""));
    teacher_password_block = new QLabel(tr(u8""));
    teacher_password_edit = new QLineEdit();
    goto_start3 = new QPushButton(tr(u8"返回"));
    teacher_signin = new QPushButton(tr(u8"登录"));
    teacher_passwordLayout = new QVBoxLayout(teacher_password);
    teacher_password_buttonLayout = new QHBoxLayout();
    teacher_password_editLayout = new QHBoxLayout();
    teacher_password_isrightLayout = new QHBoxLayout();

    teacher_password_edit->setEchoMode(QLineEdit::Password);

    QSize label_size(40, 30);
    int my_height = 35;
    QFont password_font("AR PL KaitiM GB", 6);
    QFont button_font("AR PL KaitiM GB", 12);
    teacher_password_edit->setMaximumSize(label_size);
    teacher_password_edit->setMinimumSize(label_size);
    teacher_password_edit->setMinimumWidth(250);
    teacher_password_edit->setMaximumWidth(250);
    teacher_password_label->setMaximumSize(label_size);
    teacher_password_label->setMinimumSize(label_size);
    teacher_password_block->setMaximumSize(label_size);
    teacher_password_block->setMinimumSize(label_size);
    teacher_signin->setMaximumHeight(my_height);
    teacher_signin->setMinimumHeight(my_height);
    goto_start3->setMaximumHeight(my_height);
    goto_start3->setMinimumHeight(my_height);
    teacher_password_isright->setStyleSheet("color:red;");

    teacher_password_edit->setFont(password_font);
    teacher_signin->setFont(button_font);
    goto_start3->setFont(button_font);
    teacher_password_isright->setFont(button_font);
    teacher_password_block->setFont(button_font);
    teacher_password_label->setFont(button_font);

    teacher_password_buttonLayout->addWidget(teacher_signin);
    teacher_password_buttonLayout->addWidget(goto_start3);
    teacher_password_editLayout->addWidget(teacher_password_label);
    teacher_password_editLayout->addWidget(teacher_password_edit);
    teacher_password_isrightLayout->addWidget(teacher_password_block);
    teacher_password_isrightLayout->addWidget(teacher_password_isright);
    teacher_passwordLayout->addLayout(teacher_password_editLayout);
    teacher_passwordLayout->addLayout(teacher_password_isrightLayout);
    teacher_passwordLayout->addLayout(teacher_password_buttonLayout);

    teacher_passwordLayout->setAlignment(Qt::AlignCenter);
    teacher_passwordLayout->setSpacing(10);

    connect(goto_start3, SIGNAL(clicked(bool)), this, SLOT(push_goto_start3()));
    connect(teacher_signin, SIGNAL(clicked(bool)), this, SLOT(push_teacher_signin()));
}
void StackDlg::set_student_password()
{
    student_password = new QWidget(this);
    student_id_label = new QLabel(tr(u8"学号: "));
    student_password_label = new QLabel(tr(u8"密码: "));
    student_password_isright = new QLabel(tr(u8""));
    student_password_block = new QLabel(tr(u8""));
    student_id_edit = new QLineEdit();
    student_password_edit = new QLineEdit();
    goto_start4 = new QPushButton(tr(u8"返回"));
    student_signin = new QPushButton(tr(u8"登录"));
    goto_register = new QPushButton(tr(u8"注册"));
    student_passwordLayout = new QVBoxLayout(student_password);
    student_password_buttonLayout = new QHBoxLayout();
    student_password_editLayout = new QHBoxLayout();
    student_id_editLayout = new QHBoxLayout();
    student_password_isrightLayout = new QHBoxLayout();

    QRegExp rx("[1-9][0-9]{9}");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    student_id_edit->setValidator(pReg);

    QSize label_size(40, 30);
    int my_height = 35;
    QFont password_font("AR PL KaitiM GB", 6);
    QFont id_font("AR PL KaitiM GB", 12);
    QFont button_font("AR PL KaitiM GB", 12);
    student_password_edit->setMaximumSize(label_size);
    student_password_edit->setMinimumSize(label_size);
    student_password_edit->setMinimumWidth(250);
    student_password_edit->setMaximumWidth(250);
    student_id_edit->setMaximumSize(label_size);
    student_id_edit->setMinimumSize(label_size);
    student_id_edit->setMinimumWidth(250);
    student_id_edit->setMaximumWidth(250);
    student_password_label->setMaximumSize(label_size);
    student_password_label->setMinimumSize(label_size);
    student_password_block->setMaximumSize(label_size);
    student_password_block->setMinimumSize(label_size);
    student_id_label->setMaximumSize(label_size);
    student_id_label->setMinimumSize(label_size);
    student_signin->setMaximumHeight(my_height);
    student_signin->setMinimumHeight(my_height);
    goto_register->setMaximumHeight(my_height);
    goto_register->setMinimumHeight(my_height);
    goto_start4->setMaximumHeight(my_height);
    goto_start4->setMinimumHeight(my_height);
    student_password_isright->setStyleSheet("color:red;");

    student_id_edit->setFont(id_font);
    student_password_edit->setFont(password_font);
    student_signin->setFont(button_font);
    goto_register->setFont(button_font);
    goto_start4->setFont(button_font);
    student_password_isright->setFont(button_font);
    student_id_label->setFont(button_font);
    student_password_label->setFont(button_font);
    student_password_block->setFont(button_font);

    student_password_edit->setEchoMode(QLineEdit::Password);


    student_id_editLayout->addWidget(student_id_label);
    student_id_editLayout->addWidget(student_id_edit);
    student_password_editLayout->addWidget(student_password_label);
    student_password_editLayout->addWidget(student_password_edit);
    student_password_isrightLayout->addWidget(student_password_block);
    student_password_isrightLayout->addWidget(student_password_isright);
    student_password_buttonLayout->addWidget(student_signin);
    student_password_buttonLayout->addWidget(goto_register);
    student_password_buttonLayout->addWidget(goto_start4);
    student_passwordLayout->addLayout(student_id_editLayout);
    student_passwordLayout->addLayout(student_password_editLayout);
    student_passwordLayout->addLayout(student_password_isrightLayout);
    student_passwordLayout->addLayout(student_password_buttonLayout);

    student_passwordLayout->setAlignment(Qt::AlignCenter);
    student_passwordLayout->setSpacing(10);

    connect(goto_start4, SIGNAL(clicked(bool)), this, SLOT(push_goto_start4()));
    connect(student_signin, SIGNAL(clicked(bool)), this, SLOT(push_student_signin()));
    connect(goto_register, SIGNAL(clicked(bool)), this, SLOT(push_goto_register()));
}
void StackDlg::set_student_register()
{
    student_register = new QWidget(this); // 学生注册整体界面
    register_name_label = new QLabel(tr(u8"    姓名：")); // 姓名标签
    register_id_label = new QLabel(tr(u8"    学号：")); // 学号标签
    register_password_label = new QLabel(tr(u8"    密码：")); // 密码标签
    register_password2_label = new QLabel(tr(u8"重复密码：")); // 重复密码标签
    register_password_isright = new QLabel(tr(u8"")); // 提示密码不一致标签
    register_password_block = new QLabel(tr(u8"")); // 空标签
    register_name_edit = new QLineEdit(); // 姓名编辑栏
    register_id_edit = new QLineEdit(); // 学号编辑栏
    register_password_edit = new QLineEdit(); // 密码编辑栏
    register_password2_edit = new QLineEdit(); // 重复密码编辑栏
    goto_start5 = new QPushButton(tr(u8"返回")); // 返回按钮
    register_signin = new QPushButton(tr(u8"注册")); // 注册并登录按钮
    register_passwordLayout = new QVBoxLayout(student_register); // 整体纵向布局
    register_name_editLayout = new QHBoxLayout(); // 姓名横向布局
    register_id_editLayout = new QHBoxLayout(); // 学号横向布局
    register_password_editLayout = new QHBoxLayout(); // 密码横向布局
    register_password2_editLayout = new QHBoxLayout(); // 重复密码横向布局
    register_password_isrightLayout = new QHBoxLayout(); // 提示密码不一致横向布局
    register_buttonLayout = new QHBoxLayout(); // 按钮横向布局

    QRegExp rx("[1-9][0-9]{9}");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    register_id_edit->setValidator(pReg);

    QSize label_size(70, 30);
    int my_height = 35;
    QFont password_font("AR PL KaitiM GB", 6);
    QFont id_font("AR PL KaitiM GB", 12);
    QFont button_font("AR PL KaitiM GB", 12);
    register_name_edit->setMaximumSize(label_size);
    register_name_edit->setMinimumSize(label_size);
    register_name_edit->setMinimumWidth(250);
    register_name_edit->setMaximumWidth(250);
    register_id_edit->setMaximumSize(label_size);
    register_id_edit->setMinimumSize(label_size);
    register_id_edit->setMinimumWidth(250);
    register_id_edit->setMaximumWidth(250);
    register_password_edit->setMaximumSize(label_size);
    register_password_edit->setMinimumSize(label_size);
    register_password_edit->setMinimumWidth(250);
    register_password_edit->setMaximumWidth(250);
    register_password2_edit->setMaximumSize(label_size);
    register_password2_edit->setMinimumSize(label_size);
    register_password2_edit->setMinimumWidth(250);
    register_password2_edit->setMaximumWidth(250);
    register_name_label->setMaximumSize(label_size);
    register_name_label->setMinimumSize(label_size);
    register_id_label->setMaximumSize(label_size);
    register_id_label->setMinimumSize(label_size);
    register_password_label->setMaximumSize(label_size);
    register_password_label->setMinimumSize(label_size);
    register_password2_label->setMaximumSize(label_size);
    register_password2_label->setMinimumSize(label_size);
    register_password_block->setMaximumSize(label_size);
    register_password_block->setMinimumSize(label_size);
    goto_start5->setMaximumHeight(my_height);
    goto_start5->setMinimumHeight(my_height);
    register_signin->setMaximumHeight(my_height);
    register_signin->setMinimumHeight(my_height);
    register_password_isright->setStyleSheet("color:red;");

    register_name_edit->setFont(id_font);
    register_id_edit->setFont(id_font);
    register_password_edit->setFont(password_font);
    register_password2_edit->setFont(password_font);
    register_name_label->setFont(button_font);
    register_id_label->setFont(button_font);
    register_password_label->setFont(button_font);
    register_password2_label->setFont(button_font);
    register_password_isright->setFont(button_font);
    register_password_block->setFont(button_font);
    register_signin->setFont(button_font);
    goto_start5->setFont(button_font);

    register_password_edit->setEchoMode(QLineEdit::Password);
    register_password2_edit->setEchoMode(QLineEdit::Password);

    register_name_editLayout->addWidget(register_name_label);
    register_name_editLayout->addWidget(register_name_edit);
    register_id_editLayout->addWidget(register_id_label);
    register_id_editLayout->addWidget(register_id_edit);
    register_password_editLayout->addWidget(register_password_label);
    register_password_editLayout->addWidget(register_password_edit);
    register_password2_editLayout->addWidget(register_password2_label);
    register_password2_editLayout->addWidget(register_password2_edit);
    register_password_isrightLayout->addWidget(register_password_block);
    register_password_isrightLayout->addWidget(register_password_isright);
    register_buttonLayout->addWidget(register_signin);
    register_buttonLayout->addWidget(goto_start5);
    register_passwordLayout->addLayout(register_name_editLayout);
    register_passwordLayout->addLayout(register_id_editLayout);
    register_passwordLayout->addLayout(register_password_editLayout);
    register_passwordLayout->addLayout(register_password2_editLayout);
    register_passwordLayout->addLayout(register_password_isrightLayout);
    register_passwordLayout->addLayout(register_buttonLayout);



    register_passwordLayout->setAlignment(Qt::AlignCenter);
    register_passwordLayout->setSpacing(10);

    connect(goto_start5, SIGNAL(clicked(bool)), this, SLOT(push_goto_start5()));
    connect(register_signin, SIGNAL(clicked(bool)), this, SLOT(push_register_signin()));
    connect(register_password2_edit, SIGNAL(textChanged(QString)), this, SLOT(diff_password()));
}
void StackDlg::set_add_lesson()
{
    add_lesson_QW = new QWidget(this);
    lesson_name_label = new QLabel(tr(u8"课程名称："));
    lesson_name_edit = new QLineEdit();
    teacher_name_label = new QLabel(tr(u8"教师名称："));
    teacher_name_edit = new QLineEdit();
    collage_name_label = new QLabel(tr(u8"开课学院："));
    collage_name_combobox = new QComboBox();
    collage_name_combobox->addItem(tr(u8"<请选择>"));
    collage_name_combobox->addItem(tr(u8"信科"));
    collage_name_combobox->addItem(tr(u8"地空"));
    collage_name_combobox->addItem(tr(u8"中文"));
    collage_name_combobox->addItem(tr(u8"元培"));
    collage_name_combobox->addItem(tr(u8"哲学"));
    collage_name_combobox->addItem(tr(u8"农学院"));
    n_total_label = new QLabel(tr(u8"人数上限："));
    n_total_edit = new QLineEdit();
    add_lesson_isright_label = new QLabel(tr(u8""));
    add_lesson_submit = new QPushButton(tr(u8"添加"));
    add_lesson_return = new QPushButton(tr(u8"取消"));
    add_lesson_layout = new QGridLayout(add_lesson_QW);
    add_lesson_button_layout = new QHBoxLayout();

    QRegExp rx("[1-4]?[0-9]{2}");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    n_total_edit->setValidator(pReg);
    add_lesson_isright_label->setStyleSheet("color:red;");


    lesson_name_edit->setMinimumWidth(200);
    lesson_name_edit->setMaximumWidth(200);
    collage_name_combobox->setMinimumWidth(200);
    collage_name_combobox->setMaximumWidth(200);
    teacher_name_edit->setMinimumWidth(200);
    teacher_name_edit->setMaximumWidth(200);
    n_total_edit->setMinimumWidth(200);
    n_total_edit->setMaximumWidth(200);
    add_lesson_isright_label->setMinimumHeight(20);
    add_lesson_isright_label->setMaximumHeight(20);

    lesson_name_label->setMinimumWidth(70);
    lesson_name_label->setMaximumWidth(70);

    add_lesson_layout->addWidget(lesson_name_label, 0, 0);
    add_lesson_layout->addWidget(lesson_name_edit, 0, 1);
    add_lesson_layout->addWidget(collage_name_label, 1, 0);
    add_lesson_layout->addWidget(collage_name_combobox, 1, 1);
    add_lesson_layout->addWidget(teacher_name_label, 2, 0);
    add_lesson_layout->addWidget(teacher_name_edit, 2, 1);
    add_lesson_layout->addWidget(n_total_label, 3, 0);
    add_lesson_layout->addWidget(n_total_edit, 3, 1);
    add_lesson_layout->addWidget(add_lesson_isright_label, 4, 1);
    add_lesson_layout->addLayout(add_lesson_button_layout, 5, 1);
    add_lesson_button_layout->addWidget(add_lesson_submit);
    add_lesson_button_layout->addWidget(add_lesson_return);
    add_lesson_layout->setAlignment(Qt::AlignCenter);
    add_lesson_layout->setAlignment(Qt::AlignHCenter);

    connect(add_lesson_submit, SIGNAL(clicked(bool)), this, SLOT(push_add_lesson_submit()));
    connect(add_lesson_return, SIGNAL(clicked(bool)), this, SLOT(push_add_lesson_cancel()));
}
void StackDlg::set_del_lesson()
{
    del_lesson_QW = new QWidget();
    del_lesson_table = new QTableWidget();
    del_lesson_isright = new QLabel();
    del_lesson_table->setRowCount(my_data.v_course.size());
    del_lesson_table->setColumnCount(4);
    del_lesson_layout = new QGridLayout(del_lesson_QW);
    del_lesson_submit = new QPushButton(tr(u8"删除课程"));
    del_lesson_cancel = new QPushButton(tr(u8"取消"));

    del_lesson_isright->setStyleSheet("color:red;");
    del_lesson_table->setMaximumSize(550, 300);
    del_lesson_table->setMinimumSize(550, 300);

    del_lesson_layout->addWidget(del_lesson_table, 0, 0, 1, 6);
    del_lesson_layout->addWidget(del_lesson_isright, 1, 0);
    del_lesson_layout->addWidget(del_lesson_submit, 1, 4);
    del_lesson_layout->addWidget(del_lesson_cancel, 1, 5);

    del_lesson_layout->setAlignment(Qt::AlignHCenter);

    del_lesson_table->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    del_lesson_table->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    del_lesson_table->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    del_lesson_table->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    del_lesson_table->horizontalHeader()->setStretchLastSection(true);
    //del_lesson_table->verticalHeader()->setStretchLastSection(true);
    del_lesson_table->horizontalHeader()->setEnabled(false);
    del_lesson_table->verticalHeader()->setEnabled(false);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << u8"课程名称" << u8"开课院系" << u8"授课教师" << u8"已选人数/总人数";
    del_lesson_table->setHorizontalHeaderLabels(headerLabels);

    del_lesson_load_table();

    connect(del_lesson_submit, SIGNAL(clicked(bool)), this, SLOT(push_del_lesson_submit()));
    connect(del_lesson_cancel, SIGNAL(clicked(bool)), this, SLOT(push_del_lesson_cancel()));
}
void StackDlg::set_edit_lesson()
{

}
void StackDlg::set_seek_lesson()
{
    seek_lesson_QW = new QWidget();
    seek_lesson_list = new QListWidget();
    seek_lesson_table = new QTableWidget();
    seek_lesson_table->setRowCount(my_data.v_course.size());
    seek_lesson_table->setColumnCount(2);
    seek_lesson_layout = new QGridLayout(seek_lesson_QW);
    seek_lesson_layout->setSpacing(20);

    seek_lesson_list->setMaximumSize(120, 300);
    seek_lesson_list->setMinimumSize(120, 300);
    seek_lesson_table->setMaximumSize(400, 300);
    seek_lesson_table->setMinimumSize(400, 300);

    seek_lesson_layout->addWidget(seek_lesson_list, 0, 0);
    seek_lesson_layout->addWidget(seek_lesson_table, 0, 1, 1, 3);
    seek_lesson_layout->setAlignment(Qt::AlignHCenter);

    seek_lesson_table->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    seek_lesson_table->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    seek_lesson_table->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    seek_lesson_table->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    seek_lesson_table->horizontalHeader()->setStretchLastSection(true);
    //seek_lesson_table->verticalHeader()->setStretchLastSection(true);
    seek_lesson_table->horizontalHeader()->setEnabled(false);
    seek_lesson_table->verticalHeader()->setEnabled(false);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << u8"姓名" << u8"学号";
    seek_lesson_table->setHorizontalHeaderLabels(headerLabels);

    seek_lesson_load_list();
    seek_lesson_load_table(-1);
    connect(seek_lesson_list, SIGNAL(currentRowChanged(int)), this, SLOT(seek_lesson_load_table(int)));
}
void StackDlg::del_lesson_load_table()
{
    del_lesson_table->setRowCount(my_data.v_course.size());
    for (int i = 0; i != my_data.v_course.size(); ++i)
    {
        QTableWidgetItem *t_name = new QTableWidgetItem;
        QTableWidgetItem *t_college = new QTableWidgetItem;
        QTableWidgetItem *t_teacher = new QTableWidgetItem;
        QTableWidgetItem *t_sel_total = new QTableWidgetItem;
        t_name->setText(my_data.v_course[i].name.toUtf8());
        t_college->setText(my_data.v_course[i].college.toUtf8());
        t_teacher->setText(my_data.v_course[i].teacher.toUtf8());
        t_sel_total->setText(QString::number(my_data.v_course[i].v_id.size())
                             + "/"
                             + QString::number(my_data.v_course[i].n_total));
        t_name->setTextAlignment(Qt::AlignCenter);
        t_college->setTextAlignment(Qt::AlignCenter);
        t_teacher->setTextAlignment(Qt::AlignCenter);
        t_sel_total->setTextAlignment(Qt::AlignCenter);
        del_lesson_table->setItem(i, 0, t_name);
        del_lesson_table->setItem(i, 1, t_college);
        del_lesson_table->setItem(i, 2, t_teacher);
        del_lesson_table->setItem(i, 3, t_sel_total);
    }
}
void StackDlg::seek_lesson_load_list()
{
    seek_lesson_list->clear();
    for (int i = 0; i != my_data.v_course.size(); ++i)
    {
        seek_lesson_list->insertItem(i, my_data.v_course[i].name.toUtf8());
    }
}
void StackDlg::clear_add_lesson()
{
    lesson_name_edit->setText("");
    collage_name_combobox->setCurrentIndex(0);
    teacher_name_edit->setText("");
    n_total_edit->setText("");
    add_lesson_isright_label->setText(tr(u8""));
}
void StackDlg::clear_del_lesson()
{
    del_lesson_isright->setText(tr(""));
}
void StackDlg::clear_edit_lesson()
{

}
void StackDlg::clear_seek_lesson()
{

}
void StackDlg::set_choose_lesson()
{
    choose_lesson_QW = new QWidget();
    choose_lesson_table = new QTableWidget();
    choose_lesson_table->setRowCount(my_data.v_course.size());
    choose_lesson_table->setColumnCount(5);
    choose_lesson_layout = new QGridLayout(choose_lesson_QW);
    choose_lesson_submit = new QPushButton(tr(u8"确定选课"));
    choose_lesson_cancel = new QPushButton(tr(u8"取消"));


    choose_lesson_table->setMaximumSize(550, 300);
    choose_lesson_table->setMinimumSize(550, 300);

    choose_lesson_layout->addWidget(choose_lesson_table, 0, 0, 1, 6);
    choose_lesson_layout->addWidget(choose_lesson_submit, 1, 4);
    choose_lesson_layout->addWidget(choose_lesson_cancel, 1, 5);

    choose_lesson_layout->setAlignment(Qt::AlignHCenter);

    choose_lesson_table->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    choose_lesson_table->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    choose_lesson_table->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    choose_lesson_table->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    choose_lesson_table->horizontalHeader()->setStretchLastSection(true);
    //choose_lesson_table->verticalHeader()->setStretchLastSection(true);
    choose_lesson_table->horizontalHeader()->setEnabled(false);
    choose_lesson_table->verticalHeader()->setEnabled(false);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << u8"课程名称" << u8"开课院系" << u8"授课教师" << u8"已选人数/总人数" << u8"选课状态";
    choose_lesson_table->setHorizontalHeaderLabels(headerLabels);

    choose_lesson_load_table();

    connect(choose_lesson_submit, SIGNAL(clicked(bool)), this, SLOT(push_choose_lesson_submit()));
    connect(choose_lesson_cancel, SIGNAL(clicked(bool)), this, SLOT(push_choose_lesson_cancel()));
}
void StackDlg::set_quit_lesson()
{
    quit_lesson_QW = new QWidget();
    quit_lesson_table = new QTableWidget();
    quit_lesson_table->setRowCount(my_data.v_course.size());
    quit_lesson_table->setColumnCount(5);
    quit_lesson_layout = new QGridLayout(quit_lesson_QW);
    quit_lesson_submit = new QPushButton(tr(u8"确定退课"));
    quit_lesson_cancel = new QPushButton(tr(u8"取消"));


    quit_lesson_table->setMaximumSize(550, 300);
    quit_lesson_table->setMinimumSize(550, 300);

    quit_lesson_layout->addWidget(quit_lesson_table, 0, 0, 1, 6);
    quit_lesson_layout->addWidget(quit_lesson_submit, 1, 4);
    quit_lesson_layout->addWidget(quit_lesson_cancel, 1, 5);

    quit_lesson_layout->setAlignment(Qt::AlignHCenter);

    quit_lesson_table->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    quit_lesson_table->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    quit_lesson_table->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    quit_lesson_table->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    quit_lesson_table->horizontalHeader()->setStretchLastSection(true);
    //quit_lesson_table->verticalHeader()->setStretchLastSection(true);
    quit_lesson_table->horizontalHeader()->setEnabled(false);
    quit_lesson_table->verticalHeader()->setEnabled(false);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << u8"课程名称" << u8"开课院系" << u8"授课教师" << u8"已选人数/总人数" << u8"选课状态";
    quit_lesson_table->setHorizontalHeaderLabels(headerLabels);

    quit_lesson_load_table();

    connect(quit_lesson_submit, SIGNAL(clicked(bool)), this, SLOT(push_quit_lesson_submit()));
    connect(quit_lesson_cancel, SIGNAL(clicked(bool)), this, SLOT(push_quit_lesson_cancel()));
}
void StackDlg::set_selected_lesson()
{
    selected_lesson_QW = new QWidget();
    selected_lesson_table = new QTableWidget();
    selected_lesson_table->setRowCount(my_data.v_course.size());
    selected_lesson_table->setColumnCount(5);
    selected_lesson_layout = new QGridLayout(selected_lesson_QW);


    selected_lesson_table->setMaximumSize(550, 300);
    selected_lesson_table->setMinimumSize(550, 300);

    selected_lesson_layout->addWidget(selected_lesson_table, 0, 0, 1, 6);
    selected_lesson_layout->setAlignment(Qt::AlignHCenter);

    selected_lesson_table->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    selected_lesson_table->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    selected_lesson_table->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    selected_lesson_table->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    selected_lesson_table->horizontalHeader()->setStretchLastSection(true);
    //selected_lesson_table->verticalHeader()->setStretchLastSection(true);
    selected_lesson_table->horizontalHeader()->setEnabled(false);
    selected_lesson_table->verticalHeader()->setEnabled(false);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << u8"课程名称" << u8"开课院系" << u8"授课教师" << u8"已选人数/总人数" << u8"选课状态";
    selected_lesson_table->setHorizontalHeaderLabels(headerLabels);

    selected_lesson_load_table();

}
void StackDlg::choose_lesson_load_table()
{
    choose_lesson_table->setRowCount(my_data.v_course.size());
    for (int i = 0; i != my_data.v_course.size(); ++i)
    {
        QTableWidgetItem *t_name = new QTableWidgetItem;
        QTableWidgetItem *t_college = new QTableWidgetItem;
        QTableWidgetItem *t_teacher = new QTableWidgetItem;
        QTableWidgetItem *t_sel_total = new QTableWidgetItem;
        QTableWidgetItem *is_selected = new QTableWidgetItem;
        t_name->setText(my_data.v_course[i].name.toUtf8());
        t_college->setText(my_data.v_course[i].college.toUtf8());
        t_teacher->setText(my_data.v_course[i].teacher.toUtf8());
        t_sel_total->setText(QString::number(my_data.v_course[i].v_id.size())
                             + "/"
                             + QString::number(my_data.v_course[i].n_total));
        if (my_data.v_course[i].v_id.contains(cur_id))
        {
            is_selected->setText(u8"已选");
            is_selected->setForeground(QBrush(QColor(255, 0, 0)));
        }
        else
        {
            is_selected->setText(u8"未选");
            is_selected->setForeground(QBrush(QColor(0, 0, 0)));
        }
        t_name->setTextAlignment(Qt::AlignCenter);
        t_college->setTextAlignment(Qt::AlignCenter);
        t_teacher->setTextAlignment(Qt::AlignCenter);
        t_sel_total->setTextAlignment(Qt::AlignCenter);
        is_selected->setTextAlignment(Qt::AlignCenter);
        choose_lesson_table->setItem(i, 0, t_name);
        choose_lesson_table->setItem(i, 1, t_college);
        choose_lesson_table->setItem(i, 2, t_teacher);
        choose_lesson_table->setItem(i, 3, t_sel_total);
        choose_lesson_table->setItem(i, 4, is_selected);
    }
}
void StackDlg::quit_lesson_load_table()
{
    quit_lesson_table->setRowCount(my_data.v_course.size());
    for (int i = 0; i != my_data.v_course.size(); ++i)
    {
        QTableWidgetItem *t_name = new QTableWidgetItem;
        QTableWidgetItem *t_college = new QTableWidgetItem;
        QTableWidgetItem *t_teacher = new QTableWidgetItem;
        QTableWidgetItem *t_sel_total = new QTableWidgetItem;
        QTableWidgetItem *is_selected = new QTableWidgetItem;
        t_name->setText(my_data.v_course[i].name.toUtf8());
        t_college->setText(my_data.v_course[i].college.toUtf8());
        t_teacher->setText(my_data.v_course[i].teacher.toUtf8());
        t_sel_total->setText(QString::number(my_data.v_course[i].v_id.size())
                             + "/"
                             + QString::number(my_data.v_course[i].n_total));
        if (my_data.v_course[i].v_id.contains(cur_id))
        {
            is_selected->setText(u8"已选");
            is_selected->setForeground(QBrush(QColor(255, 0, 0)));
        }
        else
        {
            is_selected->setText(u8"未选");
            is_selected->setForeground(QBrush(QColor(0, 0, 0)));
        }
        t_name->setTextAlignment(Qt::AlignCenter);
        t_college->setTextAlignment(Qt::AlignCenter);
        t_teacher->setTextAlignment(Qt::AlignCenter);
        t_sel_total->setTextAlignment(Qt::AlignCenter);
        is_selected->setTextAlignment(Qt::AlignCenter);
        quit_lesson_table->setItem(i, 0, t_name);
        quit_lesson_table->setItem(i, 1, t_college);
        quit_lesson_table->setItem(i, 2, t_teacher);
        quit_lesson_table->setItem(i, 3, t_sel_total);
        quit_lesson_table->setItem(i, 4, is_selected);
    }
}
void StackDlg::selected_lesson_load_table()
{
    selected_lesson_table->setRowCount(my_data.v_course.size());
    for (int i = 0; i != my_data.v_course.size(); ++i)
    {
        QTableWidgetItem *t_name = new QTableWidgetItem;
        QTableWidgetItem *t_college = new QTableWidgetItem;
        QTableWidgetItem *t_teacher = new QTableWidgetItem;
        QTableWidgetItem *t_sel_total = new QTableWidgetItem;
        QTableWidgetItem *is_selected = new QTableWidgetItem;
        t_name->setText(my_data.v_course[i].name.toUtf8());
        t_college->setText(my_data.v_course[i].college.toUtf8());
        t_teacher->setText(my_data.v_course[i].teacher.toUtf8());
        t_sel_total->setText(QString::number(my_data.v_course[i].v_id.size())
                             + "/"
                             + QString::number(my_data.v_course[i].n_total));
        if (my_data.v_course[i].v_id.contains(cur_id))
        {
            is_selected->setText(u8"已选");
            is_selected->setForeground(QBrush(QColor(255, 0, 0)));
        }
        else
        {
            is_selected->setText(u8"未选");
            is_selected->setForeground(QBrush(QColor(0, 0, 0)));
        }
        t_name->setTextAlignment(Qt::AlignCenter);
        t_college->setTextAlignment(Qt::AlignCenter);
        t_teacher->setTextAlignment(Qt::AlignCenter);
        t_sel_total->setTextAlignment(Qt::AlignCenter);
        is_selected->setTextAlignment(Qt::AlignCenter);
        selected_lesson_table->setItem(i, 0, t_name);
        selected_lesson_table->setItem(i, 1, t_college);
        selected_lesson_table->setItem(i, 2, t_teacher);
        selected_lesson_table->setItem(i, 3, t_sel_total);
        selected_lesson_table->setItem(i, 4, is_selected);
    }
}


void StackDlg::push_teacher()
{
    stack->setCurrentIndex(3);
}
void StackDlg::push_student()
{
    stack->setCurrentIndex(4);
}
void StackDlg::push_goto_start()
{
    clear_add_lesson();
    clear_del_lesson();
    clear_edit_lesson();
    clear_seek_lesson();
    stack->setCurrentIndex(0);
}
void StackDlg::push_goto_start2()
{
    cur_id = "";
    stack->setCurrentIndex(0);
}
void StackDlg::push_goto_start3()
{
    teacher_password_edit->setText("");
    teacher_password_isright->setText("");
    stack->setCurrentIndex(0);
}
void StackDlg::push_goto_start4()
{
    student_id_edit->setText("");
    student_password_edit->setText("");
    student_password_isright->setText("");
    stack->setCurrentIndex(0);
}
void StackDlg::push_goto_start5()
{
    register_name_edit->setText("");
    register_id_edit->setText("");
    register_password_edit->setText("");
    register_password2_edit->setText("");
    register_password_isright->setText("");
    stack->setCurrentIndex(4);
}
void StackDlg::push_teacher_signin()
{
    QString tmp_password = teacher_password_edit->text();
    if (tmp_password == "")
    {
        teacher_password_isright->setText(u8"密码为空！");
        return;
    }
    if (tmp_password == my_data.get_password())
    {
        stack->setCurrentIndex(1);
        teacher_password_edit->setText("");
        teacher_password_isright->setText("");
        seek_lesson_load_list();
    }
    else
        teacher_password_isright->setText(u8"密码错误，请重新输入！");
}
void StackDlg::push_student_signin()
{
    QString tmp_id = student_id_edit->text();
    QString tmp_password = student_password_edit->text();
    if (tmp_id == "")
    {
        student_password_isright->setText(u8"学号为空！");
        return;
    }
    if (tmp_password == "")
    {
        student_password_isright->setText(u8"密码为空！");
        return;
    }
    if (my_data.map_student.find(tmp_id) == my_data.map_student.end())
    {
        student_password_isright->setText(u8"该学号未注册！");
        return;
    }
    else if (tmp_password == my_data.map_student[tmp_id].password)
    {
        // 成功登录
        cur_id = tmp_id;
        student_name->setText(my_data.map_student[cur_id].name.toUtf8());
        choose_lesson_load_table();
        quit_lesson_load_table();
        selected_lesson_load_table();
        stack->setCurrentIndex(2);
        student_stack->setCurrentIndex(0);
        student_password_edit->setText("");
        student_id_edit->setText("");
        student_password_isright->setText("");
    }
    else
    {
        student_password_isright->setText(u8"密码错误，请重新输入！");
    }
}
void StackDlg::push_goto_register()
{
    student_id_edit->setText("");
    student_password_edit->setText("");
    student_password_isright->setText("");
    stack->setCurrentIndex(5);
}
void StackDlg::push_register_signin()
{
    if (register_name_edit->text() == "")
    {
        register_password_isright->setText(u8"姓名为空!");
        return;
    }
    if (my_data.map_student.find(register_id_edit->text()) != my_data.map_student.end())
    {
        register_password_isright->setText(u8"该学号已被注册!");
        return;
    }
    if (register_id_edit->text() == "")
    {
        register_password_isright->setText(u8"学号为空!");
        return;
    }
    if (register_password_edit->text() == "")
    {
        register_password_isright->setText(u8"密码为空!");
        return;
    }
    for (int i = 0; i != register_password_edit->text().size(); ++i)
    {
        if (register_password_edit->text()[i] == ' ')
        {
            register_password_isright->setText(u8"密码中不能有空格!");
            return;
        }
    }
    if (register_password_edit->text() == register_password2_edit->text())
    {
        // 成功注册
        cur_id = register_id_edit->text();

        my_data.map_student[cur_id].id = cur_id;
        my_data.map_student[cur_id].name = register_name_edit->text();
        my_data.map_student[cur_id].password = register_password_edit->text();
        my_data.save();

        student_name->setText(my_data.map_student[cur_id].name.toUtf8());
        register_name_edit->setText("");
        register_id_edit->setText("");
        register_password_edit->setText("");
        register_password2_edit->setText("");
        register_password_isright->setText("");

        choose_lesson_load_table();
        quit_lesson_load_table();
        selected_lesson_load_table();
        stack->setCurrentIndex(2);
        student_stack->setCurrentIndex(0);
    }
    else
    {
        register_password_isright->setText(u8"密码不一致!");
    }
}
void StackDlg::diff_password()
{
    if (register_password_edit->text() == register_password2_edit->text())
        register_password_isright->setText("");
    else
        register_password_isright->setText(u8"密码不一致!");
}
void StackDlg::push_add_lesson()
{
    clear_del_lesson();
    clear_edit_lesson();
    clear_seek_lesson();
    teacher_stack->setCurrentIndex(1);
}
void StackDlg::push_add_lesson_cancel()
{
    clear_add_lesson();
    teacher_stack->setCurrentIndex(0);
}
void StackDlg::push_add_lesson_submit()
{
    if (lesson_name_edit->text() == "")
    {
        add_lesson_isright_label->setText(tr(u8"课程名称为空！"));
        return;
    }
    if (collage_name_combobox->currentIndex() == 0)
    {
        add_lesson_isright_label->setText(tr(u8"请选择开课院系！"));
        return;
    }
    if (teacher_name_edit->text() == "")
    {
        add_lesson_isright_label->setText(tr(u8"教师姓名为空！"));
        return;
    }
    if (n_total_edit->text() == "")
    {
        add_lesson_isright_label->setText(tr(u8"课程人数为空！"));
        return;
    }
    if (!my_data.add_lesson(lesson_name_edit->text(),
                           teacher_name_edit->text(),
                           collage_name_combobox->currentText(),
                           n_total_edit->text().toInt()))
    {
        add_lesson_isright_label->setText(tr(u8"该老师已开设此门课程！"));
        return;
    }
    my_data.save();
    clear_add_lesson();
    choose_lesson_load_table();
    quit_lesson_load_table();
    seek_lesson_load_list();
    del_lesson_load_table();
    teacher_stack->setCurrentIndex(0);
}
void StackDlg::push_del_lesson()
{
    clear_add_lesson();
    clear_edit_lesson();
    clear_seek_lesson();
    del_lesson_table->selectRow(0);
    teacher_stack->setCurrentIndex(2);
}
void StackDlg::push_del_lesson_submit()
{

    int t_idx = del_lesson_table->currentRow();
    if (my_data.v_course[t_idx].v_id.size() != 0)
    {
        del_lesson_isright->setText(tr(u8"已经有学生选课，不能删除课程"));
        return;
    }
    clear_del_lesson();
    my_data.v_course.removeOne(my_data.v_course[t_idx]);

    my_data.save();
    seek_lesson_load_list();
    del_lesson_load_table();
}
void StackDlg::push_del_lesson_cancel()
{
    clear_del_lesson();
    teacher_stack->setCurrentIndex(0);
}
void StackDlg::push_edit_lesson()
{
    clear_add_lesson();
    clear_del_lesson();
    clear_seek_lesson();
}
void StackDlg::push_seek_lesson()
{
    clear_add_lesson();
    clear_del_lesson();
    clear_edit_lesson();
    seek_lesson_table->clear();
    seek_lesson_list->setCurrentRow(-1);
    teacher_stack->setCurrentIndex(0);
}
void StackDlg::push_choose_lesson()
{
    student_stack->setCurrentIndex(1);
    choose_lesson_table->selectRow(-1);
    choose_lesson_load_table();
}
void StackDlg::push_choose_lesson_submit()
{
    int t_idx = choose_lesson_table->currentRow();
    if (t_idx == -1)
        return;
    if (my_data.v_course[t_idx].v_id.contains(cur_id))
        return;
    my_data.v_course[t_idx].add_student(cur_id);
    my_data.map_student[cur_id].course_selceted.push_back(my_data.v_course[t_idx].name);
    my_data.save();
    choose_lesson_load_table();
    quit_lesson_load_table();
    choose_lesson_table->selectRow(-1);
}
void StackDlg::push_choose_lesson_cancel()
{
    student_stack->setCurrentIndex(0);
}
void StackDlg::push_quit_lesson()
{
    student_stack->setCurrentIndex(2);
    quit_lesson_table->selectRow(-1);
    quit_lesson_load_table();
}
void StackDlg::push_quit_lesson_submit()
{
    int t_idx = quit_lesson_table->currentRow();
    if (t_idx == -1)
        return;
    if (!my_data.v_course[t_idx].v_id.contains(cur_id))
        return;
    my_data.v_course[t_idx].del_student(cur_id);
    my_data.map_student[cur_id].course_selceted.removeOne(my_data.v_course[t_idx].name);

    my_data.save();
    choose_lesson_load_table();
    quit_lesson_load_table();
    quit_lesson_table->selectRow(-1);
}
void StackDlg::push_quit_lesson_cancel()
{
    student_stack->setCurrentIndex(0);
}
void StackDlg::push_selcected_lesson()
{
    student_stack->setCurrentIndex(0);
    selected_lesson_load_table();
}
void StackDlg::seek_lesson_load_table(int t_idx)
{
    if (t_idx == -1)
    {
        seek_lesson_table->setRowCount(0);
        return;
    }
    seek_lesson_table->setRowCount(my_data.v_course[t_idx].v_id.size());
    for (int i = 0; i != my_data.v_course[t_idx].v_id.size(); ++i)
    {
        QTableWidgetItem *t_name = new QTableWidgetItem;
        QTableWidgetItem *t_id = new QTableWidgetItem;
        t_name->setText(my_data.map_student[my_data.v_course[t_idx].v_id[i]].name.toUtf8());
        t_id->setText(my_data.v_course[t_idx].v_id[i].toUtf8());
        t_name->setTextAlignment(Qt::AlignCenter);
        t_id->setTextAlignment(Qt::AlignCenter);
        seek_lesson_table->setItem(i, 0, t_name);
        seek_lesson_table->setItem(i, 1, t_id);
    }
}

StackDlg::~StackDlg()
{

}
