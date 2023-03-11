//
// Created by thibault on 3/11/23.
//
#include "harmony.h"

int main(int argc, char* argv[]){
    char cNomImgLue[250];
    int nH, nW, nTaille;

    if (argc != 2)
    {
        printf("Usage: ImageIn.ppm \n");
        exit (1) ;
    }

    sscanf (argv[1],"%s",cNomImgLue) ;

    OCTET *ImgIn,*ImgOut;

    lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;

    int nTaille3 = nTaille * 3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    lire_image_ppm(cNomImgLue, ImgIn, nH * nW);

    vector<Pixel> listePixels;

    for (int i=0; i < nTaille3; i+=3)
    {
        Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};
        listePixels.push_back(p);
    }

    vector<Pixel> pdominant = get_dominant_colors(listePixels,10);

    double range = 50;

    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB,h1,h2;
        RGBtoHSL(r,g,b,hB,sB,lB);
        analogue(hB,range,h1,h2);
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            if(isDegreeBetween(hP,h2,h1)==1){
                HSLtoRGB(h1,sP,lP,rP,gP,bP);
            }
            else if(isDegreeBetween(hP,h2,h1)==2){
                HSLtoRGB(h2,sP,lP,rP,gP,bP);
            }
            else{
                rP=p.r;gP=p.g;bP=p.b;
            }
            Pixel pT = {rP,gP,bP};
            listePixelsTransform.emplace_back(pT);
        }
        for (int z=0; z < nTaille3; z+=3)
        {
            ImgOut[z] = listePixelsTransform[z/3].r;
            ImgOut[z+1] = listePixelsTransform[z/3].g;
            ImgOut[z+2] = listePixelsTransform[z/3].b;
        }
        ecrire_image_ppm(("Analogue"+ to_string(i)+".ppm").data(),ImgOut,nH,nW);
    }
}