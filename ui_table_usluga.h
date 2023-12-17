/********************************************************************************
** Form generated from reading UI file 'table_usluga.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_USLUGA_H
#define UI_TABLE_USLUGA_H

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

class Ui_table_usluga
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *table_usluga)
    {
        if (table_usluga->objectName().isEmpty())
            table_usluga->setObjectName("table_usluga");
        table_usluga->resize(672, 545);
        tableView = new QTableView(table_usluga);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 651, 391));
        pushButton = new QPushButton(table_usluga);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 500, 80, 24));
        lineEdit = new QLineEdit(table_usluga);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 420, 113, 24));
        lineEdit_2 = new QLineEdit(table_usluga);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 460, 113, 24));
        lineEdit_3 = new QLineEdit(table_usluga);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(380, 420, 113, 24));
        comboBox = new QComboBox(table_usluga);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(340, 420, 41, 24));
        label = new QLabel(table_usluga);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 420, 61, 20));
        label_2 = new QLabel(table_usluga);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 460, 101, 16));
        label_3 = new QLabel(table_usluga);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 420, 101, 20));
        pushButton_2 = new QPushButton(table_usluga);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 500, 80, 24));
        pushButton_3 = new QPushButton(table_usluga);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(370, 500, 80, 24));
        pushButton_4 = new QPushButton(table_usluga);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(470, 500, 80, 24));
        pushButton_5 = new QPushButton(table_usluga);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(570, 460, 80, 24));
        pushButton_6 = new QPushButton(table_usluga);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(470, 460, 80, 24));

        retranslateUi(table_usluga);

        QMetaObject::connectSlotsByName(table_usluga);
    } // setupUi

    void retranslateUi(QDialog *table_usluga)
    {
        table_usluga->setWindowTitle(QCoreApplication::translate("table_usluga", "\320\243\321\201\320\273\321\203\320\263\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("table_usluga", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("table_usluga", ">", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("table_usluga", "<", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("table_usluga", "=", nullptr));

        label->setText(QCoreApplication::translate("table_usluga", "\320\232\320\276\320\264 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("table_usluga", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("table_usluga", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        pushButton_2->setText(QCoreApplication::translate("table_usluga", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("table_usluga", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("table_usluga", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("table_usluga", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        pushButton_6->setText(QCoreApplication::translate("table_usluga", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_usluga: public Ui_table_usluga {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_USLUGA_H
