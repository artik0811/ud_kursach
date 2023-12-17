/********************************************************************************
** Form generated from reading UI file 'mainemployee.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINEMPLOYEE_H
#define UI_MAINEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainEmployee
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_11;

    void setupUi(QDialog *mainEmployee)
    {
        if (mainEmployee->objectName().isEmpty())
            mainEmployee->setObjectName("mainEmployee");
        mainEmployee->resize(300, 560);
        pushButton = new QPushButton(mainEmployee);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 520, 101, 24));
        pushButton_2 = new QPushButton(mainEmployee);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(82, 120, 121, 24));
        pushButton_3 = new QPushButton(mainEmployee);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(81, 160, 121, 24));
        pushButton_4 = new QPushButton(mainEmployee);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(81, 200, 121, 24));
        pushButton_5 = new QPushButton(mainEmployee);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(81, 240, 121, 24));
        pushButton_6 = new QPushButton(mainEmployee);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(81, 280, 121, 24));
        pushButton_7 = new QPushButton(mainEmployee);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(80, 320, 121, 24));
        pushButton_8 = new QPushButton(mainEmployee);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(81, 360, 121, 24));
        pushButton_9 = new QPushButton(mainEmployee);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(81, 400, 121, 24));
        pushButton_10 = new QPushButton(mainEmployee);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(80, 440, 121, 24));
        label = new QLabel(mainEmployee);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 271, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(mainEmployee);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 80, 91, 16));
        pushButton_11 = new QPushButton(mainEmployee);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(80, 480, 121, 24));

        retranslateUi(mainEmployee);

        QMetaObject::connectSlotsByName(mainEmployee);
    } // setupUi

    void retranslateUi(QDialog *mainEmployee)
    {
        mainEmployee->setWindowTitle(QCoreApplication::translate("mainEmployee", "\320\234\320\265\320\275\321\216", nullptr));
        pushButton->setText(QCoreApplication::translate("mainEmployee", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainEmployee", "\320\241\321\202\321\203\320\264\320\270\320\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mainEmployee", "\320\243\321\201\320\273\321\203\320\263\320\270", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mainEmployee", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mainEmployee", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mainEmployee", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        pushButton_7->setText(QCoreApplication::translate("mainEmployee", "\320\227\320\260\320\272\320\260\320\267", nullptr));
        pushButton_8->setText(QCoreApplication::translate("mainEmployee", "\320\224\320\276\320\277 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_9->setText(QCoreApplication::translate("mainEmployee", "\320\221\321\200\320\276\320\275\321\214 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        pushButton_10->setText(QCoreApplication::translate("mainEmployee", "\320\221\321\200\320\276\320\275\321\214", nullptr));
        label->setText(QCoreApplication::translate("mainEmployee", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("mainEmployee", "\320\222\320\260\321\210 ID:", nullptr));
        pushButton_11->setText(QCoreApplication::translate("mainEmployee", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainEmployee: public Ui_mainEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINEMPLOYEE_H
