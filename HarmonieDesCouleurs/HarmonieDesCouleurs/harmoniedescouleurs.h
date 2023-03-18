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
    void on_Parcourir_clicked();

    void on_actionQuitter_triggered();

    void on_colorSelector_clicked();

    void on_actionCredits_triggered();

    void on_dom_colors_clicked();

    void on_Supprimer_clicked();

private:
    Ui::HarmonieDesCouleurs *ui;
};
#endif // HARMONIEDESCOULEURS_H
