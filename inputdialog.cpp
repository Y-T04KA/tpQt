#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent, const QString &prompt)
    : QDialog(parent)
    , ui(new Ui::InputDialog)
{
    ui->setupUi(this);

    ui->inputPrompt->setText(prompt);
    ui->idLine->setHidden(true);
    ui->shopName->setHidden(true);

    if (prompt.contains("id"))
    {
        ui->idLine->setHidden(false);
        ui->idLine->setEnabled(true);
        ui->idLine->setPlaceholderText("id");
    }
    if (prompt.contains("название"))
    {
        ui->shopName->setHidden(false);
        ui->shopName->setEnabled(true);
        ui->shopName->setPlaceholderText("Название");
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
    isOkClicked = true;
}

