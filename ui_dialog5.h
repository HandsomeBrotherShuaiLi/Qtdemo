/********************************************************************************
** Form generated from reading UI file 'dialog5.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG5_H
#define UI_DIALOG5_H

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

class Ui_Dialog5
{
public:
    QLabel *label;
    QLineEdit *startlineEdit;
    QLabel *label_2;
    QLineEdit *endlineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog5)
    {
        if (Dialog5->objectName().isEmpty())
            Dialog5->setObjectName(QStringLiteral("Dialog5"));
        Dialog5->resize(400, 300);
        label = new QLabel(Dialog5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 50, 101, 61));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        startlineEdit = new QLineEdit(Dialog5);
        startlineEdit->setObjectName(QStringLiteral("startlineEdit"));
        startlineEdit->setGeometry(QRect(190, 70, 131, 31));
        label_2 = new QLabel(Dialog5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 101, 61));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::PlainText);
        endlineEdit = new QLineEdit(Dialog5);
        endlineEdit->setObjectName(QStringLiteral("endlineEdit"));
        endlineEdit->setGeometry(QRect(190, 140, 131, 31));
        pushButton = new QPushButton(Dialog5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 210, 81, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(Dialog5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 210, 81, 31));
        pushButton_2->setFont(font1);

        retranslateUi(Dialog5);

        QMetaObject::connectSlotsByName(Dialog5);
    } // setupUi

    void retranslateUi(QDialog *Dialog5)
    {
        Dialog5->setWindowTitle(QApplication::translate("Dialog5", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog5", " \350\265\267\345\247\213\347\202\271\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog5", " \347\273\210\346\255\242\347\202\271\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog5", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog5", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog5: public Ui_Dialog5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG5_H
