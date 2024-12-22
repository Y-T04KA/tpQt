//
// Created by yt04ka on 2024-12-21.
//

#include "DataController.h"

DataController::DataController(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    bool status = db.open();
    if (!db.isOpen())
    {
        qDebug() << "Failed to open database";
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
    //query validity check

    QStringList ids;
    QStringList shops;
    QSqlQuery query(db);
    success = query.exec("select * FROM Shops");
    int idShop = 0;
    while (query.next())
    {
        ids.append(query.value(0).toString());
        shops.append(query.value(1).toString());
    }
    table.emplace_back(ids);
    table.emplace_back(shops);

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

