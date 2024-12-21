#ifndef INVENTORY_H
#define INVENTORY_H

#include <QMainWindow>
#include <QMessageBox>

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

private:
    Ui::Inventory *ui;
    void phMessage();
};

#endif // INVENTORY_H
