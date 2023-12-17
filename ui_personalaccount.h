/********************************************************************************
** Form generated from reading UI file 'personalaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALACCOUNT_H
#define UI_PERSONALACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PersonalAccount
{
public:
    QLineEdit *PhoneLine;
    QLineEdit *MailLine;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_otmena;
    QLineEdit *lineEdit;
    QLabel *label_12;

    void setupUi(QDialog *PersonalAccount)
    {
        if (PersonalAccount->objectName().isEmpty())
            PersonalAccount->setObjectName("PersonalAccount");
        PersonalAccount->resize(1072, 419);
        PersonalAccount->setAutoFillBackground(false);
        PersonalAccount->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50)"));
        PhoneLine = new QLineEdit(PersonalAccount);
        PhoneLine->setObjectName("PhoneLine");
        PhoneLine->setGeometry(QRect(130, 140, 113, 24));
        PhoneLine->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color: rgb(255,255,255) }"));
        MailLine = new QLineEdit(PersonalAccount);
        MailLine->setObjectName("MailLine");
        MailLine->setGeometry(QRect(130, 180, 113, 24));
        MailLine->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color: rgb(255,255,255) }"));
        label = new QLabel(PersonalAccount);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 100, 49, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_2 = new QLabel(PersonalAccount);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 140, 49, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_3 = new QLabel(PersonalAccount);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 180, 49, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        pushButton = new QPushButton(PersonalAccount);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 350, 80, 24));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
"    color: #fff;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #000000;\n"
"    background-color: rgb(170,170,170);\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #111;\n"
"    background: #fff;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(PersonalAccount);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 350, 80, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
"    color: #fff;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #000000;\n"
"    background-color: rgb(170,170,170);\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #111;\n"
"    background: #fff;\n"
"}\n"
""));
        label_4 = new QLabel(PersonalAccount);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 20, 131, 16));
        QFont font;
        font.setPointSize(12);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_5 = new QLabel(PersonalAccount);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 230, 49, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_6 = new QLabel(PersonalAccount);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 280, 121, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_7 = new QLabel(PersonalAccount);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(120, 60, 91, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_8 = new QLabel(PersonalAccount);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 320, 71, 16));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_9 = new QLabel(PersonalAccount);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(660, 10, 121, 16));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        tableView = new QTableView(PersonalAccount);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(370, 40, 661, 321));
        tableView->setStyleSheet(QString::fromUtf8("QHeaderView {\n"
"    background-color:  rgb(50,50,50);\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    color: #fff;\n"
"    background-color: rgb(50,50,50);\n"
" }\n"
" QTableView {\n"
"    color:#fff;\n"
" }"));
        pushButton_3 = new QPushButton(PersonalAccount);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(379, 380, 91, 24));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
"    color: #fff;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #000000;\n"
"    background-color: rgb(170,170,170);\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #111;\n"
"    background: #fff;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(PersonalAccount);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(490, 380, 91, 24));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
"    color: #fff;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #000000;\n"
"    background-color: rgb(170,170,170);\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #111;\n"
"    background: #fff;\n"
"}\n"
""));
        label_10 = new QLabel(PersonalAccount);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(130, 100, 121, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        label_11 = new QLabel(PersonalAccount);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(130, 230, 121, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));
        pushButton_otmena = new QPushButton(PersonalAccount);
        pushButton_otmena->setObjectName("pushButton_otmena");
        pushButton_otmena->setGeometry(QRect(950, 380, 80, 24));
        pushButton_otmena->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
"    color: #fff;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #000000;\n"
"    background-color: rgb(170,170,170);\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #111;\n"
"    background: #fff;\n"
"}\n"
""));
        lineEdit = new QLineEdit(PersonalAccount);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(810, 380, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color: rgb(255,255,255) }"));
        label_12 = new QLabel(PersonalAccount);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(720, 380, 81, 21));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255) "));

        retranslateUi(PersonalAccount);

        QMetaObject::connectSlotsByName(PersonalAccount);
    } // setupUi

    void retranslateUi(QDialog *PersonalAccount)
    {
        PersonalAccount->setWindowTitle(QCoreApplication::translate("PersonalAccount", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("PersonalAccount", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("PersonalAccount", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("PersonalAccount", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("PersonalAccount", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PersonalAccount", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("PersonalAccount", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\232\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("PersonalAccount", "\320\237\320\276\320\273", nullptr));
        label_6->setText(QCoreApplication::translate("PersonalAccount", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\262\321\201\320\265 \320\277\320\276\320\273\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("PersonalAccount", "ID:", nullptr));
        label_8->setText(QCoreApplication::translate("PersonalAccount", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\276", nullptr));
        label_9->setText(QCoreApplication::translate("PersonalAccount", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PersonalAccount", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PersonalAccount", "\320\221\321\200\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_10->setText(QCoreApplication::translate("PersonalAccount", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("PersonalAccount", "TextLabel", nullptr));
        pushButton_otmena->setText(QCoreApplication::translate("PersonalAccount", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("PersonalAccount", "\320\235\320\276\320\274\320\265\321\200 \320\261\321\200\320\276\320\275\320\270:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonalAccount: public Ui_PersonalAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALACCOUNT_H
