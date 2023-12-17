/********************************************************************************
** Form generated from reading UI file 'table_zakaz.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_ZAKAZ_H
#define UI_TABLE_ZAKAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_table_zakaz
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_reset;
    QLineEdit *lineEdit_idzakaz;
    QLabel *label_id_zakaz;
    QLabel *label_id_count;
    QLineEdit *lineEdit_count;
    QDateEdit *dateEdit_first;
    QLabel *label_5;
    QLineEdit *lineEdit_sum_price;
    QLabel *label_6;
    QLineEdit *lineEdit_link;
    QLineEdit *lineEdit_comment;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *checkBox;
    QPushButton *pushButton_find;
    QPushButton *pushButton_change;
    QPushButton *pushButton_add;
    QComboBox *comboBox;
    QComboBox *comboBox_sum;
    QLabel *label;
    QDateEdit *dateEdit_last;
    QComboBox *comboBox_client;
    QLabel *label_id_client;
    QComboBox *comboBox_uslug;
    QComboBox *comboBox_studia;
    QComboBox *comboBox_sotr;
    QLabel *label_id_sotr;
    QLabel *label_id_stud;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QToolButton *toolButton;

    void setupUi(QDialog *table_zakaz)
    {
        if (table_zakaz->objectName().isEmpty())
            table_zakaz->setObjectName("table_zakaz");
        table_zakaz->resize(1013, 712);
        tableView = new QTableView(table_zakaz);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 991, 441));
        pushButton = new QPushButton(table_zakaz);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(839, 670, 151, 24));
        pushButton_reset = new QPushButton(table_zakaz);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(840, 640, 151, 24));
        lineEdit_idzakaz = new QLineEdit(table_zakaz);
        lineEdit_idzakaz->setObjectName("lineEdit_idzakaz");
        lineEdit_idzakaz->setGeometry(QRect(102, 470, 121, 24));
        label_id_zakaz = new QLabel(table_zakaz);
        label_id_zakaz->setObjectName("label_id_zakaz");
        label_id_zakaz->setGeometry(QRect(20, 470, 61, 21));
        label_id_count = new QLabel(table_zakaz);
        label_id_count->setObjectName("label_id_count");
        label_id_count->setGeometry(QRect(20, 510, 71, 21));
        lineEdit_count = new QLineEdit(table_zakaz);
        lineEdit_count->setObjectName("lineEdit_count");
        lineEdit_count->setGeometry(QRect(142, 510, 81, 24));
        dateEdit_first = new QDateEdit(table_zakaz);
        dateEdit_first->setObjectName("dateEdit_first");
        dateEdit_first->setGeometry(QRect(110, 630, 110, 25));
        label_5 = new QLabel(table_zakaz);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 550, 61, 21));
        lineEdit_sum_price = new QLineEdit(table_zakaz);
        lineEdit_sum_price->setObjectName("lineEdit_sum_price");
        lineEdit_sum_price->setGeometry(QRect(432, 550, 81, 24));
        label_6 = new QLabel(table_zakaz);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 550, 49, 21));
        lineEdit_link = new QLineEdit(table_zakaz);
        lineEdit_link->setObjectName("lineEdit_link");
        lineEdit_link->setGeometry(QRect(102, 550, 121, 24));
        lineEdit_comment = new QLineEdit(table_zakaz);
        lineEdit_comment->setObjectName("lineEdit_comment");
        lineEdit_comment->setGeometry(QRect(102, 590, 121, 24));
        label_7 = new QLabel(table_zakaz);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 590, 81, 20));
        label_8 = new QLabel(table_zakaz);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 630, 81, 21));
        checkBox = new QCheckBox(table_zakaz);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(690, 550, 201, 21));
        pushButton_find = new QPushButton(table_zakaz);
        pushButton_find->setObjectName("pushButton_find");
        pushButton_find->setGeometry(QRect(850, 470, 151, 24));
        pushButton_change = new QPushButton(table_zakaz);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(690, 510, 151, 24));
        pushButton_add = new QPushButton(table_zakaz);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(690, 470, 150, 24));
        comboBox = new QComboBox(table_zakaz);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(100, 510, 41, 24));
        comboBox_sum = new QComboBox(table_zakaz);
        comboBox_sum->addItem(QString());
        comboBox_sum->addItem(QString());
        comboBox_sum->addItem(QString());
        comboBox_sum->setObjectName("comboBox_sum");
        comboBox_sum->setGeometry(QRect(390, 550, 41, 24));
        label = new QLabel(table_zakaz);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 670, 21, 21));
        dateEdit_last = new QDateEdit(table_zakaz);
        dateEdit_last->setObjectName("dateEdit_last");
        dateEdit_last->setGeometry(QRect(110, 670, 110, 25));
        comboBox_client = new QComboBox(table_zakaz);
        comboBox_client->setObjectName("comboBox_client");
        comboBox_client->setGeometry(QRect(390, 590, 121, 24));
        label_id_client = new QLabel(table_zakaz);
        label_id_client->setObjectName("label_id_client");
        label_id_client->setGeometry(QRect(310, 590, 71, 21));
        comboBox_uslug = new QComboBox(table_zakaz);
        comboBox_uslug->setObjectName("comboBox_uslug");
        comboBox_uslug->setGeometry(QRect(390, 510, 241, 24));
        comboBox_studia = new QComboBox(table_zakaz);
        comboBox_studia->setObjectName("comboBox_studia");
        comboBox_studia->setGeometry(QRect(390, 470, 241, 24));
        comboBox_sotr = new QComboBox(table_zakaz);
        comboBox_sotr->setObjectName("comboBox_sotr");
        comboBox_sotr->setGeometry(QRect(390, 630, 121, 24));
        label_id_sotr = new QLabel(table_zakaz);
        label_id_sotr->setObjectName("label_id_sotr");
        label_id_sotr->setGeometry(QRect(310, 630, 71, 21));
        label_id_stud = new QLabel(table_zakaz);
        label_id_stud->setObjectName("label_id_stud");
        label_id_stud->setGeometry(QRect(310, 470, 71, 21));
        label_2 = new QLabel(table_zakaz);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 510, 71, 21));
        label_3 = new QLabel(table_zakaz);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 590, 111, 21));
        label_4 = new QLabel(table_zakaz);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 630, 111, 21));
        label_9 = new QLabel(table_zakaz);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(640, 510, 51, 21));
        label_10 = new QLabel(table_zakaz);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(640, 470, 51, 21));
        toolButton = new QToolButton(table_zakaz);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(520, 550, 31, 24));

        retranslateUi(table_zakaz);

        QMetaObject::connectSlotsByName(table_zakaz);
    } // setupUi

    void retranslateUi(QDialog *table_zakaz)
    {
        table_zakaz->setWindowTitle(QCoreApplication::translate("table_zakaz", "\320\227\320\260\320\272\320\260\320\267", nullptr));
        pushButton->setText(QCoreApplication::translate("table_zakaz", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("table_zakaz", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        label_id_zakaz->setText(QCoreApplication::translate("table_zakaz", "ID \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label_id_count->setText(QCoreApplication::translate("table_zakaz", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("table_zakaz", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("table_zakaz", "\320\241\321\201\321\213\320\273\320\272\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("table_zakaz", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        label_8->setText(QCoreApplication::translate("table_zakaz", "\320\224\320\260\321\202\320\260           \321\201", nullptr));
        checkBox->setText(QCoreApplication::translate("table_zakaz", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\264\320\260\321\202\320\265/\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\321\202\321\213", nullptr));
        pushButton_find->setText(QCoreApplication::translate("table_zakaz", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_change->setText(QCoreApplication::translate("table_zakaz", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_add->setText(QCoreApplication::translate("table_zakaz", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("table_zakaz", "=", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("table_zakaz", ">", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("table_zakaz", "<", nullptr));

        comboBox_sum->setItemText(0, QCoreApplication::translate("table_zakaz", "=", nullptr));
        comboBox_sum->setItemText(1, QCoreApplication::translate("table_zakaz", ">", nullptr));
        comboBox_sum->setItemText(2, QCoreApplication::translate("table_zakaz", "<", nullptr));

        label->setText(QCoreApplication::translate("table_zakaz", "\320\264\320\276", nullptr));
        label_id_client->setText(QCoreApplication::translate("table_zakaz", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        label_id_sotr->setText(QCoreApplication::translate("table_zakaz", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272", nullptr));
        label_id_stud->setText(QCoreApplication::translate("table_zakaz", "\320\241\321\202\321\203\320\264\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("table_zakaz", "\320\243\321\201\320\273\321\203\320\263\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("table_zakaz", "ID: ", nullptr));
        label_4->setText(QCoreApplication::translate("table_zakaz", "ID: ", nullptr));
        label_9->setText(QCoreApplication::translate("table_zakaz", "ID: ", nullptr));
        label_10->setText(QCoreApplication::translate("table_zakaz", "ID: ", nullptr));
        toolButton->setText(QCoreApplication::translate("table_zakaz", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_zakaz: public Ui_table_zakaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_ZAKAZ_H
