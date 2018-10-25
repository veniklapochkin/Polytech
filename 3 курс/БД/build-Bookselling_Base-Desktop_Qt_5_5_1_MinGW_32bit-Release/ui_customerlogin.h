/********************************************************************************
** Form generated from reading UI file 'customerlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERLOGIN_H
#define UI_CUSTOMERLOGIN_H

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

class Ui_customerlogin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtl;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtp;
    QPushButton *pushButton_2;
    QLabel *lstatus;

    void setupUi(QDialog *customerlogin)
    {
        if (customerlogin->objectName().isEmpty())
            customerlogin->setObjectName(QStringLiteral("customerlogin"));
        customerlogin->resize(1000, 600);
        layoutWidget = new QWidget(customerlogin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 220, 79));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtl = new QLineEdit(layoutWidget);
        txtl->setObjectName(QStringLiteral("txtl"));
        txtl->setMaxLength(25);

        horizontalLayout->addWidget(txtl);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtp = new QLineEdit(layoutWidget);
        txtp->setObjectName(QStringLiteral("txtp"));
        txtp->setMaxLength(25);
        txtp->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtp);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        lstatus = new QLabel(layoutWidget);
        lstatus->setObjectName(QStringLiteral("lstatus"));

        verticalLayout_2->addWidget(lstatus);


        retranslateUi(customerlogin);

        QMetaObject::connectSlotsByName(customerlogin);
    } // setupUi

    void retranslateUi(QDialog *customerlogin)
    {
        customerlogin->setWindowTitle(QApplication::translate("customerlogin", "Customer authentification", 0));
        txtl->setPlaceholderText(QApplication::translate("customerlogin", "Enter login", 0));
        pushButton->setText(QApplication::translate("customerlogin", "Ok", 0));
        txtp->setPlaceholderText(QApplication::translate("customerlogin", "Enter password", 0));
        pushButton_2->setText(QApplication::translate("customerlogin", "Cancel", 0));
        lstatus->setText(QApplication::translate("customerlogin", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class customerlogin: public Ui_customerlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERLOGIN_H
