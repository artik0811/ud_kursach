/********************************************************************************
** Form generated from reading UI file 'table_client.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_CLIENT_H
#define UI_TABLE_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_table_client
{
public:
    QTableView *tableView;
    QPushButton *pushButton_back;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_fio;
    QLineEdit *lineEdit_mail;
    QLineEdit *lineEdit_phone;
    QComboBox *comboBox_sex;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_add;
    QPushButton *pushButton_change;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_find;
    QPushButton *pushButton_reset;
    QCheckBox *checkBox;

    void setupUi(QDialog *table_client)
    {
        if (table_client->objectName().isEmpty())
            table_client->setObjectName("table_client");
        table_client->resize(743, 517);
        tableView = new QTableView(table_client);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 461, 491));
        pushButton_back = new QPushButton(table_client);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(640, 470, 80, 24));
        lineEdit_id = new QLineEdit(table_client);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(580, 40, 113, 24));
        lineEdit_fio = new QLineEdit(table_client);
        lineEdit_fio->setObjectName("lineEdit_fio");
        lineEdit_fio->setGeometry(QRect(580, 90, 113, 24));
        lineEdit_mail = new QLineEdit(table_client);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(580, 190, 113, 24));
        lineEdit_phone = new QLineEdit(table_client);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(580, 140, 113, 24));
        comboBox_sex = new QComboBox(table_client);
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->setObjectName("comboBox_sex");
        comboBox_sex->setGeometry(QRect(580, 240, 41, 24));
        label = new QLabel(table_client);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 40, 21, 21));
        label_2 = new QLabel(table_client);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(540, 90, 31, 21));
        label_3 = new QLabel(table_client);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 140, 49, 21));
        label_4 = new QLabel(table_client);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 190, 41, 21));
        label_5 = new QLabel(table_client);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(540, 240, 31, 16));
        pushButton_add = new QPushButton(table_client);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(490, 300, 231, 24));
        pushButton_change = new QPushButton(table_client);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(490, 380, 231, 24));
        pushButton_delete = new QPushButton(table_client);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(490, 420, 231, 24));
        pushButton_find = new QPushButton(table_client);
        pushButton_find->setObjectName("pushButton_find");
        pushButton_find->setGeometry(QRect(490, 340, 231, 24));
        pushButton_reset = new QPushButton(table_client);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(490, 470, 80, 24));
        checkBox = new QCheckBox(table_client);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(630, 240, 101, 22));

        retranslateUi(table_client);

        QMetaObject::connectSlotsByName(table_client);
    } // setupUi

    void retranslateUi(QDialog *table_client)
    {
        table_client->setWindowTitle(QCoreApplication::translate("table_client", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        pushButton_back->setText(QCoreApplication::translate("table_client", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        comboBox_sex->setItemText(0, QCoreApplication::translate("table_client", "\320\274", nullptr));
        comboBox_sex->setItemText(1, QCoreApplication::translate("table_client", "\320\266", nullptr));

        label->setText(QCoreApplication::translate("table_client", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("table_client", "\320\244\320\230\320\236", nullptr));
        label_3->setText(QCoreApplication::translate("table_client", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("table_client", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("table_client", "\320\237\320\276\320\273", nullptr));
        pushButton_add->setText(QCoreApplication::translate("table_client", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_change->setText(QCoreApplication::translate("table_client", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("table_client", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_find->setText(QCoreApplication::translate("table_client", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("table_client", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        checkBox->setText(QCoreApplication::translate("table_client", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\277\320\276\320\273\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_client: public Ui_table_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_CLIENT_H
