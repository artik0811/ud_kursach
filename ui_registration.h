/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLineEdit *loginEdit;
    QLineEdit *pass1Edit;
    QLineEdit *passEdit2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_mail;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_9;
    QComboBox *comboBox;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(511, 444);
        registration->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50)"));
        loginEdit = new QLineEdit(registration);
        loginEdit->setObjectName("loginEdit");
        loginEdit->setGeometry(QRect(200, 50, 113, 24));
        loginEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color:rgb(255,255,255)}"));
        pass1Edit = new QLineEdit(registration);
        pass1Edit->setObjectName("pass1Edit");
        pass1Edit->setGeometry(QRect(200, 250, 113, 24));
        pass1Edit->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        passEdit2 = new QLineEdit(registration);
        passEdit2->setObjectName("passEdit2");
        passEdit2->setGeometry(QRect(200, 300, 113, 24));
        passEdit2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        pushButton = new QPushButton(registration);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 360, 121, 24));
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
        label = new QLabel(registration);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 101, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        label_2 = new QLabel(registration);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 230, 49, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        label_3 = new QLabel(registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 280, 101, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        pushButton_2 = new QPushButton(registration);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 360, 121, 24));
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
        label_4 = new QLabel(registration);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 50, 201, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        label_5 = new QLabel(registration);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 300, 121, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        label_6 = new QLabel(registration);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(150, 420, 181, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        lineEdit_mail = new QLineEdit(registration);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(200, 100, 113, 24));
        lineEdit_mail->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color:rgb(255,255,255)}"));
        label_8 = new QLabel(registration);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(240, 80, 41, 16));
        label_8->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        lineEdit = new QLineEdit(registration);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 150, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{color:rgb(255,255,255)}"));
        label_9 = new QLabel(registration);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(240, 130, 31, 16));
        label_9->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        comboBox = new QComboBox(registration);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(200, 200, 111, 24));
        comboBox->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        label_10 = new QLabel(registration);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(240, 180, 49, 16));
        label_10->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        label_11 = new QLabel(registration);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 150, 121, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("registration", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("registration", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("registration", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("registration", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("registration", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \321\203\320\266\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202!", nullptr));
        label_5->setText(QCoreApplication::translate("registration", "\320\237\320\260\321\200\320\276\320\273\320\270 \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\321\216\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\210\320\273\320\260 \321\203\321\201\320\277\320\265\321\210\320\275\320\276", nullptr));
        label_8->setText(QCoreApplication::translate("registration", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_9->setText(QCoreApplication::translate("registration", "\320\244\320\230\320\236", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("registration", "\320\234\321\203\320\266.", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("registration", "\320\226\320\265\320\275.", nullptr));

        label_10->setText(QCoreApplication::translate("registration", "\320\237\320\276\320\273", nullptr));
        label_11->setText(QCoreApplication::translate("registration", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\262\321\201\320\265 \320\277\320\276\320\273\321\217!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
