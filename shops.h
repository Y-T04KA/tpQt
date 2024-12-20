#ifndef SHOPS_H
#define SHOPS_H

#include <QMainWindow>

namespace Ui {
class Shops;
}

class Shops : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shops(QWidget *parent = nullptr);
    ~Shops();

private:
    Ui::Shops *ui;
};

#endif // SHOPS_H
