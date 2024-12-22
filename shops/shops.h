#ifndef SHOPS_H
#define SHOPS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include "ui_shops.h"
#include "../data/DataController.h"
#include "../inputdialog.h"

namespace Ui {
class Shops;
}

class Shops : public QMainWindow
{
    Q_OBJECT
    typedef std::unique_ptr<std::vector<QStringList>> Table;

public:
    explicit Shops(QWidget *parent = nullptr);
    ~Shops();

private slots:
    void on_createButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();

private:
    Ui::Shops *ui;
    void phMessage();
    QStandardItemModel model;
    void fillTable();
    DataController *data;
    bool addShopQuery(const QString &shop);
    bool deleteShopQuery(const QString &shop);
    bool updateShopQuery(const QString& id,const QString &shop);
};

#endif // SHOPS_H
