#ifndef MYSERVER_H
#define MYSERVER_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class myServer;
}

class myServer : public QDialog
{
    Q_OBJECT

public:
    explicit myServer(QWidget *parent = 0);
    ~myServer();

    void setButtonServer(QString);
    void listening();

private slots:
    void on_ip_cursorPositionChanged(int arg1, int arg2);
    void on_btnStart_clicked();
    void on_btnClose_clicked();

public slots:
    void newConnect();
    void receiveMessage();

private:
    Ui::myServer *ui;
    QList<QTcpSocket*> connects;
    QTcpServer *server;
};

#endif // MYSERVER_H
