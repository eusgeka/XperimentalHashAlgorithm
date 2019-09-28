#include <QApplication>

#include "hashmapmaingui.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HashMapMainGui w;
    w.show();

    return a.exec();
}
