#include "image_ppm.h"
#include <vector>
#include <algorithm>
#include <iostream>

struct couleur{
    int r,g,b;

    bool operator==(const couleur& c) const {
        return ((c.r==r)&&(c.g==g)&&(c.b==b));
    }
};

void genTabCouleur(OCTET* ImgIn, std::vector<couleur> &tabCouleur, std::vector<int> &nbOcc, int &nTaille){
    for(int i=0; i < nTaille; i+=3){
        couleur current_color;
        current_color.r = ImgIn[i];
        current_color.g = ImgIn[i+1];
        current_color.b = ImgIn[i+2];

        std::vector<couleur>::iterator itr = std::find(tabCouleur.begin(), tabCouleur.end(), current_color);

        if(!tabCouleur.empty()){ // si le tableau n'est pas vide
            if(itr != tabCouleur.end()){ // si le tableau contient déjà la couleur actuelle
                nbOcc[std::distance(tabCouleur.begin(), itr)]++;
                continue;
            }else{  // si le tableau ne la contient pas
                tabCouleur.push_back(current_color);
                nbOcc.push_back(1);
            }
        }else{ // si le tableau est vide
            tabCouleur.push_back(current_color);
            nbOcc.push_back(1);
            
        }
    }
}

void couleurDominante(couleur &couleurDom, int &Occ, int &index, std::vector<couleur> &tabCouleur, std::vector<int> &nbOcc){
    int maxOcc = 0;

    for(int i=0; i < nbOcc.size(); i++){
        if(maxOcc < nbOcc[i]){
            maxOcc = nbOcc[i];
            index = i;
        }
    }    

    couleurDom.r = tabCouleur[index].r;
    couleurDom.g = tabCouleur[index].g;
    couleurDom.b = tabCouleur[index].b;
    Occ = maxOcc;

}

void tabCouleursDominantes(couleur* tab10CouleursDom, int* tab10Occ, std::vector<couleur> &tabCouleur, std::vector<int> &nbOcc){
    int maxOcc = 0, index = 0;
    for(int i=0; i < 10; i++){
        couleur c;
        int o = 0;
        couleurDominante(c, o, index, tabCouleur, nbOcc);
        tab10CouleursDom[i] = c;
        tab10Occ[i] = o;
        tabCouleur.erase(tabCouleur.begin() + index);
        nbOcc.erase(nbOcc.begin() + index);
        std::cout << "taille : " << tabCouleur.size() << std::endl; 
    }
}

void affiche10CouleursDom(couleur* tab10CouleursDom, int* tab10Occ){
    OCTET *ImgTemp;
    allocation_tableau(ImgTemp, OCTET, 10*3);

    for(int i=0; i < 10; i++){
        ImgTemp[i*3] = tab10CouleursDom[i].r;
        ImgTemp[i*3+1] = tab10CouleursDom[i].g;
        ImgTemp[i*3+2] = tab10CouleursDom[i].b;

        std::cout << "RGB(" << tab10CouleursDom[i].r << "," << tab10CouleursDom[i].g << "," << tab10CouleursDom[i].b << ")" << std::endl;
        std::cout << "Occurence : " << tab10Occ[i] << std::endl; 
    }

    ecrire_image_ppm("Palette10.ppm", ImgTemp, 10, 1);

}
