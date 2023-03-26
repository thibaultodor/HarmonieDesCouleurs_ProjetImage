//
// Created by thibault on 3/11/23.
//
#include "harmony.h"

int main(int argc, char* argv[]){
    char cNomImgLue[250];
    int nH, nW, nTaille,number_of_dominant_color;

    number_of_dominant_color =4;

    int taille_palette = 512;

    if (argc != 2)
    {
        printf("Usage: ImageIn.ppm \n");
        exit (1) ;
    }

    sscanf (argv[1],"%s",cNomImgLue) ;

    OCTET *ImgIn,*Palette;

    lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(Palette, OCTET, (taille_palette*taille_palette)*3);
    lire_image_ppm(cNomImgLue, ImgIn, nH * nW);

    vector<Pixel> listePixels;
    for (int i=0; i < nTaille3; i+=3){Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};listePixels.push_back(p);}
    vector<Pixel> pdominant = get_dominant_colors(listePixels,number_of_dominant_color);

    //AnalogueHarmony(pdominant,listePixels,nH,nW,2);
    //ComplementaryHarmony(pdominant,listePixels,nH,nW,2);
    //TriadiqueHarmony(pdominant,listePixels,nH,nW,2);
    //ComplementaryHarmonyQT(pdominant[0],cNomImgLue,1);
    SquareHarmony(pdominant,listePixels,nH,nW,2);

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

    ecrire_image_ppm("Palette.ppm",Palette,taille_palette,taille_palette);
}