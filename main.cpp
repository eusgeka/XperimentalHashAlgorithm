#include <QApplication>

#include "hashmapmaingui.hpp"

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    HashMapMainGui hashMapMainGui;
    hashMapMainGui.show();

    return qApplication.exec();
}
