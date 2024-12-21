#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->shopsButton, &QPushButton::clicked, this, &MainWindow::on_shopsButton_clicked);
    connect(ui->inventoryButton, &QPushButton::clicked, this, &MainWindow::on_inventoryButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_shopsButton_clicked()
{
    shops.show();
    //this->close(); //works but won't be able to reopen
}


void MainWindow::on_inventoryButton_clicked()
{
    inv.show();
}

