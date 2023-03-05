#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[]){
    char NomImgLue[250], NomImgEcrite[250];
    int nH, nW, nTaille, nW3, nTaille3;

    if(argc != 3){
        printf("Usage : NomImgLue.ppm NomImgEcrite.ppm");
        exit(1);
    }

    sscanf(argv[1], "%s", NomImgLue);
    sscanf(argv[2], "%s", NomImgEcrite);

    OCTET *ImgIn, *ImgOut;

    lire_nb_lignes_colonnes_image_ppm(NomImgLue, &nH, &nW);
    nTaille = nH * nW;

    nTaille3 = nTaille*3;
    nW3 = nW*3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    lire_image_ppm(NomImgLue, ImgIn, nH * nW);
    allocation_tableau(ImgOut, OCTET, nTaille3);

    //fonctions à tester

    ecrire_image_ppm(NomImgEcrite, ImgOut, nH, nW);
    free(ImgIn); free(ImgOut);

    return 1;
}