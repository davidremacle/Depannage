#include "fenetreprincipale.h"

#include "aboutdepannage.h"


FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);

    setWindowTitle("Depannage 1.0");
    ui->groupBox_4->setVisible(false);

    ui->idtvBox->setVisible(false);
    ui->telephonieBox->setVisible(false);

    ui->btnGenererTexte->setShortcut(Qt::Key_F1);
    ui->btnClearText->setShortcut(Qt::Key_F2);

    ui->actionQuitter->setShortcut(QKeySequence::Quit);

    connect(ui->btnGenererTexte, SIGNAL(clicked()), this, SLOT(genererText()));
    connect(ui->btnClearText, SIGNAL(clicked()), this, SLOT(effacerText()));
    connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

void FenetrePrincipale::genererText()
{
    QString depText;

    depText +="Dep ";



    if(ui->btnQuali->isChecked())
    {
        depText +=" qualitatif, ";
    }
    else
    {
        depText +=" total, ";
    }

    if(ui->btnSaccadesImages->isChecked())
    {
        depText += "saccades images ";
    }

    if(ui->btnVoixRobotique->isChecked())
    {
        depText += " voix robotique ";
    }

    if(ui->btnModem->isChecked())
    {
        depText += "modem decroche, ";
    }

    depText += "Produits :";
    if(ui->btnIdtv->isChecked())
    {
        depText += " IDTV ";
    }

    if(ui->btnTVAna->isChecked())
    {
        depText += " TV Analogique ";
    }

    if(ui->btnInternet->isChecked())
    {
        depText +=" internet ";
    }
    if(ui->btnTelephonie->isChecked())
    {
        depText += " Telephonie ";
    }

    if(!ui->btnCable->isChecked())
    {
        depText +=" Cable NOK, ";
    }
    else
    {
        depText +=" Cable OK, ";
    }


    if(!ui->btnAmpli->isChecked())
    {
        depText +=" Ampli NOK, ";
    }
    else
    {
        depText +=" Ampli OK, ";
    }


    if(!ui->RXEdit->text().isEmpty())
    {
        depText += "Signaux - ";
        depText += "RX : " + ui->RXEdit->text() + " ";
    }
    if(!ui->TXEdit->text().isEmpty())
    {
        depText += "TX : " + ui->TXEdit->text() + " ";
    }
    if(!ui->SNREdit->text().isEmpty())
    {
        depText += "SNR : " + ui->SNREdit->text() + " ";
    }


    if(!ui->btnCoupRue->isChecked())
    {
        depText +=" pas de coupure dans la rue";
    }
    else
    {
        depText += " coupe le " + ui->date_edit->text() + " a la place de " + ui->nom_coupe->text();

    }

    ui->DepTextEdit->setPlainText(depText.toUtf8());

    ui->DepTextEdit->selectAll();

    ui->DepTextEdit->copy();

}

void FenetrePrincipale::effacerText()
{
    ui->DepTextEdit->setPlainText("");
    ui->btnQuali->setChecked(false);
    ui->btnCoupRue->setChecked(false);
    ui->btnAmpli->setChecked(false);
    ui->btnCable->setChecked(false);
    ui->btnIdtv->setChecked(false);
    ui->btnInternet->setChecked(false);
    ui->btnTVAna->setChecked(false);
    ui->btnTelephonie->setChecked(false);
    ui->RXEdit->setText("");
    ui->TXEdit->setText("");
    ui->SNREdit->setText("");
    ui->btnModem->setChecked(false);
    ui->btnSaccadesImages->setChecked(false);
    ui->btnVoixRobotique->setChecked(false);
}

void FenetrePrincipale::on_btnCoupRue_stateChanged(int arg1)
{
    switch (arg1)
    {
    case 0:
        ui->groupBox_4->setVisible(false);
        break;
    case 2:
        ui->groupBox_4->setVisible(true);
        break;
    }
}

void FenetrePrincipale::on_actionAbout_triggered()
{
    aboutDepannage *Windabout = new aboutDepannage;

    Windabout->show();
}

void FenetrePrincipale::on_btnIdtv_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        ui->idtvBox->setVisible(false);
        break;
    case 2:
        ui->idtvBox->setVisible(true);
        break;
    }
}

void FenetrePrincipale::on_btnTelephonie_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        ui->telephonieBox->setVisible(false);
        break;
    case 2:
        ui->telephonieBox->setVisible(true);
        break;

    }
}
