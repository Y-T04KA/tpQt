#include "inventory.h"
#include "ui_inventory.h"

Inventory::Inventory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inventory)
{
    ui->setupUi(this);

    connect(ui->createItemButton, &QPushButton::clicked, this, &Inventory::on_createItemButton_clicked);
    connect(ui->newDeliveryButton, &QPushButton::clicked, this, &Inventory::on_newDeliveryButton_clicked);
    connect(ui->removeItemButton, &QPushButton::clicked, this, &Inventory::on_removeItemButton_clicked);
}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::on_createItemButton_clicked()
{
    phMessage();
}


void Inventory::on_newDeliveryButton_clicked()
{
    phMessage();
}


void Inventory::on_removeItemButton_clicked()
{
    phMessage();
}

void Inventory::phMessage()
{
    QMessageBox::critical(this,"Важно","Ты пидор");
}

