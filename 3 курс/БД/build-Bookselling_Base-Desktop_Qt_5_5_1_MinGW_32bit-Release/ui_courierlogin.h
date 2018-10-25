/********************************************************************************
** Form generated from reading UI file 'courierlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERLOGIN_H
#define UI_COURIERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courierlogin
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtl;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtp;
    QPushButton *pushButton_2;
    QLabel *lstatus;

    void setupUi(QDialog *courierlogin)
    {
        if (courierlogin->objectName().isEmpty())
            courierlogin->setObjectName(QStringLiteral("courierlogin"));
        courierlogin->resize(1000, 600);
        widget = new QWidget(courierlogin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 220, 79));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtl = new QLineEdit(widget);
        txtl->setObjectName(QStringLiteral("txtl"));
        txtl->setMaxLength(25);

        horizontalLayout->addWidget(txtl);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtp = new QLineEdit(widget);
        txtp->setObjectName(QStringLiteral("txtp"));
        txtp->setMaxLength(25);
        txtp->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtp);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        lstatus = new QLabel(widget);
        lstatus->setObjectName(QStringLiteral("lstatus"));

        verticalLayout_2->addWidget(lstatus);


        retranslateUi(courierlogin);

        QMetaObject::connectSlotsByName(courierlogin);
    } // setupUi

    void retranslateUi(QDialog *courierlogin)
    {
        courierlogin->setWindowTitle(QApplication::translate("courierlogin", "Courier authentification", 0));
        txtl->setPlaceholderText(QApplication::translate("courierlogin", "Enter login", 0));
        pushButton->setText(QApplication::translate("courierlogin", "Ok", 0));
        txtp->setPlaceholderText(QApplication::translate("courierlogin", "Enter password", 0));
        pushButton_2->setText(QApplication::translate("courierlogin", "Cancel", 0));
        lstatus->setText(QApplication::translate("courierlogin", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class courierlogin: public Ui_courierlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERLOGIN_H
