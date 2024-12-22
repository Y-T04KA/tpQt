#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent, const QString &prompt)
    : QDialog(parent)
    , ui(new Ui::InputDialog)
{
    ui->setupUi(this);

    ui->inputPrompt->setText(prompt);

    if (prompt.contains("id магазина"))
    {
        ui->idLine->setEnabled(true);
    }
    if (prompt.contains("название магазина"))
    {
        ui->shopName->setEnabled(true);
    }
}

InputDialog::~InputDialog()
{
    delete ui;
}

QString InputDialog::getIdLine()
{
    return ui->idLine->text();
}

QString InputDialog::getShopName()
{
    return ui->shopName->text();
}

void InputDialog::on_buttonBox_accepted()
{
    isOk = true;
}

