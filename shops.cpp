#include "shops.h"
#include "ui_shops.h"

Shops::Shops(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shops)
{
    ui->setupUi(this);
}

Shops::~Shops()
{
    delete ui;
}
