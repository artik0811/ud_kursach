/********************************************************************************
** Form generated from reading UI file 'table_brron.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_BRRON_H
#define UI_TABLE_BRRON_H

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

QT_BEGIN_NAMESPACE

class Ui_table_brron
{
public:
    QTableView *tableView;
    QPushButton *pushButton_back;
    QCheckBox *checkBox_actualBroni;
    QPushButton *pushButton_find;
    QPushButton *pushButton_add;
    QPushButton *pushButton_change;
    QLineEdit *lineEdit_id_bron;
    QLabel *label;
    QLineEdit *lineEdit_fio;
    QLabel *label_2;
    QComboBox *comboBox_status;
    QComboBox *comboBox_studia;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QCheckBox *checkBox;
    QDateEdit *dateEdit_2;
    QLabel *label_4;
    QPushButton *pushButton_reset;

    void setupUi(QDialog *table_brron)
    {
        if (table_brron->objectName().isEmpty())
            table_brron->setObjectName("table_brron");
        table_brron->resize(918, 634);
        tableView = new QTableView(table_brron);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 891, 481));
        pushButton_back = new QPushButton(table_brron);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(830, 600, 80, 24));
        checkBox_actualBroni = new QCheckBox(table_brron);
        checkBox_actualBroni->setObjectName("checkBox_actualBroni");
        checkBox_actualBroni->setGeometry(QRect(140, 600, 141, 22));
        pushButton_find = new QPushButton(table_brron);
        pushButton_find->setObjectName("pushButton_find");
        pushButton_find->setGeometry(QRect(50, 600, 80, 24));
        pushButton_add = new QPushButton(table_brron);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(390, 600, 131, 24));
        pushButton_change = new QPushButton(table_brron);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(539, 600, 131, 24));
        lineEdit_id_bron = new QLineEdit(table_brron);
        lineEdit_id_bron->setObjectName("lineEdit_id_bron");
        lineEdit_id_bron->setGeometry(QRect(50, 510, 113, 24));
        label = new QLabel(table_brron);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 510, 21, 21));
        lineEdit_fio = new QLineEdit(table_brron);
        lineEdit_fio->setObjectName("lineEdit_fio");
        lineEdit_fio->setGeometry(QRect(50, 550, 113, 24));
        label_2 = new QLabel(table_brron);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 550, 31, 21));
        comboBox_status = new QComboBox(table_brron);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName("comboBox_status");
        comboBox_status->setGeometry(QRect(480, 550, 111, 24));
        comboBox_studia = new QComboBox(table_brron);
        comboBox_studia->addItem(QString());
        comboBox_studia->setObjectName("comboBox_studia");
        comboBox_studia->setGeometry(QRect(480, 510, 111, 24));
        label_5 = new QLabel(table_brron);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 510, 49, 21));
        label_6 = new QLabel(table_brron);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(410, 550, 49, 16));
        dateEdit = new QDateEdit(table_brron);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(260, 510, 110, 25));
        pushButton = new QPushButton(table_brron);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(770, 510, 131, 24));
        label_3 = new QLabel(table_brron);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 510, 71, 21));
        checkBox = new QCheckBox(table_brron);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(210, 570, 171, 22));
        dateEdit_2 = new QDateEdit(table_brron);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(260, 540, 110, 25));
        label_4 = new QLabel(table_brron);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 540, 21, 21));
        pushButton_reset = new QPushButton(table_brron);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(680, 600, 121, 24));

        retranslateUi(table_brron);

        QMetaObject::connectSlotsByName(table_brron);
    } // setupUi

    void retranslateUi(QDialog *table_brron)
    {
        table_brron->setWindowTitle(QCoreApplication::translate("table_brron", "\320\221\321\200\320\276\320\275\321\214", nullptr));
        pushButton_back->setText(QCoreApplication::translate("table_brron", " \320\235\320\260\320\267\320\260\320\264", nullptr));
        checkBox_actualBroni->setText(QCoreApplication::translate("table_brron", "\320\237\321\200\320\265\320\264\321\201\321\202\320\276\321\217\321\211\320\270\320\265 \320\261\321\200\320\276\320\275\320\270", nullptr));
        pushButton_find->setText(QCoreApplication::translate("table_brron", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_add->setText(QCoreApplication::translate("table_brron", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\261\321\200\320\276\320\275\321\214", nullptr));
        pushButton_change->setText(QCoreApplication::translate("table_brron", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\321\203\321\201", nullptr));
        label->setText(QCoreApplication::translate("table_brron", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("table_brron", "\320\244\320\230\320\236:", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("table_brron", "---", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("table_brron", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275", nullptr));
        comboBox_status->setItemText(2, QCoreApplication::translate("table_brron", "\320\235\320\265 \320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275", nullptr));
        comboBox_status->setItemText(3, QCoreApplication::translate("table_brron", "\320\236\321\202\320\274\320\265\320\275\320\265\320\275", nullptr));

        comboBox_studia->setItemText(0, QCoreApplication::translate("table_brron", "---", nullptr));

        label_5->setText(QCoreApplication::translate("table_brron", "\320\241\321\202\321\203\320\264\320\270\321\217:", nullptr));
        label_6->setText(QCoreApplication::translate("table_brron", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        pushButton->setText(QCoreApplication::translate("table_brron", "\320\221\321\200\320\276\320\275\321\214 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("table_brron", "\320\224\320\260\321\202\320\260:          c", nullptr));
        checkBox->setText(QCoreApplication::translate("table_brron", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\264\320\260\321\202\320\265/\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("table_brron", "\320\264\320\276", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("table_brron", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_brron: public Ui_table_brron {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_BRRON_H
