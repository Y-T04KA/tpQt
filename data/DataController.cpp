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

int DataController::getRowCount()
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
    //int idShop = query.record().indexOf("name_shop");
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

