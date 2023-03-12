#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <iostream>

void kmean(OCTET *ImgOut, OCTET *ImgTemp, OCTET *ImgIn, int nTaille3, couleur* tabPalMoy, int* Moyenne, couleur* tabPalette, int tabPalSize){    
    for(int num_pixel=0; num_pixel < nTaille3; num_pixel+=3){
        ImgTemp[num_pixel] = ImgIn[num_pixel];
        ImgTemp[num_pixel+1] = ImgIn[num_pixel+1];
        ImgTemp[num_pixel+2] = ImgIn[num_pixel+2]; 
    }
    
    for (int boucle=0; boucle < 30; boucle++){
        std::cout << "boucle : " << boucle << std::endl;

        if(boucle != 0){
            for (int i = 0; i < tabPalSize; i++){
                Moyenne[i] = 0;
                tabPalette[i].r = tabPalMoy[i].r;
                tabPalette[i].g = tabPalMoy[i].g;
                tabPalette[i].b = tabPalMoy[i].b;
                tabPalMoy[i].r = 0;
                tabPalMoy[i].g = 0;
                tabPalMoy[i].b = 0;
            }
        }
        
        
        for (int num_pixel = 0; num_pixel < nTaille3; num_pixel+=3){
            int nR = ImgIn[num_pixel];
            int nG = ImgIn[num_pixel+1];
            int nB = ImgIn[num_pixel+2]; 

            float distance_min = MAXFLOAT; //distance min
            float distance_coloPal;        //distance entre coloPal & colo num_pixel
            int coloCentroide = 0;         //index colo def

            for(int coloPal = 0; coloPal < tabPalSize; coloPal++){ //Test de chaque couleur de la palette
                //calcul distance 
                distance_coloPal = sqrt(pow(tabPalette[coloPal].r-nR,2)+pow(tabPalette[coloPal].g-nG,2)+pow(tabPalette[coloPal].b-nB,2));
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

}

/* void affiche_kmean(OCTET *ImgOut, OCTET *ImgTemp, int nTaille3, couleur* tabPalMoy, int* Moyenne, couleur* tabPalette, int tabPalSize){
    
} */