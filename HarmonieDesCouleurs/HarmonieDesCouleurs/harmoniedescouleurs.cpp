#include "harmoniedescouleurs.h"
#include "ui_harmoniedescouleurs.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QString>
#include <QImage>
#include <QLabel>
#include <QHBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QColorDialog>
#include <QColor>
#include "couleursDominantes.cpp"

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

QString nomFichier;
QString cheminFichier;
bool imageValide = false;
void HarmonieDesCouleurs::on_Parcourir_clicked()
{
    //QLabel* cheminFichier_label = new QLabel(this);
    cheminFichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Images *.ppm"));

    QFileInfo fileInfo(cheminFichier);
    nomFichier = fileInfo.fileName();

    if(!cheminFichier.isEmpty()){
        qDebug() << "Nom de fichier sélectionné : " << nomFichier;
        imageValide = true;
        ui->cheminParcourir->setText(cheminFichier);
        QImage image(cheminFichier);
        image = image.scaledToWidth(ui->init_image_label->width(),Qt::SmoothTransformation);

        if(!image.isNull()){
            //QLabel* image_label = new QLabel(this);
            ui->init_image_label -> setFixedSize((image.size()));
            ui->init_image_label -> setPixmap(QPixmap::fromImage(image));
        }

    } else {
        qDebug() << "Aucun fichier sélectionné";
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


Pixel couleur1, couleur2, couleur3, couleur4;

void HarmonieDesCouleurs::on_dom_colors_clicked()
{
    if(imageValide){
        char nomImage[cheminFichier.length()+1];
        strcpy(nomImage,cheminFichier.toLocal8Bit().constData());
        qDebug() << nomImage;
        couleursDominantes(nomImage, couleur1, couleur2, couleur3, couleur4);
        //qDebug() << (int)couleur2.r << " " << (int)couleur2.g << " " << (int)couleur2.b;
        //qDebug() << (int)couleur3.r << " " << (int)couleur3.g << " " << (int)couleur3.b;
        //qDebug() << (int)couleur1.r << " " << (int)couleur1.g << " " << (int)couleur1.b;
        //qDebug() << (int)couleur4.r << " " << (int)couleur4.g << " " << (int)couleur4.b;

        ui->d_color_1->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur1.r).arg((int)couleur1.g).arg((int)couleur1.b));
        ui->d_color_2->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur2.r).arg((int)couleur2.g).arg((int)couleur2.b));
        ui->d_color_3->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur3.r).arg((int)couleur3.g).arg((int)couleur3.b));
        ui->d_color_4->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur4.r).arg((int)couleur4.g).arg((int)couleur4.b));

    } else {
        QDialog *ErreurFenetre = new QDialog(this);
        ErreurFenetre->setWindowTitle("Erreur");

        QLabel *ErreurTexte = new QLabel(ErreurFenetre);
        ErreurTexte->setText("<center>Attention erreur &#x2F </center><br><br>"
                       "Il n'y a pas d'image choisie."
                       "<br>"
                       "<center>Sélectionnez une image valide.</center><br>");
        ErreurFenetre->setLayout(new QVBoxLayout());
        ErreurFenetre->layout()->addWidget((ErreurTexte));

        ErreurFenetre->exec();
    }
}

void HarmonieDesCouleurs::on_Supprimer_clicked()
{
    if(imageValide){
        imageValide = false;
        nomFichier = NULL;
        cheminFichier = "Chemin du fichier...";
        ui->cheminParcourir->setText(cheminFichier);
        ui->init_image_label->clear();
        ui->init_image_label->setText("Choisir une image...");
    } else {
        QDialog *ErreurFenetre = new QDialog(this);
        ErreurFenetre->setWindowTitle("Erreur");

        QLabel *ErreurTexte = new QLabel(ErreurFenetre);
        ErreurTexte->setText("<center>Attention erreur &#x2F </center><br><br>"
                       "<center>Il n'y a pas d'image à supprimer.</center><br>");
        ErreurFenetre->setLayout(new QVBoxLayout());
        ErreurFenetre->layout()->addWidget((ErreurTexte));

        ErreurFenetre->exec();
    }
}

