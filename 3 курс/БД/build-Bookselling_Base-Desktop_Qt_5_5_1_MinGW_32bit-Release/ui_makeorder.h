/********************************************************************************
** Form generated from reading UI file 'makeorder.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEORDER_H
#define UI_MAKEORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_makeorder
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *name;
    QLineEdit *address;
    QComboBox *product;
    QLineEdit *publishing;
    QLineEdit *price;
    QHBoxLayout *horizontalLayout;
    QComboBox *day;
    QComboBox *month;
    QComboBox *year;
    QPushButton *pushButton;

    void setupUi(QDialog *makeorder)
    {
        if (makeorder->objectName().isEmpty())
            makeorder->setObjectName(QStringLiteral("makeorder"));
        makeorder->resize(1000, 600);
        widget = new QWidget(makeorder);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(382, 93, 225, 254));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        name = new QLineEdit(widget);
        name->setObjectName(QStringLiteral("name"));
        name->setMaxLength(25);

        verticalLayout->addWidget(name);


        verticalLayout_2->addLayout(verticalLayout);

        address = new QLineEdit(widget);
        address->setObjectName(QStringLiteral("address"));
        address->setMaxLength(30);

        verticalLayout_2->addWidget(address);


        verticalLayout_3->addLayout(verticalLayout_2);

        product = new QComboBox(widget);
        product->setObjectName(QStringLiteral("product"));

        verticalLayout_3->addWidget(product);

        publishing = new QLineEdit(widget);
        publishing->setObjectName(QStringLiteral("publishing"));
        publishing->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        publishing->setReadOnly(true);

        verticalLayout_3->addWidget(publishing);

        price = new QLineEdit(widget);
        price->setObjectName(QStringLiteral("price"));
        price->setMaxLength(25);
        price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        price->setReadOnly(true);

        verticalLayout_3->addWidget(price);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        day = new QComboBox(widget);
        day->setObjectName(QStringLiteral("day"));

        horizontalLayout->addWidget(day);

        month = new QComboBox(widget);
        month->setObjectName(QStringLiteral("month"));

        horizontalLayout->addWidget(month);

        year = new QComboBox(widget);
        year->setObjectName(QStringLiteral("year"));

        horizontalLayout->addWidget(year);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        retranslateUi(makeorder);

        QMetaObject::connectSlotsByName(makeorder);
    } // setupUi

    void retranslateUi(QDialog *makeorder)
    {
        makeorder->setWindowTitle(QApplication::translate("makeorder", "Dialog", 0));
        label->setText(QApplication::translate("makeorder", "Enter the form", 0));
        name->setPlaceholderText(QApplication::translate("makeorder", "Enter name", 0));
        address->setPlaceholderText(QApplication::translate("makeorder", "Enter address", 0));
        publishing->setPlaceholderText(QApplication::translate("makeorder", "Publishing", 0));
        price->setPlaceholderText(QApplication::translate("makeorder", "Price", 0));
        pushButton->setText(QApplication::translate("makeorder", "\320\236\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class makeorder: public Ui_makeorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEORDER_H
