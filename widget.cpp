#include "widget.h"
#include<QPushButton>
#include<QDebug>
#include "student.h"
#include "teacher.h"

#define N 0

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("信号和曹示例项目");
    this->resize(600,300);

    //创建一个按钮
    QPushButton *btn1 = new QPushButton("关闭", this);
    // 单击按钮关闭主窗口
    // connect(信号发起者,信号,信号接受者,曹函数)
    connect(btn1,&QPushButton::clicked,this,&QWidget::close);

    QPushButton *btn2 = new QPushButton("拖我啊",this);
    btn2->move(300,100);// 移动按钮
    // lambda表达式  [=] 这里的 = 表示该函数可以识别函数所在范围的控件
    connect(btn2,&QPushButton::clicked,[=](){
        QString text = btn2->text();
        qDebug() << text << endl;

        btn2->setText("就拖你!");
    });


    // 自定义型号和槽
    // 实例化对象
    Teacher *teacher = new Teacher(this);
    Student *student = new Student(this); // this 表示属于当前窗口
#if N
    // 建立信号连接
   // connect(teacher, &Teacher::hungry, student, &Student::treat);
    // 函数有重载的时候需要使用函数指针来指定具体的函数, 如果不适用函数指针 &Teacher::hungry 将产生可选性
    void (Teacher::*p1)() = &Teacher::hungry;
    void (Student::*p2)() = &Student::treat;

    connect(teacher,p1, student, p2);

#else
    // 有重载函数的情况 需要使用函数指针指定具体的函数
    void (Teacher::*p1)(QString str) = &Teacher::hungry;
    void (Student::*p2)(QString str) = &Student::treat;

    connect(teacher,p1, student, p2);

#endif

    QPushButton *btn3 = new QPushButton("自定义信号槽",this);
    btn3->move(300,150);

    connect(btn3,&QPushButton::clicked,[=](){

#if N
        // 无参信号发出
        emit teacher->hungry(); // 发出信号
#else
     // 有参信号发出
     emit teacher->hungry("烧烤");
#endif

    });


}

Widget::~Widget()
{
}

