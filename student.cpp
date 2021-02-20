#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<< "请吃饭!!" <<endl;
}

void Student::treat(QString str)
{
    qDebug()<< "请吃"<< str <<endl;
}
