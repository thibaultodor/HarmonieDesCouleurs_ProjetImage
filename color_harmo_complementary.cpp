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

    vector<Pixel> pdominant = get_dominant_colors(listePixels,4);

    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB,hC;
        RGBtoHSL(r,g,b,hB,sB,lB);
        cout << "HB :" << hB << endl;
        addDegree(hB,hC,180);
        cout << "HC :" << hC << endl;
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            if(abs(hP-hB) < abs(hP-hC)){
                cout << "HP :" << hP << endl;
                cout << "abs :" << abs(hP-hB) << "abs :" << abs(hP-hC) << endl;
                HSLtoRGB(hB,sP,lP,rP,gP,bP);
            }
            else{
                HSLtoRGB(hC,sP,lP,rP,gP,bP);
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
        ecrire_image_ppm(("Complementary"+ to_string(i)+".ppm").data(),ImgOut,nH,nW);
    }
}