#ifndef HASHMAPTABLEVIEW_HPP
#define HASHMAPTABLEVIEW_HPP

#include <QDialog>

namespace Ui {
class HashMapTableView;
}

class HashMapTableView : public QDialog {
    Q_OBJECT

public:
    explicit HashMapTableView(QWidget *parent = nullptr);
    ~HashMapTableView();
private slots:
    void on_btnOk_clicked();

private:
    Ui::HashMapTableView *ui;

public:
    void setRowCount(int);
    void setDataOnTableRow(int, QString, QString, QString);
};

#endif // HASHMAPTABLEVIEW_HPP
