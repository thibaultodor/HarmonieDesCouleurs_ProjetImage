/********************************************************************************
** Form generated from reading UI file 'harmoniedescouleurs.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARMONIEDESCOULEURS_H
#define UI_HARMONIEDESCOULEURS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HarmonieDesCouleurs
{
public:
    QAction *actionCredits;
    QAction *actionQuitter;
    QAction *actionAide_de_Harmonie_Des_Couleurs;
    QAction *actionParcourir;
    QAction *actionSupprimer;
    QAction *actionNouvelle_Fenetre;
    QAction *actionColorimetrie;
    QAction *actionExportPNG;
    QAction *actionImportPNG;
    QAction *actionImportJPEG;
    QAction *actionExportJPEG;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cheminParcourir;
    QPushButton *Parcourir;
    QPushButton *Supprimer;
    QSpacerItem *horizontalSpacer;
    QPushButton *colorSelector;
    QLabel *background;
    QFrame *init_polaroid;
    QFrame *init_fond_pola;
    QLabel *init_image_label;
    QLabel *init_legende;
    QFrame *final_polaroid;
    QFrame *final_fond_pola;
    QLabel *final_image_label;
    QLabel *final_legende;
    QPushButton *dom_colors;
    QPushButton *d_color_1;
    QPushButton *d_color_2;
    QPushButton *d_color_3;
    QPushButton *d_color_4;
    QPushButton *GenererImgFinal;
    QPushButton *colorChosenUI;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *choixHarmonieLayout;
    QLabel *radioB__Text;
    QRadioButton *radioB_Analogue;
    QRadioButton *radioB_Complementaire;
    QRadioButton *radioB_Triadique;
    QRadioButton *radioB_Quadratique;
    QLabel *radioB__Text_2;
    QLabel *valeurSlider;
    QSlider *horizontalSlider;
    QPushButton *Save_image;
    QPushButton *correction;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuImporterImg;
    QMenu *menuExporterImg;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HarmonieDesCouleurs)
    {
        if (HarmonieDesCouleurs->objectName().isEmpty())
            HarmonieDesCouleurs->setObjectName(QString::fromUtf8("HarmonieDesCouleurs"));
        HarmonieDesCouleurs->resize(960, 540);
        HarmonieDesCouleurs->setMinimumSize(QSize(960, 540));
        HarmonieDesCouleurs->setMaximumSize(QSize(960, 540));
        HarmonieDesCouleurs->setSizeIncrement(QSize(0, 0));
        HarmonieDesCouleurs->setBaseSize(QSize(0, 0));
        HarmonieDesCouleurs->setMouseTracking(false);
        HarmonieDesCouleurs->setContextMenuPolicy(Qt::DefaultContextMenu);
        HarmonieDesCouleurs->setWindowOpacity(1.000000000000000);
        HarmonieDesCouleurs->setAnimated(true);
        actionCredits = new QAction(HarmonieDesCouleurs);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        actionQuitter = new QAction(HarmonieDesCouleurs);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAide_de_Harmonie_Des_Couleurs = new QAction(HarmonieDesCouleurs);
        actionAide_de_Harmonie_Des_Couleurs->setObjectName(QString::fromUtf8("actionAide_de_Harmonie_Des_Couleurs"));
        actionParcourir = new QAction(HarmonieDesCouleurs);
        actionParcourir->setObjectName(QString::fromUtf8("actionParcourir"));
        actionSupprimer = new QAction(HarmonieDesCouleurs);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionNouvelle_Fenetre = new QAction(HarmonieDesCouleurs);
        actionNouvelle_Fenetre->setObjectName(QString::fromUtf8("actionNouvelle_Fenetre"));
        actionColorimetrie = new QAction(HarmonieDesCouleurs);
        actionColorimetrie->setObjectName(QString::fromUtf8("actionColorimetrie"));
        actionExportPNG = new QAction(HarmonieDesCouleurs);
        actionExportPNG->setObjectName(QString::fromUtf8("actionExportPNG"));
        actionImportPNG = new QAction(HarmonieDesCouleurs);
        actionImportPNG->setObjectName(QString::fromUtf8("actionImportPNG"));
        actionImportJPEG = new QAction(HarmonieDesCouleurs);
        actionImportJPEG->setObjectName(QString::fromUtf8("actionImportJPEG"));
        actionExportJPEG = new QAction(HarmonieDesCouleurs);
        actionExportJPEG->setObjectName(QString::fromUtf8("actionExportJPEG"));
        centralwidget = new QWidget(HarmonieDesCouleurs);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 4, 941, 50));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(25, 0, 25, 0);
        cheminParcourir = new QLabel(horizontalLayoutWidget);
        cheminParcourir->setObjectName(QString::fromUtf8("cheminParcourir"));
        cheminParcourir->setMaximumSize(QSize(700, 40));
        cheminParcourir->setAutoFillBackground(false);
        cheminParcourir->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 20px;\n"
"font: 11pt \"Sawasdee\";\n"
""));
        cheminParcourir->setFrameShadow(QFrame::Sunken);
        cheminParcourir->setLineWidth(0);
        cheminParcourir->setScaledContents(true);
        cheminParcourir->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cheminParcourir->setIndent(15);

        horizontalLayout_3->addWidget(cheminParcourir);

        Parcourir = new QPushButton(horizontalLayoutWidget);
        Parcourir->setObjectName(QString::fromUtf8("Parcourir"));
        Parcourir->setMaximumSize(QSize(80, 25));
        Parcourir->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        horizontalLayout_3->addWidget(Parcourir);

        Supprimer = new QPushButton(horizontalLayoutWidget);
        Supprimer->setObjectName(QString::fromUtf8("Supprimer"));
        Supprimer->setMaximumSize(QSize(80, 25));
        Supprimer->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        horizontalLayout_3->addWidget(Supprimer);

        horizontalSpacer = new QSpacerItem(100, 36, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        colorSelector = new QPushButton(centralwidget);
        colorSelector->setObjectName(QString::fromUtf8("colorSelector"));
        colorSelector->setGeometry(QRect(380, 60, 200, 30));
        colorSelector->setCursor(QCursor(Qt::ArrowCursor));
        colorSelector->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setEnabled(false);
        background->setGeometry(QRect(0, 0, 960, 520));
        background->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"background-image:url(\"../HarmonieDesCouleurs/background1920.jpg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center;"));
        init_polaroid = new QFrame(centralwidget);
        init_polaroid->setObjectName(QString::fromUtf8("init_polaroid"));
        init_polaroid->setGeometry(QRect(40, 60, 320, 360));
        init_polaroid->setAutoFillBackground(false);
        init_polaroid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        init_polaroid->setFrameShape(QFrame::StyledPanel);
        init_polaroid->setFrameShadow(QFrame::Raised);
        init_fond_pola = new QFrame(init_polaroid);
        init_fond_pola->setObjectName(QString::fromUtf8("init_fond_pola"));
        init_fond_pola->setGeometry(QRect(10, 10, 300, 300));
        init_fond_pola->setAutoFillBackground(false);
        init_fond_pola->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        init_fond_pola->setFrameShape(QFrame::StyledPanel);
        init_fond_pola->setFrameShadow(QFrame::Plain);
        init_fond_pola->setLineWidth(1);
        init_image_label = new QLabel(init_fond_pola);
        init_image_label->setObjectName(QString::fromUtf8("init_image_label"));
        init_image_label->setGeometry(QRect(0, 0, 300, 300));
        QFont font;
        font.setItalic(true);
        init_image_label->setFont(font);
        init_image_label->setCursor(QCursor(Qt::ArrowCursor));
        init_image_label->setScaledContents(false);
        init_image_label->setAlignment(Qt::AlignCenter);
        init_image_label->setWordWrap(false);
        init_legende = new QLabel(init_polaroid);
        init_legende->setObjectName(QString::fromUtf8("init_legende"));
        init_legende->setGeometry(QRect(10, 325, 300, 21));
        init_legende->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Purisa\";"));
        init_legende->setAlignment(Qt::AlignCenter);
        final_polaroid = new QFrame(centralwidget);
        final_polaroid->setObjectName(QString::fromUtf8("final_polaroid"));
        final_polaroid->setGeometry(QRect(600, 60, 320, 360));
        final_polaroid->setAutoFillBackground(false);
        final_polaroid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        final_polaroid->setFrameShape(QFrame::StyledPanel);
        final_polaroid->setFrameShadow(QFrame::Raised);
        final_fond_pola = new QFrame(final_polaroid);
        final_fond_pola->setObjectName(QString::fromUtf8("final_fond_pola"));
        final_fond_pola->setGeometry(QRect(10, 10, 300, 300));
        final_fond_pola->setAutoFillBackground(false);
        final_fond_pola->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        final_fond_pola->setFrameShape(QFrame::StyledPanel);
        final_fond_pola->setFrameShadow(QFrame::Plain);
        final_fond_pola->setLineWidth(1);
        final_image_label = new QLabel(final_fond_pola);
        final_image_label->setObjectName(QString::fromUtf8("final_image_label"));
        final_image_label->setGeometry(QRect(0, 0, 300, 300));
        final_image_label->setFont(font);
        final_image_label->setCursor(QCursor(Qt::ArrowCursor));
        final_image_label->setScaledContents(false);
        final_image_label->setAlignment(Qt::AlignCenter);
        final_image_label->setWordWrap(false);
        final_legende = new QLabel(final_polaroid);
        final_legende->setObjectName(QString::fromUtf8("final_legende"));
        final_legende->setGeometry(QRect(10, 325, 300, 21));
        final_legende->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Purisa\";"));
        final_legende->setAlignment(Qt::AlignCenter);
        dom_colors = new QPushButton(centralwidget);
        dom_colors->setObjectName(QString::fromUtf8("dom_colors"));
        dom_colors->setGeometry(QRect(50, 423, 300, 30));
        dom_colors->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        d_color_1 = new QPushButton(centralwidget);
        d_color_1->setObjectName(QString::fromUtf8("d_color_1"));
        d_color_1->setEnabled(true);
        d_color_1->setGeometry(QRect(120, 455, 40, 40));
        d_color_1->setCheckable(false);
        d_color_2 = new QPushButton(centralwidget);
        d_color_2->setObjectName(QString::fromUtf8("d_color_2"));
        d_color_2->setGeometry(QRect(160, 455, 40, 40));
        d_color_3 = new QPushButton(centralwidget);
        d_color_3->setObjectName(QString::fromUtf8("d_color_3"));
        d_color_3->setGeometry(QRect(200, 455, 40, 40));
        d_color_4 = new QPushButton(centralwidget);
        d_color_4->setObjectName(QString::fromUtf8("d_color_4"));
        d_color_4->setGeometry(QRect(240, 455, 40, 40));
        GenererImgFinal = new QPushButton(centralwidget);
        GenererImgFinal->setObjectName(QString::fromUtf8("GenererImgFinal"));
        GenererImgFinal->setGeometry(QRect(660, 423, 200, 30));
        GenererImgFinal->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        colorChosenUI = new QPushButton(centralwidget);
        colorChosenUI->setObjectName(QString::fromUtf8("colorChosenUI"));
        colorChosenUI->setGeometry(QRect(440, 410, 80, 80));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(380, 100, 201, 263));
        choixHarmonieLayout = new QVBoxLayout(verticalLayoutWidget);
        choixHarmonieLayout->setObjectName(QString::fromUtf8("choixHarmonieLayout"));
        choixHarmonieLayout->setContentsMargins(0, 0, 0, 0);
        radioB__Text = new QLabel(verticalLayoutWidget);
        radioB__Text->setObjectName(QString::fromUtf8("radioB__Text"));
        radioB__Text->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        choixHarmonieLayout->addWidget(radioB__Text);

        radioB_Analogue = new QRadioButton(verticalLayoutWidget);
        radioB_Analogue->setObjectName(QString::fromUtf8("radioB_Analogue"));
        radioB_Analogue->setEnabled(true);
        radioB_Analogue->setCursor(QCursor(Qt::PointingHandCursor));
        radioB_Analogue->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        radioB_Analogue->setChecked(true);

        choixHarmonieLayout->addWidget(radioB_Analogue);

        radioB_Complementaire = new QRadioButton(verticalLayoutWidget);
        radioB_Complementaire->setObjectName(QString::fromUtf8("radioB_Complementaire"));
        radioB_Complementaire->setCursor(QCursor(Qt::PointingHandCursor));
        radioB_Complementaire->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        choixHarmonieLayout->addWidget(radioB_Complementaire);

        radioB_Triadique = new QRadioButton(verticalLayoutWidget);
        radioB_Triadique->setObjectName(QString::fromUtf8("radioB_Triadique"));
        radioB_Triadique->setCursor(QCursor(Qt::PointingHandCursor));
        radioB_Triadique->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        choixHarmonieLayout->addWidget(radioB_Triadique);

        radioB_Quadratique = new QRadioButton(verticalLayoutWidget);
        radioB_Quadratique->setObjectName(QString::fromUtf8("radioB_Quadratique"));
        radioB_Quadratique->setCursor(QCursor(Qt::PointingHandCursor));
        radioB_Quadratique->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        choixHarmonieLayout->addWidget(radioB_Quadratique);

        radioB__Text_2 = new QLabel(verticalLayoutWidget);
        radioB__Text_2->setObjectName(QString::fromUtf8("radioB__Text_2"));
        radioB__Text_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));

        choixHarmonieLayout->addWidget(radioB__Text_2);

        valeurSlider = new QLabel(verticalLayoutWidget);
        valeurSlider->setObjectName(QString::fromUtf8("valeurSlider"));
        valeurSlider->setStyleSheet(QString::fromUtf8("font: oblique 11pt \"Sawasdee\";"));
        valeurSlider->setAlignment(Qt::AlignCenter);

        choixHarmonieLayout->addWidget(valeurSlider);

        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(359);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(10);

        choixHarmonieLayout->addWidget(horizontalSlider);

        Save_image = new QPushButton(centralwidget);
        Save_image->setObjectName(QString::fromUtf8("Save_image"));
        Save_image->setEnabled(true);
        Save_image->setGeometry(QRect(660, 456, 200, 30));
        Save_image->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        Save_image->setCheckable(false);
        Save_image->setAutoDefault(false);
        Save_image->setFlat(false);
        correction = new QPushButton(centralwidget);
        correction->setObjectName(QString::fromUtf8("correction"));
        correction->setGeometry(QRect(870, 440, 80, 30));
        correction->setStyleSheet(QString::fromUtf8("font: 11pt \"Sawasdee\";"));
        HarmonieDesCouleurs->setCentralWidget(centralwidget);
        background->raise();
        horizontalLayoutWidget->raise();
        colorSelector->raise();
        init_polaroid->raise();
        final_polaroid->raise();
        dom_colors->raise();
        d_color_1->raise();
        d_color_2->raise();
        d_color_3->raise();
        d_color_4->raise();
        GenererImgFinal->raise();
        colorChosenUI->raise();
        verticalLayoutWidget->raise();
        Save_image->raise();
        correction->raise();
        menubar = new QMenuBar(HarmonieDesCouleurs);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuImporterImg = new QMenu(menuMenu);
        menuImporterImg->setObjectName(QString::fromUtf8("menuImporterImg"));
        menuExporterImg = new QMenu(menuMenu);
        menuExporterImg->setObjectName(QString::fromUtf8("menuExporterImg"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        HarmonieDesCouleurs->setMenuBar(menubar);
        statusbar = new QStatusBar(HarmonieDesCouleurs);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(false);
        statusbar->setSizeGripEnabled(false);
        HarmonieDesCouleurs->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuMenu->addAction(actionParcourir);
        menuMenu->addAction(menuImporterImg->menuAction());
        menuMenu->addAction(menuExporterImg->menuAction());
        menuMenu->addAction(actionSupprimer);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);
        menuImporterImg->addAction(actionImportPNG);
        menuImporterImg->addAction(actionImportJPEG);
        menuExporterImg->addAction(actionExportPNG);
        menuExporterImg->addAction(actionExportJPEG);
        menuAide->addAction(actionColorimetrie);
        menuAide->addAction(actionAide_de_Harmonie_Des_Couleurs);
        menuAide->addSeparator();
        menuAide->addAction(actionCredits);

        retranslateUi(HarmonieDesCouleurs);

        Save_image->setDefault(false);


        QMetaObject::connectSlotsByName(HarmonieDesCouleurs);
    } // setupUi

    void retranslateUi(QMainWindow *HarmonieDesCouleurs)
    {
        HarmonieDesCouleurs->setWindowTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Harmonie Des Couleurs", nullptr));
        actionCredits->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Cr\303\251dits", nullptr));
#if QT_CONFIG(tooltip)
        actionCredits->setToolTip(QCoreApplication::translate("HarmonieDesCouleurs", "Cr\303\251dits", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQuitter->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Quitter", nullptr));
        actionAide_de_Harmonie_Des_Couleurs->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Aide sur Harmonie Des Couleurs", nullptr));
        actionParcourir->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Parcourir", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Supprimer", nullptr));
        actionNouvelle_Fenetre->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Nouvelle Fen\303\252tre", nullptr));
        actionColorimetrie->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Aide Colorimetrie", nullptr));
        actionExportPNG->setText(QCoreApplication::translate("HarmonieDesCouleurs", "au format PNG", nullptr));
        actionImportPNG->setText(QCoreApplication::translate("HarmonieDesCouleurs", "au format PNG", nullptr));
        actionImportJPEG->setText(QCoreApplication::translate("HarmonieDesCouleurs", "au format JPEG", nullptr));
        actionExportJPEG->setText(QCoreApplication::translate("HarmonieDesCouleurs", "au format JPEG", nullptr));
        cheminParcourir->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Chemin du fichier...", nullptr));
        Parcourir->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Parcourir", nullptr));
        Supprimer->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Supprimer", nullptr));
        colorSelector->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Choix couleur sur la palette", nullptr));
        background->setText(QString());
        init_image_label->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Choisir une image...", nullptr));
        init_legende->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Image Originale", nullptr));
        final_image_label->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Veuillez s\303\251lectionner une image source...", nullptr));
        final_legende->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Image Modifi\303\251e", nullptr));
        dom_colors->setText(QCoreApplication::translate("HarmonieDesCouleurs", "G\303\251n\303\251ration couleurs dominantes", nullptr));
        d_color_1->setText(QString());
        d_color_2->setText(QString());
        d_color_3->setText(QString());
        d_color_4->setText(QString());
        GenererImgFinal->setText(QCoreApplication::translate("HarmonieDesCouleurs", "G\303\251n\303\251rer image", nullptr));
        colorChosenUI->setText(QString());
        radioB__Text->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Choix de l'harmonie :", nullptr));
        radioB_Analogue->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Analogue", nullptr));
        radioB_Complementaire->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Complementaire", nullptr));
        radioB_Triadique->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Triadique", nullptr));
        radioB_Quadratique->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Quadratique", nullptr));
        radioB__Text_2->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Largeur de la bande :", nullptr));
        valeurSlider->setText(QCoreApplication::translate("HarmonieDesCouleurs", "(s\303\251lectionner une valeur)", nullptr));
        Save_image->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Sauvegarder l'image", nullptr));
        correction->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Correction", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Fichier", nullptr));
        menuImporterImg->setTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Importer...", nullptr));
        menuExporterImg->setTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Exporter...", nullptr));
        menuAide->setTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HarmonieDesCouleurs: public Ui_HarmonieDesCouleurs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARMONIEDESCOULEURS_H
