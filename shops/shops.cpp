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
    //в идеале надо класть в конфиг но нам пойдет
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
    ui->shopTable->reset();
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
}

bool Shops::addShopQuery(const QString& shop)
{
    if (shop.isEmpty()) return false;
    return data->createShop(shop);
}

bool Shops::deleteShopQuery(const QString& shop)
{
    if (shop.isEmpty()) return false;
    return data->deleteShop(shop.toInt());
}

bool Shops::updateShopQuery(const QString& id,const QString& shop)
{
    if (shop.isEmpty()) return false;
    return data->updateShop(id, shop);
}


void Shops::on_createButton_clicked()
{
    auto createDialog = new InputDialog(this,QString("Введите название магазина:"));
    createDialog->exec();
    if (createDialog->isOkClicked)
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
    auto deleteDialog = new InputDialog(this, QString("Введите id магазина для удаления"));
    deleteDialog->exec();
    if (deleteDialog->isOkClicked)
    {
        auto idToDelete = deleteDialog->getIdLine();
        bool ok = false;
        idToDelete.toInt(&ok);
        if (idToDelete.toInt() <= model.rowCount() && ok)
        {
            // query path
            if (!deleteShopQuery(idToDelete))
            {
                phMessage();
            }
        } else
        {
            QMessageBox::critical(this,"Ошибка", "Неправильный id");
        };
    }
}


void Shops::on_updateButton_clicked()
{
    auto updateDialog = new InputDialog(this, QString("Введите id магазина и новое название магазина"));
    updateDialog->exec();
    if (updateDialog->isOkClicked)
    {
        auto idToUpdate = updateDialog->getIdLine();
        bool ok = false;
        idToUpdate.toInt(&ok);
        if (idToUpdate.toInt() <= model.rowCount() && ok)
        {
            // query path
            if (!updateShopQuery(idToUpdate, updateDialog->getShopName()))
            {
                phMessage();
            }
        } else
        {
            QMessageBox::critical(this,"Ошибка", "Неправильный id");
        };
    }
}

void Shops::phMessage()
{
    QMessageBox::critical(this,"Важно","Ошибка");
}
