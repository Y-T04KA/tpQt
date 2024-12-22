//
// Created by yt04ka on 2024-12-21.
//

#include "DataController.h"

DataController::DataController(const QString& path)
{
    if (!db.isOpen())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
        if (!db.open())
        {
            qDebug() << "Failed to open database";
        }
    }
}

int DataController::getRowCount() const
{
    return table[0].size();
}

QString DataController::getColumnAtRow(const int& col, const int& row)
{
    return table[col][row];
}


bool DataController::getShops()
{
    bool success = false;
    table.clear();
    //query validity check

    QStringList ids;
    QStringList shops;
    QSqlQuery query(db);
    success = query.exec("select * FROM Shops");
    while (query.next())
    {
        ids.append(query.value(0).toString());
        shops.append(query.value(1).toString());
    }
    table.emplace_back(ids);
    table.emplace_back(shops);

    return success;
}

bool DataController::getItems()
{
    bool success = false;
    table.clear();
    QStringList ids;
    QStringList items;
    QSqlQuery query(db);
    success = query.exec("select * FROM Items");
    while (query.next())
    {
        ids.append(query.value(0).toString());
        items.append(query.value(1).toString());
    }
    table.emplace_back(ids);
    table.emplace_back(items);
    return success;
}


bool DataController::getItemsInShop(const int& shopId)
{
    bool success = false;
    table.clear();
    QStringList item;
    QStringList quantity;
    QSqlQuery query(db);
    query.prepare("SELECT Items.name_item, Inventory.number FROM Inventory INNER JOIN Items ON Inventory.id_item=Items.id_item WHERE id_shop = :id");
    query.bindValue(":id", shopId);
    success = query.exec();
    while (query.next())
    {
        item.append(query.value(0).toString());
        quantity.append(query.value(1).toString());
    }
    table.emplace_back(item);
    table.emplace_back(quantity);
    return success;
}

bool DataController::getItemByShops(const int& itemId)
{
    bool success = false;
    table.clear();
    QStringList shop;
    QStringList quantity;
    QSqlQuery query(db);
    query.prepare("SELECT Shops.name_shop, Inventory.number FROM Inventory INNER JOIN Shops ON Inventory.id_shop=Shops.id_shop WHERE Inventory.id_shop = :id");
    query.bindValue(":id", itemId);
    success = query.exec();
    while (query.next())
    {
        shop.append(query.value(0).toString());
        quantity.append(query.value(1).toString());
    }
    table.emplace_back(shop);
    table.emplace_back(quantity);
    return success;
}



bool DataController::createShop(const QString& shopName) const
{
    //bool success = false;
    //rudimentary sql injection check
    if (shopName.contains("DROP TABLE") || shopName.contains("DROP DATABASE")) return false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO Shops (name_shop) VALUES (:shop)");
    query.bindValue(":shop", shopName);
    return query.exec();
}

bool DataController::deleteShop(const int& shopId) const
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Shops WHERE id_shop = :shop");
    query.bindValue(":shop", shopId);
    return query.exec();
}

bool DataController::updateShop(const QString& shopId, const QString& shopName)
{
    QSqlQuery query(db);
    query.prepare("UPDATE Shops SET name_shop = :shop WHERE id_shop = :id");
    query.bindValue(":shop", shopName);
    query.bindValue(":id", shopId);
    return query.exec();
}

