/********************************************************************************
** Form generated from reading UI file 'table_bron_obor.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_BRON_OBOR_H
#define UI_TABLE_BRON_OBOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_table_bron_obor
{
public:
    QPushButton *pushButton_back;
    QTableView *tableView;
    QPushButton *pushButton_reset;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_name;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_find;

    void setupUi(QDialog *table_bron_obor)
    {
        if (table_bron_obor->objectName().isEmpty())
            table_bron_obor->setObjectName("table_bron_obor");
        table_bron_obor->resize(598, 507);
        pushButton_back = new QPushButton(table_bron_obor);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(500, 460, 80, 24));
        tableView = new QTableView(table_bron_obor);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 351, 481));
        pushButton_reset = new QPushButton(table_bron_obor);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(390, 460, 80, 24));
        lineEdit_id = new QLineEdit(table_bron_obor);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(470, 40, 113, 24));
        lineEdit_name = new QLineEdit(table_bron_obor);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(470, 90, 113, 24));
        label = new QLabel(table_bron_obor);
        label->setObjectName("label");
        label->setGeometry(QRect(398, 40, 61, 20));
        label_2 = new QLabel(table_bron_obor);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(398, 90, 61, 20));
        pushButton_find = new QPushButton(table_bron_obor);
        pushButton_find->setObjectName("pushButton_find");
        pushButton_find->setGeometry(QRect(390, 240, 191, 24));

        retranslateUi(table_bron_obor);

        QMetaObject::connectSlotsByName(table_bron_obor);
    } // setupUi

    void retranslateUi(QDialog *table_bron_obor)
    {
        table_bron_obor->setWindowTitle(QCoreApplication::translate("table_bron_obor", "\320\221\321\200\320\276\320\275\321\214 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        pushButton_back->setText(QCoreApplication::translate("table_bron_obor", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("table_bron_obor", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        label->setText(QCoreApplication::translate("table_bron_obor", "ID \320\261\321\200\320\276\320\275\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("table_bron_obor", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_find->setText(QCoreApplication::translate("table_bron_obor", "\320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_bron_obor: public Ui_table_bron_obor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_BRON_OBOR_H
