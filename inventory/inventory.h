#ifndef INVENTORY_H
#define INVENTORY_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>

#include "../data/DataController.h"
#include "../inputdialog.h"
#include "ui_inventory.h"

namespace Ui {
class Inventory;
}

class Inventory : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();

private slots:
    void on_createItemButton_clicked();

    void on_newDeliveryButton_clicked();

    void on_removeItemButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    int currentShop = 1; // надо заменить на чтение из конфига
    Ui::Inventory *ui;
    void phMessage();
    DataController *data;
    QStandardItemModel model;
    void fillTable(const int& page);
    bool addItemQuery(const QString& item);
    bool deliveryQuery(const int& shop, const int& item, const int& deliverySize);
    bool removeQuery(const int& shop, const int& item, const int& deliverySize);
};

#endif // INVENTORY_H
