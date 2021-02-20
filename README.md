# qt-signal-slot-demo
qt signals and slot demo project  ,  just for demo



建立信号连接

~~~cpp
// 标准模式
connect(信号发起者, 信号, 接受者, 槽函数);

// 项目中常用 lambda模式
// lambda表达式  [=] 这里的 = 表示该函数可以识别函数所在范围的控件
connect(信号发起者, 信号, [=](){
        qDebug() << "信号" << endl;
    });

~~~



当信号或者槽函数有重载的时候, 指定槽函数或者信号 需要使用函数指针 指明具体的信号或者函数, 如

~~~cpp
void (Teacher::*p1)(QString str) = &Teacher::hungry;
void (Student::*p2)(QString str) = &Student::treat;
connect(teacher,p1, student, p2);

~~~



emit 信号触发

~~~cpp
  emit teacher->hungry("烧烤");
~~~





