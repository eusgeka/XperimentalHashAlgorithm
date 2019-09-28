#include "hashmapmaingui.hpp"
#include "ui_hashmapmaingui.h"

HashMapMainGui::HashMapMainGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HashMapMainGui) {
    ui->setupUi(this);
}

HashMapMainGui::~HashMapMainGui() {
    delete ui;
}

void HashMapMainGui::on_lnEdtFirstName_editingFinished() {

}

void HashMapMainGui::on_lnEdtLastName_editingFinished() {

}

void HashMapMainGui::on_btnInsert_clicked() {
    m_hMap.add(ui->lnEdtFirstName->text().toUtf8().constData(), ui->lnEdtLastName->text().toUtf8().constData());
    ui->lnEdtFirstName->clear();
    ui->lnEdtLastName->clear();
}
