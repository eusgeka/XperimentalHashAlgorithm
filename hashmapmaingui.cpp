#include "hashmapmaingui.hpp"
#include "ui_hashmapmaingui.h"

#include "hashmaptableview.hpp"

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

void HashMapMainGui::on_btnShowMap_clicked() {
    HashMapTableView hashMapTableView;
    int index = 0;
    hashMapTableView.setRowCount(static_cast<int>(m_hMap.m_hMap.size()));
    for (auto it = m_hMap.m_hMap.begin(); it != m_hMap.m_hMap.end(); ++it) {
        Key key = it->first;
        std::pair<std::string, std::string> pair = it->second;
        QString hashValue = QString::number(key.getThird());
        QString firstName = QString::fromUtf8(pair.first.c_str());
        QString lastName = QString::fromUtf8(pair.second.c_str());
        hashMapTableView.setDataOnTableRow(index++, hashValue, firstName, lastName);
    }
    hashMapTableView.exec();
}
