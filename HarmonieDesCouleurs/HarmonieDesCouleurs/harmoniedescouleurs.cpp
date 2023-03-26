#include "harmoniedescouleurs.h"
#include "harmony.h"
#include "ui_harmoniedescouleurs.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QString>
#include <QImage>
#include <QImageReader>
#include <QLabel>
#include <QHBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QColorDialog>
#include <QColor>
#include <QSlider>
#include <QObject>
#include "couleursDominantes.cpp"

QString nomFichier;
QString cheminFichier;
bool imageValide = false;
bool imageModifiee = false;

// Concerne la palette de couleur
Pixel colorChosenPixel;
QColor colorChosenQT;
bool colorChosenBool;

// Concerne la génération de couleur dominantes
Pixel couleur1, couleur2, couleur3, couleur4;
bool genDomColor = false;

HarmonieDesCouleurs::HarmonieDesCouleurs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HarmonieDesCouleurs)
{
    ui->setupUi(this);

    imageIsSet(imageValide);

    QObject::connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](){
        int valeur = ui->horizontalSlider->value();
        ui->valeurSlider->setText(QString::number(valeur));
    });

    QObject::connect(ui->radioB_Analogue, &QRadioButton::clicked, [=](){
        ui->horizontalSlider->setMaximum((359));
    });

    QObject::connect(ui->radioB_Complementaire, &QRadioButton::clicked, [=](){
        ui->horizontalSlider->setMaximum((179));
    });

    QObject::connect(ui->radioB_Triadique, &QRadioButton::clicked, [=](){
        ui->horizontalSlider->setMaximum((119));
    });

    QObject::connect(ui->radioB_Quadratique, &QRadioButton::clicked, [=](){
        ui->horizontalSlider->setMaximum((89));
    });

    ui->colorChosenUI->setEnabled(false);

    imageIsModified(imageModifiee);


}

HarmonieDesCouleurs::~HarmonieDesCouleurs()
{
    delete ui;
}

void HarmonieDesCouleurs::imageIsSet(bool imageValide){
    if(!imageValide){ //Si l'image n'est pas valide
        ui->Supprimer->setVisible(false);
        //Image originale
        ui->dom_colors->setVisible(false);
        ui->d_color_1->setVisible(false);
        ui->d_color_2->setVisible(false);
        ui->d_color_3->setVisible(false);
        ui->d_color_4->setVisible(false);
        //Choix couleur
        ui->colorSelector->setVisible(false);
        //Couleur choisie
        ui->colorChosenUI->setVisible(false);
        //Choix Harmonie
        for(int i=0; i < ui->choixHarmonieLayout->count(); i++){
            QWidget *widget = ui->choixHarmonieLayout->itemAt(i)->widget();
                if (widget != NULL) {
                    widget->setVisible(false);
                }
        }
        //Image modifiée
        ui->GenererImgFinal->setVisible(false);
        ui->GenererImgFinal->setEnabled(false);
    }else{  // Si l'image est valide
        ui->Supprimer->setVisible(true);
        //Image originale
        ui->dom_colors->setVisible(true);
        ui->d_color_1->setVisible(true);
        ui->d_color_2->setVisible(true);
        ui->d_color_3->setVisible(true);
        ui->d_color_4->setVisible(true);
        // Gen pas encore appuyé donc on ne peut choisir la couleur
        if(!genDomColor){
            ui->d_color_1->setEnabled(false);
            ui->d_color_2->setEnabled(false);
            ui->d_color_3->setEnabled(false);
            ui->d_color_4->setEnabled(false);
        }
        //Choix couleur
        ui->colorSelector->setVisible(true);
        //Couleur choisie
        ui->colorChosenUI->setVisible(true);
        //Choix Harmonie
        for(int i=0; i < ui->choixHarmonieLayout->count(); i++){
            QWidget *widget = ui->choixHarmonieLayout->itemAt(i)->widget();
                if (widget != NULL) {
                    widget->setVisible(true);
                }
        }
        //Image modifiée
        ui->GenererImgFinal->setVisible(true);
    }
}

void HarmonieDesCouleurs::imageIsModified(bool imageModifiee){
    if(!imageModifiee){
        ui->Save_image->setVisible((false));
    }else{
        ui->Save_image->setVisible((true));
    }
}

void HarmonieDesCouleurs::on_actionQuitter_triggered() //Appui sur "menu > quitter"
{
    close();
}

void HarmonieDesCouleurs::on_Parcourir_clicked() //Appui pour choisir un fichier image *.ppm
{
    //QLabel* cheminFichier_label = new QLabel(this);
    cheminFichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Images *.ppm"));

    QFileInfo fileInfo(cheminFichier);
    nomFichier = fileInfo.fileName();

    if(!cheminFichier.isEmpty()){
        qDebug() << "Nom de fichier sélectionné : " << nomFichier;
        imageValide = true;
        imageIsSet(imageValide);
        ui->cheminParcourir->setText(cheminFichier);
        QImage image(cheminFichier);
        image = image.scaledToWidth(ui->init_image_label->width(),Qt::SmoothTransformation);

        if(!image.isNull()){
            //QLabel* image_label = new QLabel(this);
            ui->init_image_label -> setFixedSize((image.size()));
            ui->init_image_label -> setPixmap(QPixmap::fromImage(image));

            //Affichage du texte sur Image Modifiée
            ui->final_image_label->setText("Veuillez sélectionner une couleur...");
        }

    } else {
        qDebug() << "Aucun fichier sélectionné";
    }

}

void HarmonieDesCouleurs::colorChosen(bool colorChosenBool){ // Si conditions valides, on peut cliquer sur Générer Img
    if(!colorChosenBool){
        ui->GenererImgFinal->setEnabled(false);
    } else {
        ui->GenererImgFinal->setEnabled(true);
    }
}

QColor lastcolorChosenBool_colorSelector = Qt::white;

void HarmonieDesCouleurs::on_colorSelector_clicked() //Appui "choix couleur palette"
{
    QColorDialog dialog(this);
    dialog.setOption(QColorDialog::NoButtons);
    dialog.setCurrentColor(lastcolorChosenBool_colorSelector);

    QColor color = dialog.getColor(lastcolorChosenBool_colorSelector, this, tr("Choisir une couleur"), QColorDialog::ShowAlphaChannel | QColorDialog::DontUseNativeDialog);

    if(color.isValid()){
        lastcolorChosenBool_colorSelector = color;
        QString cssColor = color.name(QColor::HexRgb);
        ui->colorSelector->setStyleSheet(QString("background-color: %1").arg(cssColor));
        colorChosenQT = color;
        ui->colorChosenUI->setStyleSheet(QString("background-color: %1").arg(cssColor));
        colorChosenPixel.r = color.red();
        colorChosenPixel.g = color.green();
        colorChosenPixel.b = color.blue();
        colorChosenBool = true;
        colorChosen(colorChosenBool);
    }
}

void HarmonieDesCouleurs::on_actionCredits_triggered() //Appui "menu > crédits"
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




void HarmonieDesCouleurs::on_dom_colors_clicked() //Appui sur génération des couleurs dominantes
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
        genDomColor = true;
        ui->d_color_1->setEnabled(true);
        ui->d_color_2->setEnabled(true);
        ui->d_color_3->setEnabled(true);
        ui->d_color_4->setEnabled(true);

    } else {
        QDialog *ErreurFenetre = new QDialog(this);
        ErreurFenetre->setWindowTitle("Erreur");

        QLabel *ErreurTexte = new QLabel(ErreurFenetre);
        ErreurTexte->setText("<center>Attention erreur</center><br><br>"
                       "Il n'y a pas d'image choisie."
                       "<br>"
                       "<center>Sélectionnez une image valide.</center><br>");
        ErreurFenetre->setLayout(new QVBoxLayout());
        ErreurFenetre->layout()->addWidget((ErreurTexte));

        ErreurFenetre->exec();
    }
}

void HarmonieDesCouleurs::on_d_color_1_clicked()
{
    if(genDomColor){
        colorChosenQT = QColor((int)couleur1.r, (int)couleur1.b, (int)couleur1.b);
        colorChosenPixel = couleur1;
        ui->colorChosenUI->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur1.r).arg((int)couleur1.g).arg((int)couleur1.b));
        colorChosenBool = true;
        colorChosen(colorChosenBool);
    }
}

void HarmonieDesCouleurs::on_d_color_2_clicked()
{
    if(genDomColor){
        colorChosenQT = QColor((int)couleur2.r, (int)couleur2.b, (int)couleur2.b);
        colorChosenPixel = couleur2;
        ui->colorChosenUI->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur2.r).arg((int)couleur2.g).arg((int)couleur2.b));
        colorChosenBool = true;
        colorChosen(colorChosenBool);
    }
}


void HarmonieDesCouleurs::on_d_color_3_clicked()
{
    if(genDomColor){
        colorChosenQT = QColor((int)couleur3.r, (int)couleur3.b, (int)couleur3.b);
        colorChosenPixel = couleur3;
        ui->colorChosenUI->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur3.r).arg((int)couleur3.g).arg((int)couleur3.b));
        colorChosenBool = true;
        colorChosen(colorChosenBool);
    }
}

void HarmonieDesCouleurs::on_d_color_4_clicked()
{
    if(genDomColor){
        colorChosenQT = QColor((int)couleur4.r, (int)couleur4.b, (int)couleur4.b);
        colorChosenPixel = couleur4;
        ui->colorChosenUI->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg((int)couleur4.r).arg((int)couleur4.g).arg((int)couleur4.b));
        colorChosenBool = true;
        colorChosen(colorChosenBool);
    }
}



void HarmonieDesCouleurs::on_Supprimer_clicked() //Appui sur le bouton "Supprimer"
{
    if(imageValide){
        imageValide = false;
        imageModifiee = false;
        imageIsSet(imageValide);
        imageIsModified(imageModifiee);

        //Supprimer couleur choisie
        ui->colorChosenUI->setStyleSheet(QString(""));
        colorChosenBool = false;
        colorChosen(colorChosenBool);

        lastcolorChosenBool_colorSelector = Qt::white;
        ui->colorSelector->setStyleSheet(QString(""));

        //Supprimer les couleurs dominantes
        genDomColor = false;
        ui->d_color_1->setStyleSheet(QString(""));
        ui->d_color_2->setStyleSheet(QString(""));
        ui->d_color_3->setStyleSheet(QString(""));
        ui->d_color_4->setStyleSheet(QString(""));

        // Remettre Texte de la largeur de bande
        ui->horizontalSlider->setMaximum((359));
        ui->horizontalSlider->setValue(1);
        ui->valeurSlider->setText("(sélectionner une valeur)");

        // Remettre harmonie par défaut
        ui->radioB_Analogue->setChecked(true);

        //Supprimer fichier
        nomFichier = NULL;
        cheminFichier = "Chemin du fichier...";
        ui->cheminParcourir->setText(cheminFichier);

        //Clear images
        ui->init_image_label->clear();
        ui->init_image_label->setText("Choisir une image...");
        ui->final_image_label->clear();
        ui->final_image_label->setText("Veuillez sélectionner une image source...");


    } else {
        QDialog *ErreurFenetre = new QDialog(this);
        ErreurFenetre->setWindowTitle("Erreur");

        QLabel *ErreurTexte = new QLabel(ErreurFenetre);
        ErreurTexte->setText("<center>Attention erreur</center><br><br>"
                       "<center>Il n'y a pas d'image à supprimer.</center>");
        ErreurFenetre->setLayout(new QVBoxLayout());
        ErreurFenetre->layout()->addWidget((ErreurTexte));

        ErreurFenetre->exec();
    }
}



void HarmonieDesCouleurs::on_GenererImgFinal_clicked()
{
    if(imageValide && colorChosenBool){
        char nomImage[cheminFichier.length()+1];
        strcpy(nomImage,cheminFichier.toLocal8Bit().constData());
        qDebug() << nomImage;
        QImage oldimage("/tmp/Image_Transform.ppm");
        if(!oldimage.isNull()){
            oldimage.detach();
        }

        if(ui->radioB_Analogue->isChecked()){
            AnalogueHarmonyQT(colorChosenPixel, nomImage, (double)ui->horizontalSlider->value());
        }else if(ui->radioB_Complementaire->isChecked()){
            ComplementaryHarmonyQT(colorChosenPixel, nomImage, (double)ui->horizontalSlider->value());
        }else if(ui->radioB_Triadique->isChecked()){
            TriadiqueHarmonyQT(colorChosenPixel, nomImage, (double)ui->horizontalSlider->value());
        }else if(ui->radioB_Quadratique->isChecked()){
            SquareHarmonyQT(colorChosenPixel, nomImage, (double)ui->horizontalSlider->value());
        }

        QImage image("/tmp/Image_Transform.ppm");
        image = image.scaledToWidth(ui->final_image_label->width(),Qt::SmoothTransformation);
        ui->final_image_label->setFixedSize((image.size()));
        ui->final_image_label->setPixmap(QPixmap::fromImage(image));
        imageModifiee = true;
        imageIsModified(imageModifiee);

    }
}

void HarmonieDesCouleurs::on_Save_image_clicked()
{
    if(imageModifiee){
        QImage imageTransformee("/tmp/Image_Transform.ppm");
        QFileInfo info(cheminFichier);
        QString cheminFichierDosssier = info.path();

        QString nomFichierSaved = QFileDialog::getSaveFileName(this, tr("Sauvegarder l'image"), cheminFichierDosssier +"/nom_image.ppm", tr("Images *.ppm"));

        if (!nomFichierSaved.isEmpty()){
            if(imageTransformee.save(nomFichierSaved,"ppm")){
                qDebug() << "Image Sauvergardée.";
            }
        }else{
            return;
        }

    }
}

