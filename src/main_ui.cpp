#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include<string>
#include <unordered_set>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return 0;
}
