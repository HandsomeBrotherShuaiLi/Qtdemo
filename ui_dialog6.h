/********************************************************************************
** Form generated from reading UI file 'dialog6.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG6_H
#define UI_DIALOG6_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog6
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *startlineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog6)
    {
        if (Dialog6->objectName().isEmpty())
            Dialog6->setObjectName(QStringLiteral("Dialog6"));
        Dialog6->resize(400, 300);
        label = new QLabel(Dialog6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 111, 51));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Dialog6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 110, 51, 21));
        label_2->setFont(font);
        startlineEdit = new QLineEdit(Dialog6);
        startlineEdit->setObjectName(QStringLiteral("startlineEdit"));
        startlineEdit->setGeometry(QRect(160, 110, 121, 31));
        pushButton = new QPushButton(Dialog6);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 190, 91, 31));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Dialog6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 190, 91, 31));
        pushButton_2->setFont(font);

        retranslateUi(Dialog6);

        QMetaObject::connectSlotsByName(Dialog6);
    } // setupUi

    void retranslateUi(QDialog *Dialog6)
    {
        Dialog6->setWindowTitle(QApplication::translate("Dialog6", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog6", "\346\237\245\350\257\242\347\225\214\351\235\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog6", "\350\265\267\347\202\271\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog6", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog6", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog6: public Ui_Dialog6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG6_H
