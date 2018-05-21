/********************************************************************************
** Form generated from reading UI file 'myserver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSERVER_H
#define UI_MYSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_myServer
{
public:
    QGridLayout *gridLayout;
    QSpinBox *port;
    QPushButton *btnStart;
    QLineEdit *ip;
    QPushButton *btnClose;

    void setupUi(QDialog *myServer)
    {
        if (myServer->objectName().isEmpty())
            myServer->setObjectName(QStringLiteral("myServer"));
        myServer->resize(350, 55);
        gridLayout = new QGridLayout(myServer);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        port = new QSpinBox(myServer);
        port->setObjectName(QStringLiteral("port"));
        port->setMinimumSize(QSize(70, 0));
        port->setMaximum(99999);
        port->setValue(12345);

        gridLayout->addWidget(port, 1, 1, 1, 1);

        btnStart = new QPushButton(myServer);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(true);

        gridLayout->addWidget(btnStart, 1, 2, 1, 1);

        ip = new QLineEdit(myServer);
        ip->setObjectName(QStringLiteral("ip"));
        ip->setEnabled(false);

        gridLayout->addWidget(ip, 1, 0, 1, 1);

        btnClose = new QPushButton(myServer);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setEnabled(true);

        gridLayout->addWidget(btnClose, 1, 3, 1, 1);


        retranslateUi(myServer);

        QMetaObject::connectSlotsByName(myServer);
    } // setupUi

    void retranslateUi(QDialog *myServer)
    {
        myServer->setWindowTitle(QApplication::translate("myServer", "myServer", Q_NULLPTR));
        btnStart->setText(QApplication::translate("myServer", "START SERVER", Q_NULLPTR));
        ip->setText(QApplication::translate("myServer", "127.0.0.1", Q_NULLPTR));
        btnClose->setText(QApplication::translate("myServer", "CLOSE SERVER", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class myServer: public Ui_myServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSERVER_H
