#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT //支持型号和曹机制
        public:
        explicit Teacher(QObject *parent = nullptr);

signals: //定义信号的规则:  返回值类型为void  只需什么  不用实现  可以有参数 可以重载
    void hungry();
    void hungry(QString str);

public slots:// 自定义槽函数


};

#endif // TEACHER_H
