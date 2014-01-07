#ifndef ABOUTDEPANNAGE_H
#define ABOUTDEPANNAGE_H
#include <QDialog>

namespace Ui {
class aboutDepannage;
}

class aboutDepannage : public QDialog
{
    Q_OBJECT
    
public:
    explicit aboutDepannage(QWidget *parent = 0);
    ~aboutDepannage();
    
private slots:


    void on_btnFermerFenetre_clicked();

private:
    Ui::aboutDepannage *ui;
};

#endif // ABOUTDEPANNAGE_H
