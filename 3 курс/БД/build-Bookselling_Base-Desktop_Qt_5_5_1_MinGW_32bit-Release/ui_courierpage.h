/********************************************************************************
** Form generated from reading UI file 'courierpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERPAGE_H
#define UI_COURIERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courierpage
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *doneorder;

    void setupUi(QDialog *courierpage)
    {
        if (courierpage->objectName().isEmpty())
            courierpage->setObjectName(QStringLiteral("courierpage"));
        courierpage->resize(1000, 600);
        widget = new QWidget(courierpage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(41, 22, 901, 531));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        doneorder = new QPushButton(widget);
        doneorder->setObjectName(QStringLiteral("doneorder"));

        horizontalLayout->addWidget(doneorder);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(courierpage);

        QMetaObject::connectSlotsByName(courierpage);
    } // setupUi

    void retranslateUi(QDialog *courierpage)
    {
        courierpage->setWindowTitle(QApplication::translate("courierpage", "Courier page", 0));
        doneorder->setText(QApplication::translate("courierpage", "\320\241\320\264\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", 0));
    } // retranslateUi

};

namespace Ui {
    class courierpage: public Ui_courierpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERPAGE_H
