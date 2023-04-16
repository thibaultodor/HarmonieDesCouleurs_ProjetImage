#include <iostream>
#include <vector>
#include <cmath>
#include "harmony.h"

void couleursDominantes(char cheminFichier[], Pixel &couleur1, Pixel &couleur2, Pixel &couleur3, Pixel &couleur4){
    //char cNomImgLue[250];
    std::cout << cheminFichier << std::endl;
    int nH, nW, nTaille;

    int taille_palette = 512;

    OCTET *ImgIn,*Palette;

    lire_nb_lignes_colonnes_image_ppm(cheminFichier, &nH, &nW);
    nTaille = nH * nW;

    int nTaille3 = nTaille * 3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(Palette, OCTET, (taille_palette*taille_palette)*3);
    lire_image_ppm(cheminFichier, ImgIn, nH * nW);

    vector<Pixel> listePixels;

    for (int i=0; i < nTaille3; i+=3)
    {
        Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};
        listePixels.push_back(p);
    }

    vector<Pixel> pdominant = get_dominant_colors1(listePixels,4);

//    for (Pixel p:pdominant) {
//        cout << (int)p.r << " " << (int)p.g << " " << (int)p.b << endl;
//    }

    nW = taille_palette*3;nH=taille_palette*3;

    for (int i = 0; i < nH/2; i+=3) {
        for (int j = 0; j < nW/2; j+=3) {
            Palette[(i * (nW/3)) + j] = pdominant[0].r;
            Palette[(i * (nW/3)) + j + 1] = pdominant[0].g;
            Palette[(i * (nW/3)) + j + 2] = pdominant[0].b;

            Palette[(i * (nW/3)) + j + (nW/2)] = pdominant[1].r;
            Palette[(i * (nW/3)) + j + (nW/2) + 1] = pdominant[1].g;
            Palette[(i * (nW/3)) + j + (nW/2) + 2] = pdominant[1].b;

            Palette[((i + nH/2) * nW/3) + j] = pdominant[2].r;
            Palette[((i + nH/2) * nW/3) + j + 1] = pdominant[2].g;
            Palette[((i + nH/2) * nW/3) + j + 2] = pdominant[2].b;

            Palette[((i + nH/2) * nW/3) + j + (nW/2)] = pdominant[3].r;
            Palette[((i + nH/2) * nW/3) + j + (nW/2) + 1] = pdominant[3].g;
            Palette[((i + nH/2) * nW/3) + j + (nW/2) + 2] = pdominant[3].b;
        }
    }

    couleur1.r = pdominant[0].r;
    couleur1.g = pdominant[0].g;
    couleur1.b = pdominant[0].b;

    couleur2.r = pdominant[1].r;
    couleur2.g = pdominant[1].g;
    couleur2.b = pdominant[1].b;

    couleur3.r = pdominant[2].r;
    couleur3.g = pdominant[2].g;
    couleur3.b = pdominant[2].b;

    couleur4.r = pdominant[3].r;
    couleur4.g = pdominant[3].g;
    couleur4.b = pdominant[3].b;

    //cout << (int)couleur1.r << " " << couleur1.g << " " << couleur1.b;

    //ecrire_image_ppm("Palette.ppm",Palette,taille_palette,taille_palette);
}
