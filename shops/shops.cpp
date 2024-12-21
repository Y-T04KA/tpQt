#include "shops.h"
#include "ui_shops.h"

Shops::Shops(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shops)
{
    ui->setupUi(this);

    connect(ui->createButton, &QPushButton::clicked, this, &Shops::on_createButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &Shops::on_deleteButton_clicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &Shops::on_updateButton_clicked);
}

Shops::~Shops()
{
    delete ui;
}

void Shops::on_createButton_clicked()
{
    phMessage();
}


void Shops::on_deleteButton_clicked()
{
    phMessage();
}


void Shops::on_updateButton_clicked()
{
    phMessage();
}

void Shops::phMessage()
{
    QMessageBox::critical(this,"Важно","Ты пидор");
}
