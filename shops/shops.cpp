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

    data = new DataController("/home/yt04ka/CLionProjects/tpQt/data/tpdb.sqlite");
    fillTable();
}

Shops::~Shops()
{
    delete ui;
}

void Shops::fillTable()
{
    if (!data->getShops()) phMessage();
    model.clear();
    model.setColumnCount(2);
    model.setHeaderData(0, Qt::Horizontal, "id");
    model.setHeaderData(1, Qt::Horizontal, "Магазин");
    model.setRowCount(data->getRowCount());
    for (int row = 0; row < data->getRowCount(); row++)
    {
        model.setItem(row, 0, new QStandardItem(data->getColumnAtRow(0,row)));
        model.setItem(row, 1, new QStandardItem(data->getColumnAtRow(1,row)));
    }

    ui->shopTable->setModel(&model);
    ui->shopTable->reset();
    ui->shopTable->update();
}

bool Shops::addShopQuery(const QString& shop)
{
    if (shop.isEmpty()) return false;
    return data->createShop(shop);
}


void Shops::on_createButton_clicked()
{
    auto createDialog = new InputDialog(this,QString("Введите название магазина:"));
    createDialog->exec();
    if (createDialog->isOk)
    {
        auto newShopName = createDialog->getShopName();
        if (!addShopQuery(newShopName))
        {
            phMessage();
        };
    }
    fillTable(); //должна обновляться таблица в интерфейсе но почему-то этого не делает
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
    QMessageBox::critical(this,"Важно","Ошибка");
}
