#include "smart.h"
#include "b.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    b w;
    w.show();
    return a.exec();
}
