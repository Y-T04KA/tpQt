#ifndef SHOPS_H
#define SHOPS_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Shops;
}

class Shops : public QMainWindow
{
    Q_OBJECT

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
};

#endif // SHOPS_H
