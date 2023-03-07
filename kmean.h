#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <iostream>

void kmean(OCTET *ImgOut, OCTET *ImgTemp, OCTET *ImgIn, int nTaille3, couleur* tabPalMoy, int* Moyenne, couleur* tabPalette, int tabPalSize){
    int nR, nG, nB;

    for (int num_pixel = 0; num_pixel < nTaille3; num_pixel+=3){
        nR = ImgIn[num_pixel];
        nG = ImgIn[num_pixel+1];
        nB = ImgIn[num_pixel+2]; 

        float distance_min = MAXFLOAT;
        float distance_coloPal;
        int coloCentroide = 0;
        int coloPal = 0;

        for(coloPal; coloPal < tabPalSize; coloPal++){
            distance_coloPal = sqrt(pow(nR-tabPalette[coloPal].r,2)+pow(nG-tabPalette[coloPal].g,2)+pow(nB-tabPalette[coloPal].b,2));
            if(distance_coloPal < distance_min){
                distance_min = distance_coloPal;
                coloCentroide = coloPal;
            }
        }

        tabPalMoy[coloCentroide].r += nR;
        tabPalMoy[coloCentroide].g += nG;
        tabPalMoy[coloCentroide].b += nB;
        Moyenne[coloCentroide] += 1;

        ImgTemp[num_pixel] = coloCentroide;
        ImgTemp[num_pixel+1] = coloCentroide;
        ImgTemp[num_pixel+2] = coloCentroide;
    }

    // Couleur moyenne de chaque centroide
    for(int coloPal=0; coloPal < tabPalSize; coloPal++){
        float somme = Moyenne[coloPal];
        if(tabPalMoy[coloPal].r > 0){
                tabPalMoy[coloPal].r = (int)(tabPalMoy[coloPal].r/somme);
            }
            if(tabPalMoy[coloPal].g > 0){
                tabPalMoy[coloPal].g = (int)(tabPalMoy[coloPal].g/somme);
            }
            if(tabPalMoy[coloPal].b > 0){
                tabPalMoy[coloPal].b = (int)(tabPalMoy[coloPal].b/somme);
            }
    }

    for (int num_pixel = 0; num_pixel < nTaille3; num_pixel+=3){
        for(int coloPal = 0; coloPal < tabPalSize; coloPal++){
            if(ImgTemp[num_pixel] == coloPal){
                ImgOut[num_pixel] = tabPalMoy[coloPal].r;
                ImgOut[num_pixel+1] = tabPalMoy[coloPal].g;
                ImgOut[num_pixel+2] = tabPalMoy[coloPal].b;
            }
        }
    }

    for(int coloPal = 0; coloPal < tabPalSize; coloPal++){
        tabPalette[coloPal].r = tabPalMoy[coloPal].r;
        tabPalette[coloPal].g = tabPalMoy[coloPal].g;
        tabPalette[coloPal].b = tabPalMoy[coloPal].b;

    }

}

/* void affiche_kmean(OCTET *ImgOut, OCTET *ImgTemp, int nTaille3, couleur* tabPalMoy, int* Moyenne, couleur* tabPalette, int tabPalSize){
    
} */