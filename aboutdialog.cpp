#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    QPixmap logo(":/images/n.png");

    ui->label_logo->setPixmap(logo);
    ui->label_logo->show();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
