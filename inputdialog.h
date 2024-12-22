#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr, const QString &prompt = "Не задан запрос");
    ~InputDialog();

    QString getIdLine();
    QString getShopName();
    bool isOkClicked = false;

    private slots:
    void on_buttonBox_accepted();
private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
