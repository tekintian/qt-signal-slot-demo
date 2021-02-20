#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication应用程序类 初始化我们的应用程序
    QApplication a(argc, argv);

    // 创建一个主窗口控件
    Widget w;

    // 显示一个窗口, 窗口默认是隐藏的
    w.show();

    // 主事件循环 待阻塞 等待用户操作界面
    return a.exec();

}

