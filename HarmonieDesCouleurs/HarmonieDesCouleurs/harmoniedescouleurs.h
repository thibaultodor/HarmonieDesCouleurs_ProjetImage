#ifndef HARMONIEDESCOULEURS_H
#define HARMONIEDESCOULEURS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HarmonieDesCouleurs; }
QT_END_NAMESPACE

class HarmonieDesCouleurs : public QMainWindow
{
    Q_OBJECT

public:
    HarmonieDesCouleurs(QWidget *parent = nullptr);
    ~HarmonieDesCouleurs();

private slots:
    void on_actionParcourir_triggered();

    void on_actionSupprimer_triggered();

    void on_actionCredits_triggered();

    void on_actionQuitter_triggered();

    void on_actionColorimetrie_triggered();

    void on_actionAide_de_Harmonie_Des_Couleurs_triggered();

    void on_Parcourir_clicked();

    void imageIsSet(bool imageValide);

    void colorChosen(bool colorChosenBool);

    void on_colorSelector_clicked();

    void imageIsModified(bool imageModifiee);

    void on_dom_colors_clicked();

    void on_Supprimer_clicked();

    void on_d_color_1_clicked();

    void on_d_color_2_clicked();

    void on_d_color_3_clicked();

    void on_d_color_4_clicked();

    void on_GenererImgFinal_clicked();

    void on_Save_image_clicked();

private:
    Ui::HarmonieDesCouleurs *ui;
};
#endif // HARMONIEDESCOULEURS_H
