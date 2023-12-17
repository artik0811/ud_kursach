/********************************************************************************
** Form generated from reading UI file 'table_login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_LOGIN_H
#define UI_TABLE_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_table_login
{
public:
    QTableView *tableView;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *backButton;
    QPushButton *findButton;
    QPushButton *changeButton;
    QLineEdit *lineEdit_role;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *table_login)
    {
        if (table_login->objectName().isEmpty())
            table_login->setObjectName("table_login");
        table_login->resize(574, 503);
        tableView = new QTableView(table_login);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 281, 481));
        lineEdit_login = new QLineEdit(table_login);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(300, 60, 261, 24));
        lineEdit_password = new QLineEdit(table_login);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(302, 120, 261, 24));
        label = new QLabel(table_login);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 30, 49, 21));
        label_2 = new QLabel(table_login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 100, 49, 16));
        backButton = new QPushButton(table_login);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(300, 460, 261, 24));
        findButton = new QPushButton(table_login);
        findButton->setObjectName("findButton");
        findButton->setGeometry(QRect(300, 260, 261, 24));
        changeButton = new QPushButton(table_login);
        changeButton->setObjectName("changeButton");
        changeButton->setGeometry(QRect(300, 300, 261, 24));
        lineEdit_role = new QLineEdit(table_login);
        lineEdit_role->setObjectName("lineEdit_role");
        lineEdit_role->setGeometry(QRect(302, 180, 261, 24));
        label_3 = new QLabel(table_login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 160, 31, 16));
        pushButton = new QPushButton(table_login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 360, 80, 24));

        retranslateUi(table_login);

        QMetaObject::connectSlotsByName(table_login);
    } // setupUi

    void retranslateUi(QDialog *table_login)
    {
        table_login->setWindowTitle(QCoreApplication::translate("table_login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label->setText(QCoreApplication::translate("table_login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("table_login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("table_login", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        findButton->setText(QCoreApplication::translate("table_login", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        changeButton->setText(QCoreApplication::translate("table_login", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("table_login", "\320\240\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("table_login", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_login: public Ui_table_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_LOGIN_H
