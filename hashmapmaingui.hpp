#ifndef HASHMAPMAINGUI_HPP
#define HASHMAPMAINGUI_HPP

#include <QMainWindow>

#include "unordermap.hpp"

namespace Ui {
class HashMapMainGui;
}

class HashMapMainGui : public QMainWindow
{
    Q_OBJECT
private:
    UnOrderMap m_hMap;


public:
    explicit HashMapMainGui(QWidget *parent = nullptr);
    ~HashMapMainGui();

private slots:
    void on_lnEdtFirstName_editingFinished();

    void on_lnEdtLastName_editingFinished();

    void on_btnInsert_clicked();

private:
    Ui::HashMapMainGui *ui;
};

#endif // HASHMAPMAINGUI_HPP
