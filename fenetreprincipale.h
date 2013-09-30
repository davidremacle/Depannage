#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QtGui>

namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

private slots:
    void genererText();
    void effacerText();
    void on_btnCoupRue_stateChanged(int arg1);

    void on_actionAbout_triggered();

    void on_btnIdtv_stateChanged(int arg1);

    void on_btnTelephonie_stateChanged(int arg1);

private:
    Ui::FenetrePrincipale *ui;
};

#endif // FENETREPRINCIPALE_H
