#include <stdio.h>
#include <iostream>
#include "image_ppm.h"
#include "convert.h"
#include "palette.h"
#include "kmean.h"


int main(int argc, char* argv[]){
    char NomImgLue[250], NomImgEcrite[250];
    int nH, nW, nTaille, nW3, nTaille3;
    int tabPalSize;

    if(argc != 3){
        printf("Usage : NomImgLue.ppm NomImgEcrite.ppm nbCouleursPalette\n");
        exit(1);
    }

    sscanf(argv[1], "%s", NomImgLue);
    //sscanf(argv[2], "%s", NomImgEcrite);
    sscanf(argv[2], "%d", &tabPalSize);


    OCTET *ImgIn, *ImgTemp, *ImgOut;

    lire_nb_lignes_colonnes_image_ppm(NomImgLue, &nH, &nW);
    nTaille = nH * nW;

    nTaille3 = nTaille*3;
    nW3 = nW*3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    lire_image_ppm(NomImgLue, ImgIn, nH * nW);
    allocation_tableau(ImgTemp, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);

    //fonctions à tester
    int tabImgIn[nTaille3];
    couleur tabPalette[tabPalSize];


    couleur tabPalMoy[tabPalSize];
    int Moyenne[tabPalSize];

    OctetToIntPPM(ImgIn, tabImgIn, nH, nW);
    genTabPalette(tabImgIn, nTaille, tabPalette, tabPalSize);
    //afficheTabPalette(tabPalette, tabPalSize);

    kmean(ImgOut, ImgTemp, ImgIn, nTaille3, tabPalMoy, Moyenne, tabPalette, tabPalSize);
    afficheTabPalette(tabPalette, tabPalSize);

    ecrire_image_ppm((char*)"ImgKmean.ppm", ImgOut, nH, nW);
    free(ImgIn); free(ImgOut);

    return 1;
}