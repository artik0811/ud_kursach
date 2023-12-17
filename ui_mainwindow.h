/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Foto
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Foto)
    {
        if (Foto->objectName().isEmpty())
            Foto->setObjectName("Foto");
        Foto->resize(520, 600);
        Foto->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50)"));
        centralwidget = new QWidget(Foto);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 210, 161, 51));
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
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(160, 420, 161, 51));
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
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(160, 140, 161, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
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
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(160, 350, 161, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
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
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(160, 280, 161, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
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
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(370, 90, 111, 24));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
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
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(160, 510, 161, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{padding:4px;\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 441, 51));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        Foto->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Foto);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 520, 21));
        Foto->setMenuBar(menubar);
        statusbar = new QStatusBar(Foto);
        statusbar->setObjectName("statusbar");
        Foto->setStatusBar(statusbar);

        retranslateUi(Foto);

        QMetaObject::connectSlotsByName(Foto);
    } // setupUi

    void retranslateUi(QMainWindow *Foto)
    {
        Foto->setWindowTitle(QCoreApplication::translate("Foto", "\320\234\320\265\320\275\321\216", nullptr));
        pushButton->setText(QCoreApplication::translate("Foto", "\320\235\320\260\321\210\320\270 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Foto", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\321\203\320\264\320\270\320\270", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Foto", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Foto", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Foto", "\320\227\320\260\320\261\321\200\320\276\320\275\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\321\203\320\264\320\270\321\216", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Foto", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Foto", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        label->setText(QCoreApplication::translate("Foto", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214,", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Foto: public Ui_Foto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
