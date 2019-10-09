#include "hashmaptableview.hpp"
#include "ui_hashmaptableview.h"

HashMapTableView::HashMapTableView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HashMapTableView) {
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | windowFlags());

//    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->verticalHeader()->setVisible(false);
    QStringList qStringList;
    qStringList.append("  Id (Hash value) ");
    qStringList.append("  First Name ");
    qStringList.append("  Last Name ");
    ui->tableWidget->setHorizontalHeaderLabels(qStringList);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

HashMapTableView::~HashMapTableView() {
    delete this->ui;
}

void HashMapTableView::on_btnOk_clicked() {
    this->close();
}

void HashMapTableView::setRowCount(int rowCount) {
    this->ui->tableWidget->setRowCount(rowCount);
}

void HashMapTableView::setDataOnTableRow(int index, QString id, QString firstName, QString lastName) {
    this->ui->tableWidget->setItem(index, 0, new QTableWidgetItem(id));
    this->ui->tableWidget->setItem(index, 1, new QTableWidgetItem(firstName));
    this->ui->tableWidget->setItem(index, 2, new QTableWidgetItem(lastName));
}
