#include "harmoniedescouleurs.h"
#include "ui_harmoniedescouleurs.h"
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QHBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QColorDialog>
#include <QColor>



HarmonieDesCouleurs::HarmonieDesCouleurs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HarmonieDesCouleurs)
{
    ui->setupUi(this);
}

HarmonieDesCouleurs::~HarmonieDesCouleurs()
{
    delete ui;
}

void HarmonieDesCouleurs::on_actionQuitter_triggered()
{
    close();
}

void HarmonieDesCouleurs::on_Parcourir_clicked()
{
    //QLabel* nomfichier_label = new QLabel(this);
    QString nomfichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Images (*.ppm)"));

    if(!nomfichier.isEmpty()){
        ui->cheminParcourir->setText(nomfichier);
        QImage image(nomfichier);
        image = image.scaledToWidth(ui->image_label->width(),Qt::SmoothTransformation);

        if(!image.isNull()){
            //QLabel* image_label = new QLabel(this);
            ui->image_label -> setPixmap(QPixmap::fromImage(image));
            ui->image_label -> setFixedSize((image.size()));
        }

    }


}



QColor lastColorSelected = Qt::white;

void HarmonieDesCouleurs::on_colorSelector_clicked()
{
    QColorDialog dialog(this);
    dialog.setOption(QColorDialog::NoButtons);
    dialog.setCurrentColor(lastColorSelected);

    QColor color = dialog.getColor(lastColorSelected, this, tr("Choisir une couleur"), QColorDialog::ShowAlphaChannel | QColorDialog::DontUseNativeDialog);
    if(color.isValid()){
        lastColorSelected = color;
    }

    QString cssColor = color.name(QColor::HexRgb);
    ui->colorSelector->setStyleSheet(QString("background-color: %1").arg(cssColor));
}

void HarmonieDesCouleurs::on_actionCredits_triggered()
{
    QDialog *creditsFenetre = new QDialog(this);
    creditsFenetre->setWindowTitle("Crédits");

    QLabel *creditsTexte = new QLabel(creditsFenetre);
    creditsTexte->setText("<center>*** Harmonie des Couleurs ***</center><br><br>"
                   "Développée par :"
                   "<p style='text-align: right;'>Christina MAURIN<br>Thibault ODOR</p>"
                   "<br>"
                   "Basé sur Qt et C++<br>"
                   "Crédits background : Vecteezy"
                   "<br><br>"
                   "Merci d'utiliser l'application !<br>");
    creditsFenetre->setLayout(new QVBoxLayout());
    creditsFenetre->layout()->addWidget((creditsTexte));

    creditsFenetre->exec();
}

