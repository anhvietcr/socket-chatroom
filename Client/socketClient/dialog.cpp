#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(ui->chatLog->model(), SIGNAL(rowsInserted(QModelIndex,int,int)),
            ui->chatLog, SLOT(scrollToBottom()));
}

//is connected to server
void Dialog::connected()
{
    //viết message gửi đi
    socket->write("<" + ui->nickname->text().toLocal8Bit() + " join chat>");
    socket->flush();
    socket->waitForBytesWritten(3000); //bắt đầu gửi đi
}

//disconnect to server
void Dialog::disconnected()
{
    ui->btnSend->setEnabled(false);
    QMessageBox::warning(this, "Dissconnect", "Oops! Loss connect to server");

   //reconnecting
    ui->btnConnecter->setEnabled(true);
}

void Dialog::readyRead()
{
    ui->chatLog->addItem(socket->readAll());
}

void Dialog::bytesWritten(qint64 bytes)
{
    qDebug() << "Bytes Written: " << bytes;
}

Dialog::~Dialog()
{
    if (socket) {
        QString message = "<" +ui->nickname->text() + "> was left";

        //send to server
        socket->write(message.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
    delete ui;
}

//send message
//nút Send được nhấn
void Dialog::on_btnSend_clicked()
{
    if (socket) {
        QString message = "#" +ui->nickname->text() + ": " + ui->message->text();

        //send to server
        socket->write(message.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(3000);

        //clear text in chat
        ui->message->setText("");
    }
}

//connecting to server ...
//nút connect tới server được nhấn
void Dialog::on_btnConnecter_clicked()
{
    if (ui->nickname->text().isEmpty()) {
        QMessageBox::warning(this, "Wrong", "Nickname not empty");
        return;
    }

    socket->connectToHost(ui->server->text(), ui->port->value());

    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "Error", socket->errorString());
    } else {
        QMessageBox::information(this, "Successfuly", QString("Connected to Server  " + ui->server->text() + ":" + ui->port->text()));
        ui->btnConnecter->setEnabled(false);
        ui->nickname->setEnabled(false);
        ui->chatLog->clear();
    }
}

//change text in input send message
//hàm tự động chỉnh thanh scroll
void Dialog::on_message_cursorPositionChanged(int arg1, int arg2)
{
    if (ui->message->text().isEmpty()) {
        ui->btnSend->setEnabled(false);
    } else {
        ui->btnSend->setEnabled(true);
    }
}
