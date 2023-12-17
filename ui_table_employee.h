/********************************************************************************
** Form generated from reading UI file 'table_employee.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_EMPLOYEE_H
#define UI_TABLE_EMPLOYEE_H

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

class Ui_table_employee
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *pushButton_6;
    QComboBox *comboBox_2;

    void setupUi(QDialog *table_employee)
    {
        if (table_employee->objectName().isEmpty())
            table_employee->setObjectName("table_employee");
        table_employee->resize(692, 581);
        tableView = new QTableView(table_employee);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 661, 361));
        pushButton = new QPushButton(table_employee);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 520, 80, 24));
        pushButton_2 = new QPushButton(table_employee);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 520, 111, 24));
        pushButton_3 = new QPushButton(table_employee);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 520, 80, 24));
        pushButton_4 = new QPushButton(table_employee);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(280, 520, 80, 24));
        lineEdit = new QLineEdit(table_employee);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 400, 113, 24));
        lineEdit_2 = new QLineEdit(table_employee);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 460, 113, 24));
        lineEdit_3 = new QLineEdit(table_employee);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(510, 400, 91, 24));
        lineEdit_4 = new QLineEdit(table_employee);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(270, 400, 113, 24));
        label = new QLabel(table_employee);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 400, 21, 16));
        label_2 = new QLabel(table_employee);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 460, 61, 16));
        label_3 = new QLabel(table_employee);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 400, 31, 20));
        label_4 = new QLabel(table_employee);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 400, 41, 16));
        pushButton_5 = new QPushButton(table_employee);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(380, 520, 80, 24));
        lineEdit_5 = new QLineEdit(table_employee);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(310, 460, 71, 24));
        label_5 = new QLabel(table_employee);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 460, 61, 20));
        comboBox = new QComboBox(table_employee);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 400, 41, 24));
        pushButton_6 = new QPushButton(table_employee);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(570, 450, 80, 24));
        comboBox_2 = new QComboBox(table_employee);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(260, 460, 41, 24));

        retranslateUi(table_employee);

        QMetaObject::connectSlotsByName(table_employee);
    } // setupUi

    void retranslateUi(QDialog *table_employee)
    {
        table_employee->setWindowTitle(QCoreApplication::translate("table_employee", "\320\241\321\202\321\203\320\264\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("table_employee", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("table_employee", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("table_employee", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_4->setText(QCoreApplication::translate("table_employee", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("table_employee", "\320\232\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("table_employee", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("table_employee", "\320\246\320\265\320\275\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("table_employee", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        pushButton_5->setText(QCoreApplication::translate("table_employee", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        lineEdit_5->setText(QString());
        label_5->setText(QCoreApplication::translate("table_employee", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("table_employee", ">", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("table_employee", "<", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("table_employee", "=", nullptr));

        pushButton_6->setText(QCoreApplication::translate("table_employee", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("table_employee", ">", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("table_employee", "<", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("table_employee", "=", nullptr));

    } // retranslateUi

};

namespace Ui {
    class table_employee: public Ui_table_employee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_EMPLOYEE_H
