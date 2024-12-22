//
// Created by yt04ka on 2024-12-21.
//

#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <QtSql>


class DataController {
    //typedef std::unique_ptr<std::vector<QStringList>> Table;
    public:
    explicit DataController(const QString& path);
    ~DataController();
    bool getShops();
    bool createShop(const QString& shopName) const;
    bool updateShop(const QString& shopId, const QString& shopName);
    bool deleteShop(const int& shopId) const;

    bool getItems();
    bool getItemsInShop(const int& shopId);
    bool getItemByShops(const int& itemId);

    bool createItem(const QString& itemName);
    bool newDelivery(const int& itemId, const int& shopId, const int& quantity);
    bool removeItem(const int& itemId, const int& shopId, const int& quantity);

    std::vector<QStringList> table;
    int getRowCount() const;
    QString getColumnAtRow(const int& item, const int& row);
    private:
    QSqlDatabase db;
};



#endif //DATACONTROLLER_H
