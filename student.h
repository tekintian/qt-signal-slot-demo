#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);


signals:// 自定义信号函数
    //定义信号的规则:  返回值类型为void  只需什么  不用实现  可以有参数 可以重载

public slots:// 自定义槽函数
    // 返回值类型为 void   需要声明  需要实现  可以有参数  可以重载
    void treat();
    void treat(QString str);

};

#endif // STUDENT_H
