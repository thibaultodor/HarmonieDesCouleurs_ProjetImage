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

/* MENU APP */
void HarmonieDesCouleurs::on_actionParcourir_triggered(){
    on_Parcourir_clicked();
}

void HarmonieDesCouleurs::on_actionSupprimer_triggered(){
    on_Supprimer_clicked();
}

void HarmonieDesCouleurs::on_actionCredits_triggered() //Appui "menu > crédits"
{
    QDialog *creditsFenetre = new QDialog(this);
    creditsFenetre->setWindowTitle("Crédits");
    creditsFenetre->setFixedWidth(300);

    QImage *creditsImage = new QImage("../HarmonieDesCouleurs/authors.png");
    QImage creditsImageResized = creditsImage->scaledToWidth(64,Qt::SmoothTransformation);
    QLabel* creditsLabel = new QLabel();
    creditsLabel->setPixmap(QPixmap::fromImage(creditsImageResized));
    creditsLabel->show();

    QLabel *creditsTexte = new QLabel(creditsFenetre);
    creditsTexte->setText("<br>Développée par :"
                          "<p style='text-align: right;'>Christina MAURIN<br>Thibault ODOR</p>"
                          "<center>M1 Imagine - 2023</center>"
                          "<br>"
                          "Basée sur Qt et C++<br>"
                          "Crédits background : Vecteezy <br>"
                          "Crédits icones : juicy_fish"
                          "<br><br>"
                          "Merci d'utiliser l'application !<br>");

    QPushButton *creditsBouton = new QPushButton(creditsFenetre);
    creditsBouton->setText("Fermer");
    creditsBouton->setFixedSize(80,25);

    QFont font("Sawasdee", 11);
    creditsTexte->setFont(font);
    creditsBouton->setFont(font);


    QObject::connect(creditsBouton, &QPushButton::clicked, creditsFenetre, &QDialog::close);


    QVBoxLayout *layout = new QVBoxLayout(creditsFenetre);
    layout->addWidget(creditsLabel, 0, Qt::AlignCenter);
    layout->addWidget(creditsTexte);
    layout->addWidget(creditsBouton, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    creditsFenetre->exec();
}

void HarmonieDesCouleurs::on_actionQuitter_triggered() //Appui sur "menu > quitter"
{
    close();
}

void HarmonieDesCouleurs::on_actionColorimetrie_triggered(){
    QDialog *aideFenetre = new QDialog(this);
    aideFenetre->setWindowTitle("Aide");
    aideFenetre->setFixedSize(400,350);

    //Logo
    QImage *aideImage = new QImage("../HarmonieDesCouleurs/colors.png");
    QImage aideImageResized = aideImage->scaledToWidth(64,Qt::SmoothTransformation);
    QLabel* aideLabel = new QLabel();
    aideLabel->setPixmap(QPixmap::fromImage(aideImageResized));
    aideLabel->show();

    //Analagoue
    QLabel *harmoTexte1 = new QLabel(aideFenetre);
    harmoTexte1->setText("Analogue");

    QImage *harmoImage1 = new QImage("../HarmonieDesCouleurs/Analogue.png");
    QImage harmonImage1Resized = harmoImage1->scaledToWidth(100,Qt::SmoothTransformation);
    QLabel* harmonImage1Label = new QLabel();
    harmonImage1Label->setPixmap(QPixmap::fromImage(harmonImage1Resized));
    harmonImage1Label->show();

    //Complementaire
    QLabel *harmoTexte2 = new QLabel(aideFenetre);
    harmoTexte2->setText("Complémentaire");

    QImage *harmoImage2 = new QImage("../HarmonieDesCouleurs/Complementaire.png");
    QImage harmonImage2Resized = harmoImage2->scaledToWidth(100,Qt::SmoothTransformation);
    QLabel* harmonImage2Label = new QLabel();
    harmonImage2Label->setPixmap(QPixmap::fromImage(harmonImage2Resized));
    harmonImage2Label->show();

    //Triadique
    QLabel *harmoTexte3 = new QLabel(aideFenetre);
    harmoTexte3->setText("Triadique");

    QImage *harmoImage3 = new QImage("../HarmonieDesCouleurs/Triadique.png");
    QImage harmonImage3Resized = harmoImage3->scaledToWidth(100,Qt::SmoothTransformation);
    QLabel* harmonImage3Label = new QLabel();
    harmonImage3Label->setPixmap(QPixmap::fromImage(harmonImage3Resized));
    harmonImage3Label->show();

    //Quadratique
    QLabel *harmoTexte4 = new QLabel(aideFenetre);
    harmoTexte4->setText("Quadratique");

    QImage *harmoImage4 = new QImage("../HarmonieDesCouleurs/Quadratique.png");
    QImage harmonImage4Resized = harmoImage4->scaledToWidth(100,Qt::SmoothTransformation);
    QLabel* harmonImage4Label = new QLabel();
    harmonImage4Label->setPixmap(QPixmap::fromImage(harmonImage4Resized));
    harmonImage4Label->show();

    //Boutons
    QPushButton *aideBouton = new QPushButton(aideFenetre);
    aideBouton->setText("Fermer");
    aideBouton->setFixedSize(80,25);

    QPushButton *aideBoutonPrecedent = new QPushButton(aideFenetre);
    aideBoutonPrecedent->setText("<");
    aideBoutonPrecedent->setFixedSize(25,25);

    QPushButton *aideBoutonSuivant = new QPushButton(aideFenetre);
    aideBoutonSuivant->setText(">");
    aideBoutonSuivant->setFixedSize(25,25);

    //Font
    QFont font("Sawasdee", 11);
    harmoTexte1->setFont(font);
    harmoTexte2->setFont(font);
    harmoTexte3->setFont(font);
    harmoTexte4->setFont(font);
    aideBouton->setFont(font);
    aideBoutonPrecedent->setFont(font);
    aideBoutonSuivant->setFont(font);

    //Connexion éléments
    QObject::connect(aideBouton, &QPushButton::clicked, aideFenetre, &QDialog::close);

    int indiceTexte = 0;
    aideBoutonPrecedent->setEnabled(false);
    harmoTexte2->setVisible(false);
    harmoTexte3->setVisible(false);
    harmoTexte4->setVisible(false);
    harmonImage2Label->setVisible(false);
    harmonImage3Label->setVisible(false);
    harmonImage4Label->setVisible(false);
    QObject::connect(aideBoutonPrecedent, &QPushButton::clicked, [aideBoutonPrecedent, aideBoutonSuivant, harmoTexte1, harmoTexte2, harmoTexte3, harmoTexte4, harmonImage1Label, harmonImage2Label,harmonImage3Label, harmonImage4Label, &indiceTexte]() {
            indiceTexte--;
            if (indiceTexte < 0) {
                indiceTexte = 3;
            }
            if (indiceTexte == 0) {
                aideBoutonPrecedent->setEnabled(false);
                aideBoutonSuivant->setEnabled(true);
            }else{
                aideBoutonPrecedent->setEnabled(true);
                aideBoutonSuivant->setEnabled(true);
            }
            harmoTexte1->setVisible(indiceTexte == 0);
            harmoTexte2->setVisible(indiceTexte == 1);
            harmoTexte3->setVisible(indiceTexte == 2);
            harmoTexte4->setVisible(indiceTexte == 3);
            harmonImage1Label->setVisible(indiceTexte == 0);
            harmonImage2Label->setVisible(indiceTexte == 1);
            harmonImage3Label->setVisible(indiceTexte == 2);
            harmonImage4Label->setVisible(indiceTexte == 3);
        });

    QObject::connect(aideBoutonSuivant, &QPushButton::clicked, [aideBoutonPrecedent, aideBoutonSuivant, harmoTexte1, harmoTexte2, harmoTexte3, harmoTexte4, harmonImage1Label, harmonImage2Label,harmonImage3Label, harmonImage4Label, &indiceTexte]() {
            indiceTexte++;
            if (indiceTexte > 3) {
                indiceTexte = 0;
            }
            if (indiceTexte == 3) {
                aideBoutonSuivant->setEnabled(false);
                aideBoutonPrecedent->setEnabled(true);
            }else{
                aideBoutonSuivant->setEnabled(true);
                aideBoutonPrecedent->setEnabled(true);
            }
            harmoTexte1->setVisible(indiceTexte == 0);
            harmoTexte2->setVisible(indiceTexte == 1);
            harmoTexte3->setVisible(indiceTexte == 2);
            harmoTexte4->setVisible(indiceTexte == 3);
            harmonImage1Label->setVisible(indiceTexte == 0);
            harmonImage2Label->setVisible(indiceTexte == 1);
            harmonImage3Label->setVisible(indiceTexte == 2);
            harmonImage4Label->setVisible(indiceTexte == 3);
        });

    //Layout Bouton
    QHBoxLayout *layoutBoutons = new QHBoxLayout();
    layoutBoutons->addWidget(aideBoutonPrecedent);
    layoutBoutons->addWidget(aideBouton);
    layoutBoutons->addWidget(aideBoutonSuivant);

    //Layout général
    QVBoxLayout *layout = new QVBoxLayout(aideFenetre);
    layout->addWidget(aideLabel, 0, Qt::AlignCenter);
    layout->addWidget(harmoTexte1, 0, Qt::AlignCenter);
    layout->addWidget(harmonImage1Label, 0, Qt::AlignCenter);
    layout->addWidget(harmoTexte2, 0, Qt::AlignCenter);
    layout->addWidget(harmonImage2Label, 0, Qt::AlignCenter);
    layout->addWidget(harmoTexte3, 0, Qt::AlignCenter);
    layout->addWidget(harmonImage3Label, 0, Qt::AlignCenter);
    layout->addWidget(harmoTexte4, 0, Qt::AlignCenter);
    layout->addWidget(harmonImage4Label, 0, Qt::AlignCenter);
    layout->addLayout(layoutBoutons);
    layout->setAlignment(Qt::AlignCenter);

    aideFenetre->exec();
}

void HarmonieDesCouleurs::on_actionAide_de_Harmonie_Des_Couleurs_triggered(){
    QDialog *aideFenetre = new QDialog(this);
    aideFenetre->setWindowTitle("Aide");

    QImage *aideImage = new QImage("../HarmonieDesCouleurs/info.png");
    QImage aideImageResized = aideImage->scaledToWidth(64,Qt::SmoothTransformation);
    QLabel* aideLabel = new QLabel();
    aideLabel->setPixmap(QPixmap::fromImage(aideImageResized));
    aideLabel->show();

    QLabel *aideTexte = new QLabel(aideFenetre);
    aideTexte->setText("<br>Cette application permet d'harmoniser les couleurs d'une image :<br>"
                       "1 - Importer une image avec le bouton Parcourir <br>"
                       "2 - Sélectionner la couleur principale : <br>"
                       "---- Soit via le générateur de couleurs dominantes : <br>"
                       "-------- Cliquer sur générer puis choisir une des 4 couleurs<br>"
                       "---- Soit via la sélection avec la palette <br>"
                       "3 - Choisir le type d'harmonisation <br>"
                       "4 - Choisir la largeur de la bande de l'harmonisation <br>"
                       "<i>(Choisir 360 rendra un résultat similaire à l'image originale)</i><br>"
                       "5 - Cliquer sur générer l'image <br>"
                       "6 - Enregistrer l'image sur votre ordinateur <i>(optionnel)</i><br>");

    QPushButton *aideBouton = new QPushButton(aideFenetre);
    aideBouton->setText("Fermer");
    aideBouton->setFixedSize(80,25);

    QFont font("Sawasdee", 11);
    aideTexte->setFont(font);
    aideBouton->setFont(font);


    QObject::connect(aideBouton, &QPushButton::clicked, aideFenetre, &QDialog::close);


    QVBoxLayout *layout = new QVBoxLayout(aideFenetre);
    layout->addWidget(aideLabel, 0, Qt::AlignCenter);
    layout->addWidget(aideTexte);
    layout->addWidget(aideBouton, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    aideFenetre->exec();


}

/* DEBUT CONTENU APP */
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
        QDialog *erreurFenetre = new QDialog(this);
        erreurFenetre->setWindowTitle("Erreur");

        QImage *erreurImage = new QImage("../HarmonieDesCouleurs/erreur.png");
        QImage erreurImageResized = erreurImage->scaledToWidth(64,Qt::SmoothTransformation);
        QLabel* erreurLabel = new QLabel();
        erreurLabel->setPixmap(QPixmap::fromImage(erreurImageResized));
        erreurLabel->show();

        QLabel *erreurTexte = new QLabel(erreurFenetre);
        erreurTexte->setText("<cbr><center>Attention erreur</center><br>"
                       "Il n'y a pas d'image choisie."
                       "<br>"
                       "<center>Sélectionnez une image valide.</center><br>");

        QPushButton *erreurBouton = new QPushButton(erreurFenetre);
        erreurBouton->setText("Fermer");
        erreurBouton->setFixedSize(80,25);

        QFont font("Sawasdee", 11);
        erreurTexte->setFont(font);
        erreurBouton->setFont(font);

        QObject::connect(erreurBouton, &QPushButton::clicked, erreurFenetre, &QDialog::close);

        QVBoxLayout *layout = new QVBoxLayout(erreurFenetre);
        layout->addWidget(erreurLabel, 0, Qt::AlignCenter);
        layout->addWidget(erreurTexte);
        layout->addWidget(erreurBouton, 0, Qt::AlignCenter);
        layout->setAlignment(Qt::AlignCenter);

        erreurFenetre->exec();
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
        QDialog *erreurFenetre = new QDialog(this);
        erreurFenetre->setWindowTitle("Erreur");

        QImage *erreurImage = new QImage("../HarmonieDesCouleurs/erreur.png");
        QImage erreurImageResized = erreurImage->scaledToWidth(64,Qt::SmoothTransformation);
        QLabel* erreurLabel = new QLabel();
        erreurLabel->setPixmap(QPixmap::fromImage(erreurImageResized));
        erreurLabel->show();

        QLabel *erreurTexte = new QLabel(erreurFenetre);
        erreurTexte->setText("<center><b>Attention erreur :<br>"
                       "Il n'y a pas d'image à supprimer.</b></center>");

        QPushButton *erreurBouton = new QPushButton(erreurFenetre);
        erreurBouton->setText("Fermer");
        erreurBouton->setFixedSize(80,25);

        QFont font("Sawasdee", 11);
        erreurTexte->setFont(font);
        erreurBouton->setFont(font);


        QObject::connect(erreurBouton, &QPushButton::clicked, erreurFenetre, &QDialog::close);


        QVBoxLayout *layout = new QVBoxLayout(erreurFenetre);
        layout->addWidget(erreurLabel, 0, Qt::AlignCenter);
        layout->addWidget(erreurTexte);
        layout->addWidget(erreurBouton, 0, Qt::AlignCenter);
        layout->setAlignment(Qt::AlignCenter);

        erreurFenetre->exec();
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

                QDialog *SavedFenetre = new QDialog(this);
                SavedFenetre->setWindowTitle("Information");

                QImage *savedImage = new QImage("../HarmonieDesCouleurs/saved.png");
                QImage savedImageResized = savedImage->scaledToWidth(64,Qt::SmoothTransformation);
                QLabel* savedLabel = new QLabel();
                savedLabel->setPixmap(QPixmap::fromImage(savedImageResized));
                savedLabel->show();

                QLabel *SavedTexte = new QLabel(SavedFenetre);
                SavedTexte->setText("<center>Votre image a bien été sauvergardée.</center>");
                QPushButton *SavedBouton = new QPushButton(SavedFenetre);
                SavedBouton->setText("Fermer");
                SavedBouton->setFixedSize(80,25);

                QFont font("Sawasdee", 11);
                SavedTexte->setFont(font);
                SavedBouton->setFont(font);


                QObject::connect(SavedBouton, &QPushButton::clicked, SavedFenetre, &QDialog::close);


                QVBoxLayout *layout = new QVBoxLayout(SavedFenetre);
                layout->addWidget(savedLabel, 0, Qt::AlignCenter);
                layout->addWidget(SavedTexte);
                layout->addWidget(SavedBouton, 0, Qt::AlignCenter);
                layout->setAlignment(Qt::AlignCenter);

                SavedFenetre->exec();
            }
        }else{
            return;
        }

    }
}

