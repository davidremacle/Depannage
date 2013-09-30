#include "aboutdepannage.h"
#include "ui_aboutdepannage.h"

aboutDepannage::aboutDepannage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDepannage)
{
    ui->setupUi(this);
}

aboutDepannage::~aboutDepannage()
{
    delete ui;
}



void aboutDepannage::on_btnFermerFenetre_clicked()
{
    this->accept();
}
