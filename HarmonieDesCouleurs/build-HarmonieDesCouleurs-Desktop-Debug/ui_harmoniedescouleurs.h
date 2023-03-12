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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HarmonieDesCouleurs
{
public:
    QAction *actionCredits;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cheminParcourir;
    QPushButton *Parcourir;
    QSpacerItem *horizontalSpacer;
    QPushButton *colorSelector;
    QLabel *background;
    QFrame *frame_2;
    QFrame *frame;
    QLabel *image_label;
    QLabel *legende;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HarmonieDesCouleurs)
    {
        if (HarmonieDesCouleurs->objectName().isEmpty())
            HarmonieDesCouleurs->setObjectName(QString::fromUtf8("HarmonieDesCouleurs"));
        HarmonieDesCouleurs->resize(960, 540);
        HarmonieDesCouleurs->setMinimumSize(QSize(960, 540));
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
        centralwidget = new QWidget(HarmonieDesCouleurs);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 941, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(25, 0, 25, 0);
        cheminParcourir = new QLabel(horizontalLayoutWidget);
        cheminParcourir->setObjectName(QString::fromUtf8("cheminParcourir"));
        cheminParcourir->setAutoFillBackground(false);
        cheminParcourir->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 20px;\n"
"font: 11pt \"Sawasdee\";\n"
""));
        cheminParcourir->setFrameShadow(QFrame::Sunken);
        cheminParcourir->setLineWidth(0);
        cheminParcourir->setScaledContents(true);

        horizontalLayout_3->addWidget(cheminParcourir);

        Parcourir = new QPushButton(horizontalLayoutWidget);
        Parcourir->setObjectName(QString::fromUtf8("Parcourir"));
        Parcourir->setMaximumSize(QSize(80, 25));
        Parcourir->setStyleSheet(QString::fromUtf8("font: 11pt \"Dyuthi\";"));

        horizontalLayout_3->addWidget(Parcourir);

        horizontalSpacer = new QSpacerItem(150, 36, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        colorSelector = new QPushButton(centralwidget);
        colorSelector->setObjectName(QString::fromUtf8("colorSelector"));
        colorSelector->setGeometry(QRect(420, 70, 201, 31));
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setEnabled(false);
        background->setGeometry(QRect(0, 0, 960, 520));
        background->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"background-image:url(\"../HarmonieDesCouleurs/background1920.jpg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center;"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(40, 60, 320, 360));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 300, 300));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(1);
        image_label = new QLabel(frame);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(0, 0, 300, 300));
        QFont font;
        font.setItalic(true);
        image_label->setFont(font);
        image_label->setScaledContents(false);
        image_label->setAlignment(Qt::AlignCenter);
        image_label->setWordWrap(false);
        legende = new QLabel(frame_2);
        legende->setObjectName(QString::fromUtf8("legende"));
        legende->setGeometry(QRect(10, 325, 300, 21));
        legende->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Purisa\";"));
        legende->setAlignment(Qt::AlignCenter);
        HarmonieDesCouleurs->setCentralWidget(centralwidget);
        background->raise();
        horizontalLayoutWidget->raise();
        colorSelector->raise();
        frame_2->raise();
        menubar = new QMenuBar(HarmonieDesCouleurs);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        HarmonieDesCouleurs->setMenuBar(menubar);
        statusbar = new QStatusBar(HarmonieDesCouleurs);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HarmonieDesCouleurs->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionCredits);
        menuMenu->addAction(actionQuitter);

        retranslateUi(HarmonieDesCouleurs);

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
        cheminParcourir->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Chemin du fichier...", nullptr));
        Parcourir->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Parcourir", nullptr));
        colorSelector->setText(QCoreApplication::translate("HarmonieDesCouleurs", "S\303\251lectionner une couleur", nullptr));
        background->setText(QString());
        image_label->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Choisir une image...", nullptr));
        legende->setText(QCoreApplication::translate("HarmonieDesCouleurs", "Image Originale", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("HarmonieDesCouleurs", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HarmonieDesCouleurs: public Ui_HarmonieDesCouleurs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARMONIEDESCOULEURS_H
