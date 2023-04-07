//
// Created by thibault on 3/11/23.
//
#include "harmony.h"

int main(int argc, char* argv[]) {
    char cNomImgLue[250];
    int nH, nW, nTaille, number_of_dominant_color;

    number_of_dominant_color = 5;

    int taille_palette = 512;

    if (argc != 2) {
        printf("Usage: ImageIn.ppm \n");
        exit(1);
    }

    sscanf(argv[1], "%s", cNomImgLue);

    OCTET *ImgIn,*ImgInKmean, *Palette, *ImgOut,*ImgFix,*ImgOutFix;

    lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(ImgInKmean, OCTET, nTaille3);
    allocation_tableau(ImgFix, OCTET, nTaille3);
    allocation_tableau(ImgOutFix, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);
    allocation_tableau(Palette, OCTET, (taille_palette * taille_palette) * 3);
    lire_image_ppm(cNomImgLue, ImgIn, nH * nW);

    vector<Pixel> listePixels;
    for (int i = 0; i < nTaille3; i += 3) {
        Pixel p = {ImgIn[i], ImgIn[i + 1], ImgIn[i + 2]};
        listePixels.push_back(p);
    }

    /*
    for(int i=1;i<25;i++) {
        vector<Pixel> pdominant = get_dominant_colors(listePixels, i, nH, nW);
    }
    */

    vector<Pixel> pdominant = get_dominant_colors(listePixels, 4, nH, nW);
    lire_image_ppm("Image_Kmean.ppm", ImgInKmean, nH * nW);

    //AnalogueHarmony(pdominant,listePixels,nH,nW,2);
    //ComplementaryHarmony(pdominant,listePixels,nH,nW,2);
    //TriadiqueHarmony(pdominant,listePixels,nH,nW,2);
    //ComplementaryHarmonyQT(pdominant[0],cNomImgLue,1);


    int* segmentValues = new int[nW * nH];
    assignSegmentValues(ImgInKmean, segmentValues,nW,nH);

    // Print the segment values
    /*
    for (int y = 0; y < nH; y++) {
        for (int x = 0; x < nW; x++) {
            int index = getIndex(x, y, nW);
            std::cout << segmentValues[index] << " ";
        }
        std::cout << std::endl;
    }
    */

    std::vector<std::vector<int>> affecteLabel;
    affecteLabel.resize(nTaille);

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution for each color channel
    std::uniform_int_distribution<int> distr(0, 255);

    for (int i = 0; i < nTaille; ++i) {
        // Generate random values for each color channel
        int red = distr(gen);
        int green = distr(gen);
        int blue = distr(gen);

        std::vector<int> v;
        v.emplace_back(red);v.emplace_back(green);v.emplace_back(blue);
        affecteLabel[segmentValues[i]] = v;
    }

    int red = distr(gen);
    int green = distr(gen);
    int blue = distr(gen);
    SquareHarmonyQT(Pixel{(OCTET)red,(OCTET)green,(OCTET)blue},cNomImgLue,20);
    

    for (int i = 0; i < nTaille3; i+=3) {
        ImgOut[i] = affecteLabel[segmentValues[i/3]][0];
        ImgOut[i+1] = affecteLabel[segmentValues[i/3]][1];
        ImgOut[i+2] = affecteLabel[segmentValues[i/3]][2];
    }

    ecrire_image_ppm("test.ppm",ImgOut,nH,nW);

    std::vector<int> listeLabel;
    listeLabel.reserve(nTaille);
    for (int i = 0; i < nTaille; ++i) {listeLabel.emplace_back(segmentValues[i]);}
    std::sort(listeLabel.begin(), listeLabel.end());
    // Remove duplicates
    listeLabel.erase(std::unique(listeLabel.begin(), listeLabel.end()), listeLabel.end());

    std::vector<std::vector<int>> zones;
    for (int i = 0; i < listeLabel.size(); i++) {
        std::vector<int> v;
        for (int j = 0; j < nTaille3; j+=3) {
            if(segmentValues[j/3] == listeLabel[i]){v.emplace_back(j);}
        }
        zones.emplace_back(v);
    }

    //std::cout << zones.size() << std::endl;

    lire_image_ppm("Image_Transform.ppm", ImgFix, nH * nW);

    for (auto & zone : zones) {
        std::vector<PixelXY> listePixelsFix;
        for (int j = 0; j < zone.size(); j++) {
            listePixelsFix.emplace_back(PixelXY{zone[j],ImgFix[zone[j]],ImgFix[zone[j]+1],ImgFix[zone[j]+2]});
        }
        //std::vector<double> variance = calculate_variance(listePixelsFix);
        //std::cout << variance[0] << " " << variance[1] << " " << variance[2] <<  std::endl;
        Pixel colour = getMostColourZone(listePixelsFix);
        double h,s,l;
        RGBtoHSL(colour.r,colour.g,colour.b,h,s,l);
        for (auto & j : listePixelsFix) {
            double hfix,sfix,lfix;
            RGBtoHSL(j.r,j.g,j.b,hfix,sfix,lfix);
            hfix = h;
            OCTET rfix,gfix,bfix;
            HSLtoRGB(hfix,sfix,lfix,rfix,gfix,bfix);
            ImgOutFix[j.index] = rfix;
            ImgOutFix[j.index+1] = gfix;
            ImgOutFix[j.index+2] = bfix;
        }
    }

    ecrire_image_ppm("testFIX.ppm",ImgOutFix,nH,nW);

    vector<Pixel> listePixelsFix;
    for (int i = 0; i < nTaille3; i += 3) {
        Pixel p = {ImgOutFix[i], ImgOutFix[i + 1], ImgOutFix[i + 2]};
        listePixelsFix.push_back(p);
    }
    SquareHarmony({Pixel{(OCTET)red,(OCTET)green,(OCTET)blue}},listePixelsFix,nH,nW,20);

    /*
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
    */
}