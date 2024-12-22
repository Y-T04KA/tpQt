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
    data = new DataController("/home/yt04ka/CLionProjects/tpQt/data/tpdb.sqlite");
    fillTable(0);
}

void Inventory::fillTable(const int& page)
{
    switch (page)
    {
        case 0: // товары в магазине
            if (!data->getItemsInShop(currentShop)) phMessage();
            model.clear();
            ui->inShopTable->reset();
            model.setColumnCount(2);
            model.setHeaderData(0, Qt::Horizontal, "Товар");
            model.setHeaderData(1, Qt::Horizontal, "Количество");
            model.setRowCount(data->getRowCount());
            for (int row = 0; row < data->getRowCount(); row++)
            {
                model.setItem(row, 0, new QStandardItem(data->getColumnAtRow(0,row)));
                model.setItem(row, 1, new QStandardItem(data->getColumnAtRow(1,row)));
            }
            ui->inShopTable->setModel(&model);
                break;
        case 1: // все товары
            if (!data->getItems()) phMessage();
            model.clear();
            ui->itemsAllTable->reset();
            model.setColumnCount(2);
            model.setHeaderData(0, Qt::Horizontal, "id товара");
            model.setHeaderData(1, Qt::Horizontal, "Товар");
            model.setRowCount(data->getRowCount());
            for (int row = 0; row < data->getRowCount(); row++)
            {
                model.setItem(row, 0, new QStandardItem(data->getColumnAtRow(0,row)));
                model.setItem(row, 1, new QStandardItem(data->getColumnAtRow(1,row)));
            }
            ui->itemsAllTable->setModel(&model);
                break;
        case 2: // товары по магазинам
            if (!data->getItemByShops(currentShop)) phMessage();
            model.clear();
            ui->itemsByShopTable->reset();
            model.setColumnCount(2);
            model.setHeaderData(0, Qt::Horizontal, "Магазин");
            model.setHeaderData(1, Qt::Horizontal, "Количество");
            model.setRowCount(data->getRowCount());
            for (int row = 0; row < data->getRowCount(); row++)
            {
                model.setItem(row, 0, new QStandardItem(data->getColumnAtRow(0,row)));
                model.setItem(row, 1, new QStandardItem(data->getColumnAtRow(1,row)));
            }
            ui->itemsByShopTable->setModel(&model);
                break;
        default:
            QMessageBox::critical(this,"Ошибка","Ты как сюда попал");
            break;
    }
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
    QMessageBox::critical(this,"Ошибка","Ошибка");
}


void Inventory::on_tabWidget_tabBarClicked(int index) // от 0 до 2
{
    if (index!=2)
    {
        fillTable(index);
    } else
    {
        // ask for item id
        auto itemDialog = new InputDialog(this,"Введите id товара");
        itemDialog->exec();
        if (itemDialog->isOkClicked)
        {
            auto buf = currentShop;
            currentShop = itemDialog->getIdLine().toInt();
            fillTable(2);
            currentShop = buf;
        }
    }
}

