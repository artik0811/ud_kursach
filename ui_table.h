/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

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

class Ui_Table
{
public:
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;

    void setupUi(QDialog *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName("Table");
        Table->resize(627, 339);
        Table->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50)"));
        pushButton = new QPushButton(Table);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(530, 300, 80, 24));
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
        tableView = new QTableView(Table);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(15, 11, 341, 311));
        tableView->setTabletTracking(true);
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
        pushButton_2 = new QPushButton(Table);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(390, 250, 80, 24));
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
        lineEdit = new QLineEdit(Table);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(470, 30, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        lineEdit_2 = new QLineEdit(Table);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(502, 70, 81, 24));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        label = new QLabel(Table);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 30, 61, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        label_2 = new QLabel(Table);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(368, 70, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        comboBox = new QComboBox(Table);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 110, 41, 24));
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        label_3 = new QLabel(Table);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 110, 61, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        lineEdit_3 = new QLineEdit(Table);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(500, 110, 81, 24));
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        label_4 = new QLabel(Table);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(380, 220, 201, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        pushButton_3 = new QPushButton(Table);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(500, 250, 80, 24));
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
        comboBox_2 = new QComboBox(Table);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(450, 70, 41, 24));
        comboBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));

        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QDialog *Table)
    {
        Table->setWindowTitle(QCoreApplication::translate("Table", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Table", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Table", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label->setText(QCoreApplication::translate("Table", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("Table", "\320\246\320\265\320\275\320\260:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Table", ">", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Table", "=", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Table", "<", nullptr));

        label_3->setText(QCoreApplication::translate("Table", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", nullptr));
        label_4->setText(QCoreApplication::translate("Table", "\320\236\321\210\320\270\320\261\320\272\320\260! \320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \321\205\320\276\321\202\321\217 \320\261\321\213 1 \320\277\320\276\320\273\320\265", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Table", ">", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Table", "=", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Table", "<", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
