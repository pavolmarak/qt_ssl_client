#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QTcpSocket)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Unconnected");
    //ui->statusbar->insertPermanentWidget(0,QPixmap())
    connect(this->socket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(disconnectedSlot()));
    connect(this->socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(errorSlot(QAbstractSocket::SocketError)));
    connect(this->socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(stateChangedSlot(QAbstractSocket::SocketState)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_connect_clicked()
{
    this->socket->connectToHost(ui->ip->text(),ui->port->text().toUInt());
}

void MainWindow::connectedSlot()
{
    ui->log->append("Connected successfully [socket descriptor: " + QString::number(this->socket->socketDescriptor()) + "]");
    ui->statusbar->showMessage("Connected");
}

void MainWindow::disconnectedSlot()
{
    ui->log->append("Disconnected");
    ui->statusbar->showMessage("Disconnected");
}

void MainWindow::errorSlot(QAbstractSocket::SocketError e)
{
    ui->log->append("Error [" + QString::number(e) + "]: " + this->socket->errorString());
}

void MainWindow::stateChangedSlot(QAbstractSocket::SocketState s)
{
    ui->log->append("State: " + QString::number(s));
}





void MainWindow::on_button_send_clicked()
{

}
