#include "stackdlg.h"
#include "data.h"
#include "data.cpp"
#include <QFile>
#include <QApplication>
#include <QSplitter>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include <QTextCodec>



int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("u8"));
    QApplication a(argc, argv);
    StackDlg w;
    w.setMinimumSize(800, 450);
    w.setMaximumSize(800, 450);
    w.show();

    return a.exec();
}
