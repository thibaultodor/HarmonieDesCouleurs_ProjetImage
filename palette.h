#include <vector>
#include <algorithm>
#include <iostream>

struct couleur{
    int r,g,b;
};

/* std::vector<couleur> genTabRandCouleur(int nbCouleursPalette){
    std::vector<couleur> tabCouleur;
    for(int i=0; i < nbCouleursPalette; i++ ){
        couleur randColor;
        randColor.r = rand()%256;
        randColor.g = rand()%256;
        randColor.b = rand()%256;
        tabCouleur.push_back(randColor);
    }
    return tabCouleur;
}; */

void genTabPalette(int *ImgIn, int nTaille, couleur *tabPalette, int tabPalSize){
    int index = ceil(nTaille/tabPalSize);
    for(int i=0; i < tabPalSize; i++){
        couleur ColorSelected;
        ColorSelected.r = ImgIn[index];
        ColorSelected.g = ImgIn[index+1];
        ColorSelected.b = ImgIn[index+2];
        tabPalette[i] = ColorSelected;
        index += ceil(nTaille/tabPalSize);
    }
};

void afficheTabPalette(couleur *tabPalette, int tabPalSize){
    int nH = sqrt(tabPalSize);
    int nW = tabPalSize/nH;
    int nW3 = (tabPalSize/2*3);
    
    OCTET *ImgOut;
    allocation_tableau(ImgOut, OCTET, nH*nW3);

    for (int i=0; i < tabPalSize; i++){
        ImgOut[i*3]   = tabPalette[i].r;
        ImgOut[i*3+1] = tabPalette[i].g;
        ImgOut[i*3+2] = tabPalette[i].b;
    }

    ecrire_image_ppm("PaletteGeneree.ppm", ImgOut, nH, nW);
}