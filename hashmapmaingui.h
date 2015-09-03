#ifndef HASHMAPMAINGUI_H
#define HASHMAPMAINGUI_H

#include <QMainWindow>

#include "unordermap.h"

namespace Ui {
class HashMapMainGui;
}

class HashMapMainGui : public QMainWindow
{
    Q_OBJECT
private:
    UnOrderMap m_hMap;


public:
    explicit HashMapMainGui(QWidget *parent = 0);
    ~HashMapMainGui();

private slots:
    void on_lnEdtFirstName_editingFinished();

    void on_lnEdtLastName_editingFinished();

    void on_btnInsert_clicked();

private:
    Ui::HashMapMainGui *ui;
};

#endif // HASHMAPMAINGUI_H
