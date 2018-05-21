/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *server;
    QLabel *label_2;
    QSpinBox *port;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nickname;
    QPushButton *btnConnecter;
    QListWidget *chatLog;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *message;
    QPushButton *btnSend;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(526, 377);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        server = new QLineEdit(Dialog);
        server->setObjectName(QStringLiteral("server"));

        horizontalLayout->addWidget(server);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        port = new QSpinBox(Dialog);
        port->setObjectName(QStringLiteral("port"));
        port->setMaximum(999999);
        port->setValue(12345);

        horizontalLayout->addWidget(port);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nickname = new QLineEdit(Dialog);
        nickname->setObjectName(QStringLiteral("nickname"));

        horizontalLayout->addWidget(nickname);

        btnConnecter = new QPushButton(Dialog);
        btnConnecter->setObjectName(QStringLiteral("btnConnecter"));

        horizontalLayout->addWidget(btnConnecter);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        chatLog = new QListWidget(Dialog);
        chatLog->setObjectName(QStringLiteral("chatLog"));

        gridLayout->addWidget(chatLog, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        message = new QLineEdit(Dialog);
        message->setObjectName(QStringLiteral("message"));
        message->setMinimumSize(QSize(400, 45));

        horizontalLayout_2->addWidget(message);

        btnSend = new QPushButton(Dialog);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setEnabled(false);
        btnSend->setMinimumSize(QSize(100, 50));

        horizontalLayout_2->addWidget(btnSend);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(message, SIGNAL(returnPressed()), btnSend, SLOT(click()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Server IP", Q_NULLPTR));
        server->setText(QApplication::translate("Dialog", "192.168.56.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Port", Q_NULLPTR));
        nickname->setText(QString());
        nickname->setPlaceholderText(QApplication::translate("Dialog", "nick name", Q_NULLPTR));
        btnConnecter->setText(QApplication::translate("Dialog", "Connect Server", Q_NULLPTR));
        btnSend->setText(QApplication::translate("Dialog", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
