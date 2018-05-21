#include "myserver.h"
#include "ui_myserver.h"

myServer::myServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myServer)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnect()));
}

myServer::~myServer()
{
    delete ui;
}

void myServer::on_ip_cursorPositionChanged(int arg1, int arg2)
{
    if (ui->ip->text().isEmpty() || ui->ip->text().length() < 7) {
        setButtonServer("close");
    } else {
        setButtonServer("open");
    }
}

//open server
//nút start server được nhấn
void myServer::on_btnStart_clicked()
{
    if (server)
    {
        listening();
    } else {
        server = new QTcpServer(this);
        connect(server, SIGNAL(newConnection()), this, SLOT(newConnect()));
        listening();
    }
}

//new listening my server
void myServer::listening()
{
    //nếu mà server, đã bật hoặc không bật được
    if (!server->listen(QHostAddress::Any, ui->port->value())) {
        QMessageBox::warning(this, "Error", "Serser was open in address: " + ui->ip->text() + ":" + ui->port->text());
    } else {
        //bật thành công server
        QMessageBox::information(this, "Successfully", "Server open successfully !");
        setButtonServer("open");
    }
}

//close server
//nút close server được nhấn
void myServer::on_btnClose_clicked()
{
    //send to clients
    foreach(QTcpSocket *socket, connects) {
        socket->write("<< server was close >>");
        socket->flush();
        socket->waitForBytesWritten(3000);
    }

    //del server
    server->close();
    delete server;
    server = NULL;

    //del list connected
    connects.clear();

    //hiển thị thông điệp cho người quản trị server biết server close
    QMessageBox::information(this, "Close", "Server was close!");
    setButtonServer("close");
}

void myServer::setButtonServer(QString is)
{
    //server was open
    if (is == "open") {
        ui->btnStart->setEnabled(false);
        ui->btnClose->setEnabled(true);
    } else if (is == "close") {
        ui->btnStart->setEnabled(true);
        ui->btnClose->setEnabled(false);
    }
}

//new client connecting...
void myServer::newConnect()
{
    //server nhận được connect từ client
    //tạo socket phía server để đọc gói tin
    QTcpSocket *socket = server->nextPendingConnection();

    //đưa socket mới vào danh sách
    connects.append(socket);

    //receive message from client
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

//get message from a client
void myServer::receiveMessage()
{
    //nhận được message từ client
    //sender hiện tại là QObject, nên cần ép về QTcpSocket, vì được gửi qua signal, slot nên bị chuyển kiểu
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());

    //bắt đầu đọc toàn bộ message
    QByteArray data = socket->readAll();

    //foreach(biến, tập)
    //duyệt qua hết mảng connects
    foreach(QTcpSocket *socket, connects) {

        socket->write(data);
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
}

