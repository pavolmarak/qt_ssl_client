#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QTcpSocket)
{
    ui->setupUi(this);
    connect(this->socket,SIGNAL(connected()),this,SLOT(connectedSlot()));
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
    ui->log->append("Connected successfully");
}
