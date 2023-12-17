/********************************************************************************
** Form generated from reading UI file 'table_dop_obor.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_DOP_OBOR_H
#define UI_TABLE_DOP_OBOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_table_dop_obor
{
public:
    QTableView *tableView;
    QPushButton *pushButton_back;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_price;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_change;
    QPushButton *pushButton_find;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_delete;

    void setupUi(QDialog *table_dop_obor)
    {
        if (table_dop_obor->objectName().isEmpty())
            table_dop_obor->setObjectName("table_dop_obor");
        table_dop_obor->resize(869, 535);
        tableView = new QTableView(table_dop_obor);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 551, 511));
        pushButton_back = new QPushButton(table_dop_obor);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(760, 490, 80, 24));
        lineEdit_id = new QLineEdit(table_dop_obor);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(702, 30, 141, 24));
        lineEdit_name = new QLineEdit(table_dop_obor);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(702, 80, 141, 24));
        lineEdit_price = new QLineEdit(table_dop_obor);
        lineEdit_price->setObjectName("lineEdit_price");
        lineEdit_price->setGeometry(QRect(702, 130, 141, 24));
        label = new QLabel(table_dop_obor);
        label->setObjectName("label");
        label->setGeometry(QRect(590, 30, 31, 21));
        label_2 = new QLabel(table_dop_obor);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(590, 80, 61, 20));
        label_3 = new QLabel(table_dop_obor);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(590, 130, 49, 16));
        comboBox = new QComboBox(table_dop_obor);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(650, 130, 51, 24));
        pushButton = new QPushButton(table_dop_obor);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(589, 190, 251, 24));
        pushButton_change = new QPushButton(table_dop_obor);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(589, 230, 251, 24));
        pushButton_find = new QPushButton(table_dop_obor);
        pushButton_find->setObjectName("pushButton_find");
        pushButton_find->setGeometry(QRect(590, 270, 251, 24));
        pushButton_reset = new QPushButton(table_dop_obor);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(590, 490, 80, 24));
        pushButton_delete = new QPushButton(table_dop_obor);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(590, 310, 251, 24));

        retranslateUi(table_dop_obor);

        QMetaObject::connectSlotsByName(table_dop_obor);
    } // setupUi

    void retranslateUi(QDialog *table_dop_obor)
    {
        table_dop_obor->setWindowTitle(QCoreApplication::translate("table_dop_obor", "\320\224\320\276\320\277 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_back->setText(QCoreApplication::translate("table_dop_obor", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("table_dop_obor", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("table_dop_obor", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_3->setText(QCoreApplication::translate("table_dop_obor", "\320\246\320\265\320\275\320\260:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("table_dop_obor", ">", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("table_dop_obor", "<", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("table_dop_obor", "=", nullptr));

        pushButton->setText(QCoreApplication::translate("table_dop_obor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_change->setText(QCoreApplication::translate("table_dop_obor", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_find->setText(QCoreApplication::translate("table_dop_obor", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("table_dop_obor", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("table_dop_obor", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_dop_obor: public Ui_table_dop_obor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_DOP_OBOR_H
