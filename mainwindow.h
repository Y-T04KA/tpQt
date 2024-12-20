#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "shops.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_shopsButton_clicked();

private:
    Ui::MainWindow *ui;
    Shops shops;
};
#endif // MAINWINDOW_H
