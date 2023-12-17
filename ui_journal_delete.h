/********************************************************************************
** Form generated from reading UI file 'journal_delete.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNAL_DELETE_H
#define UI_JOURNAL_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_journal_delete
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *journal_delete)
    {
        if (journal_delete->objectName().isEmpty())
            journal_delete->setObjectName("journal_delete");
        journal_delete->resize(514, 465);
        tableView = new QTableView(journal_delete);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 491, 381));
        pushButton = new QPushButton(journal_delete);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 420, 80, 24));
        pushButton_2 = new QPushButton(journal_delete);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 420, 91, 24));
        lineEdit = new QLineEdit(journal_delete);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 420, 161, 24));
        label = new QLabel(journal_delete);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 400, 49, 16));

        retranslateUi(journal_delete);

        QMetaObject::connectSlotsByName(journal_delete);
    } // setupUi

    void retranslateUi(QDialog *journal_delete)
    {
        journal_delete->setWindowTitle(QCoreApplication::translate("journal_delete", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\271", nullptr));
        pushButton->setText(QCoreApplication::translate("journal_delete", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("journal_delete", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("journal_delete", "\320\230\320\274\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class journal_delete: public Ui_journal_delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_DELETE_H
