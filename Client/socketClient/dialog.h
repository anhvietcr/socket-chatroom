#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QTcpSocket *socket;

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void bytesWritten(qint64);

private slots:
    void on_btnSend_clicked();
    void on_btnConnecter_clicked();
    void on_message_cursorPositionChanged(int arg1, int arg2);
};

#endif // DIALOG_H
