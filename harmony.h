#ifndef HARMONIEDESCOULEURS_PROJETIMAGE_HARMONY_H
#define HARMONIEDESCOULEURS_PROJETIMAGE_HARMONY_H

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include "image_ppm.h"

using namespace std;

// A simple struct to represent a pixel with RGB values
struct Pixel {
    OCTET r, g, b;

    // Overloading the equality operator for comparing pixels
    bool operator==(const Pixel& p) const {
        return r == p.r && g == p.g && b == p.b;
    }
};

// Calculate the Euclidean distance between two pixels
float euclidean_distance(const Pixel& p1, const Pixel& p2) {
    float dr = p1.r - p2.r;
    float dg = p1.g - p2.g;
    float db = p1.b - p2.b;
    return sqrt(dr*dr + dg*dg + db*db);
}

// Assign each pixel to the closest cluster centroid
void assign_clusters(const vector<Pixel>& pixels, const vector<Pixel>& centroids, vector<int>& labels) {
    for (int i = 0; i < pixels.size(); i++) {
        int min_label = -1;
        float min_distance = numeric_limits<float>::max();

        for (int j = 0; j < centroids.size(); j++) {
            float distance = euclidean_distance(pixels[i], centroids[j]);

            if (distance < min_distance) {
                min_label = j;
                min_distance = distance;
            }
        }

        labels[i] = min_label;
    }
}

// Calculate the mean color of each cluster
void update_centroids(const vector<Pixel>& pixels, const vector<int>& labels, vector<Pixel>& centroids) {
    vector<int> counts(centroids.size(), 0);
    vector<int> r_sums(centroids.size(), 0);
    vector<int> g_sums(centroids.size(), 0);
    vector<int> b_sums(centroids.size(), 0);

    for (int i = 0; i < pixels.size(); i++) {
        int label = labels[i];
        counts[label]++;
        r_sums[label] += pixels[i].r;
        g_sums[label] += pixels[i].g;
        b_sums[label] += pixels[i].b;
    }

    for (int j = 0; j < centroids.size(); j++) {
        if (counts[j] == 0) {
            continue;
        }

        centroids[j].r = static_cast<OCTET>(r_sums[j] / counts[j]);
        centroids[j].g = static_cast<OCTET>(g_sums[j] / counts[j]);
        centroids[j].b = static_cast<OCTET>(b_sums[j] / counts[j]);
    }
}

// Run k-means algorithm
void kmeans(const vector<Pixel>& pixels, vector<Pixel>& centroids, int k, int max_iter) {
    vector<int> labels(pixels.size(), -1);

    // Randomly initialize cluster centroids
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, pixels.size()-1);
    for (int i = 0; i < k; i++) {
        centroids.push_back(pixels[dist(gen)]);
    }

    // Run k-means iterations
    for (int i = 0; i < max_iter; i++) {
        assign_clusters(pixels, centroids, labels);
        update_centroids(pixels, labels, centroids);
    }
}

// colors using number_of_dominant_colors-means algorithm
vector<Pixel> get_dominant_colors(const vector<Pixel>& pixels, int number_of_dominant_colors) {
    vector<Pixel> centroids;
    kmeans(pixels, centroids, number_of_dominant_colors, 30);
    // Run k-means algorithm
    // Count the number of pixels in each cluster
    vector<int> counts(centroids.size(), 0);
    for (int i = 0; i < pixels.size(); i++) {
        int label = -1;
        float min_distance = numeric_limits<float>::max();
        for (int j = 0; j < centroids.size(); j++) {
            float distance = euclidean_distance(pixels[i], centroids[j]);
            if (distance < min_distance) {
                label = j;
                min_distance = distance;
            }
        }

        counts[label]++;
    }

    // Sort the clusters by the number of pixels in each cluster
    vector<pair<int, int>> cluster_counts;
    for (int i = 0; i < centroids.size(); i++) {
        cluster_counts.push_back(make_pair(counts[i], i));
    }
    sort(cluster_counts.begin(), cluster_counts.end(), greater<pair<int, int>>());

// Get the most dominant colors
    vector<Pixel> dominant_colors;
    for (int i = 0; i < min(number_of_dominant_colors, static_cast<int>(centroids.size())); i++) {
        dominant_colors.push_back(centroids[cluster_counts[i].second]);
    }

    return dominant_colors;
}

void RGBtoHSL(int r, int g, int b, double &h, double &s, double &l) {
    double rd = static_cast<double>(r) / 255.0;
    double gd = static_cast<double>(g) / 255.0;
    double bd = static_cast<double>(b) / 255.0;

    double max_color = std::max(std::max(rd, gd), bd);
    double min_color = std::min(std::min(rd, gd), bd);
    double delta = max_color - min_color;

    if (delta == 0) {h = 0;}
    else if (max_color == rd) { h = fmod(((gd - bd) / delta), 6);}
    else if (max_color == gd) { h = ((bd - rd) / delta) + 2;}
    else {h = ((rd - gd) / delta) + 4;}
    h = (h * 60.0) / 360.0;

    if (h < 0) {h += 1.0;}
    l = (max_color + min_color) / 2.0;
    if (delta == 0) {s = 0;}
    else {s = delta / (1.0 - fabs(2.0 * l - 1.0));}
    h = h*360;
    s = s;
    l = l;
}

void HSLtoRGB(float h, float s, float l, OCTET & r, OCTET & g, OCTET & b) {
    if (s == 0) {
        r = g = b = l * 255;
    } else {
        float q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        float p = 2 * l - q;
        float hk = h / 360.0;
        float tr = hk + 1.0 / 3.0;
        float tg = hk;
        float tb = hk - 1.0 / 3.0;

        tr = tr < 0 ? tr + 1 : (tr > 1 ? tr - 1 : tr);
        tg = tg < 0 ? tg + 1 : (tg > 1 ? tg - 1 : tg);
        tb = tb < 0 ? tb + 1 : (tb > 1 ? tb - 1 : tb);

        r = ((tr < 1.0 / 6.0) ? p + (q - p) * 6 * tr : (tr < 1.0 / 2.0) ? q : (tr < 2.0 / 3.0) ? p + (q - p) * (2.0 / 3.0 - tr) * 6 : p) * 255;
        g = ((tg < 1.0 / 6.0) ? p + (q - p) * 6 * tg : (tg < 1.0 / 2.0) ? q : (tg < 2.0 / 3.0) ? p + (q - p) * (2.0 / 3.0 - tg) * 6 : p) * 255;
        b = ((tb < 1.0 / 6.0) ? p + (q - p) * 6 * tb : (tb < 1.0 / 2.0) ? q : (tb < 2.0 / 3.0) ? p + (q - p) * (2.0 / 3.0 - tb) * 6 : p) * 255;
    }
}

void addDegree(double hB, double &h,double addvalue){
    h = hB + addvalue;
    if(h>360){h=h-360;}
}

void analogue(double h,double range,double &h1,double &h2){
    addDegree(h,h1,range);
    addDegree(h,h1,(360-range));
}

int isDegreeBetween(double degree, double degree1, double degree2) {
    double angle = std::fmod((degree2 - degree1 + 360), 360); // get angle between the two degrees in a circular manner
    angle = angle;
    double d1 = std::fmod((degree - degree1 + 360), 360); // get the difference between degree1 and degree in a circular manner
    //cout << d1 << endl;
    d1 = d1;
    double d2 = std::fmod((degree2 - degree + 360), 360); // get the difference between degree2 and degree in a circular manner
    //cout << d2 << endl;
    d2 = d2;

    //cout << d1 << " " << d2 << " : " << angle << endl;

    if (d1 >= angle && d2 >= angle) { // check if both differences are less than or equal to the angle between the degrees
        return 0;
    }

    else if(abs(angle-d1) < abs(angle-d2)){
        return 1;
    }
    else{
        return 2;
    }
}

vector<double> distanceMin(std::vector<double> hList,double hRef){
    int valRef = lround(hRef);
    std::vector<int> listDistance;
    std::vector<bool> isNegatif;
    for (double h:hList) {
        int valH = lround(h);
        int nbPasPLUS = 0;
        while(valH != valRef){
            if(valH != 361){valH++;nbPasPLUS++;}
            else{valH=0;}
        }
        valH = lround(h);
        int nbPasMOINS = 0;
        while(valH != valRef){
            if(valH != -1){valH--;nbPasMOINS++;}
            else{valH=360;}
        }
        int valMIN = std::min(nbPasPLUS,nbPasMOINS);
        if(valMIN==nbPasPLUS){
            isNegatif.emplace_back(false);
        }
        else{
            isNegatif.emplace_back(true);
        }
        listDistance.emplace_back(valMIN);
    }
    int minIndex = 0;
    for (int i = 1; i < hList.size(); ++i) {
        if(listDistance[minIndex] > listDistance[i]){minIndex=i;}
    }
    double valReturn = listDistance[minIndex];
    if(isNegatif[minIndex]){valReturn *= -1.;}
    std::vector<double> vectorReturn;
    vectorReturn.emplace_back(hList[minIndex]);
    vectorReturn.emplace_back(valReturn);
    return vectorReturn;
}

void ComplementaryHarmony(const std::vector<Pixel> &pdominant,const std::vector<Pixel>& listePixels,int nH,int nW,double sizeBand){
    OCTET *ImgOut;
    int nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB,hC;
        RGBtoHSL(r,g,b,hB,sB,lB);
        addDegree(hB,hC,180);
        std::vector<double> hList;
        hList.emplace_back(hB);
        hList.emplace_back(hC);
        double influenceSize = (float)(360. / (double)hList.size());
        double radius = influenceSize / 2.;
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            std::vector<double> vectorDistance = distanceMin(hList,hP);
            double distance = vectorDistance[1];
            double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
            HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
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

void ComplementaryHarmonyQT(const Pixel &cdominant,char * filePath,double sizeBand){
    OCTET *ImgOut,*ImgIn;
    int nH,nW;
    lire_nb_lignes_colonnes_image_ppm(filePath, &nH, &nW);
    int nTaille = nH * nW;
    int nTaille3 = nTaille *3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);
    lire_image_ppm(filePath, ImgIn, nH * nW);
    vector<Pixel> listePixels;
    for (int i=0; i < nTaille3; i+=3){Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};listePixels.push_back(p);}
    OCTET r = cdominant.r;OCTET g = cdominant.g;OCTET b = cdominant.b;
    double hB,sB,lB,hC;
    RGBtoHSL(r,g,b,hB,sB,lB);
    addDegree(hB,hC,180);
    std::vector<double> hList;
    hList.emplace_back(hB);
    hList.emplace_back(hC);
    double influenceSize = (float)(360. / (double)hList.size());
    double radius = influenceSize / 2.;
    vector<Pixel> listePixelsTransform;
    for (Pixel p:listePixels) {
        double hP,sP,lP;
        OCTET rP,gP,bP;
        RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
        std::vector<double> vectorDistance = distanceMin(hList,hP);
        double distance = vectorDistance[1];
        double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
        HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
        Pixel pT = {rP,gP,bP};
        listePixelsTransform.emplace_back(pT);
    }
    for (int z=0; z < nTaille3; z+=3)
    {
        ImgOut[z] = listePixelsTransform[z/3].r;
        ImgOut[z+1] = listePixelsTransform[z/3].g;
        ImgOut[z+2] = listePixelsTransform[z/3].b;
    }
    ecrire_image_ppm("Image_Transform.ppm",ImgOut,nH,nW);
}


void AnalogueHarmony(const std::vector<Pixel> &pdominant,const std::vector<Pixel>& listePixels,int nH,int nW,double sizeBand){
    OCTET *ImgOut;
    int nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB;
        RGBtoHSL(r,g,b,hB,sB,lB);
        std::vector<double> hList;
        hList.emplace_back(hB);
        double influenceSize = (float)(360. / (double)hList.size());
        double radius = influenceSize / 2.;
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            std::vector<double> vectorDistance = distanceMin(hList,hP);
            double distance = vectorDistance[1];
            double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
            HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
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

void AnalogueHarmonyQT(const Pixel &cdominant,char * filePath,double sizeBand){
    OCTET *ImgOut,*ImgIn;
    int nH,nW;
    lire_nb_lignes_colonnes_image_ppm(filePath, &nH, &nW);
    int nTaille = nH * nW;
    int nTaille3 = nTaille *3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);
    lire_image_ppm(filePath, ImgIn, nH * nW);
    vector<Pixel> listePixels;
    for (int i=0; i < nTaille3; i+=3){Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};listePixels.push_back(p);}
    OCTET r = cdominant.r;OCTET g = cdominant.g;OCTET b = cdominant.b;
    double hB,sB,lB;
    RGBtoHSL(r,g,b,hB,sB,lB);
    std::vector<double> hList;
    hList.emplace_back(hB);
    double influenceSize = (float)(360. / (double)hList.size());
    double radius = influenceSize / 2.;
    vector<Pixel> listePixelsTransform;
    for (Pixel p:listePixels) {
        double hP,sP,lP;
        OCTET rP,gP,bP;
        RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
        std::vector<double> vectorDistance = distanceMin(hList,hP);
        double distance = vectorDistance[1];
        double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
        HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
        Pixel pT = {rP,gP,bP};
        listePixelsTransform.emplace_back(pT);
    }
    for (int z=0; z < nTaille3; z+=3)
    {
        ImgOut[z] = listePixelsTransform[z/3].r;
        ImgOut[z+1] = listePixelsTransform[z/3].g;
        ImgOut[z+2] = listePixelsTransform[z/3].b;
    }
    ecrire_image_ppm("Image_Transform.ppm",ImgOut,nH,nW);
}


void TriadiqueHarmony(const std::vector<Pixel> &pdominant,const std::vector<Pixel>& listePixels,int nH,int nW,double sizeBand){
    OCTET *ImgOut;
    int nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB,hT1,hT2;
        RGBtoHSL(r,g,b,hB,sB,lB);
        addDegree(hB,hT1,120);
        addDegree(hB,hT2,240);
        std::vector<double> hList;
        hList.emplace_back(hB);
        hList.emplace_back(hT1);
        hList.emplace_back(hT2);
        double influenceSize = (float)(360. / (double)hList.size());
        double radius = influenceSize / 2.;
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            std::vector<double> vectorDistance = distanceMin(hList,hP);
            double distance = vectorDistance[1];
            double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
            HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
            Pixel pT = {rP,gP,bP};
            listePixelsTransform.emplace_back(pT);
        }
        for (int z=0; z < nTaille3; z+=3)
        {
            ImgOut[z] = listePixelsTransform[z/3].r;
            ImgOut[z+1] = listePixelsTransform[z/3].g;
            ImgOut[z+2] = listePixelsTransform[z/3].b;
        }
        ecrire_image_ppm(("Triadique"+ to_string(i)+".ppm").data(),ImgOut,nH,nW);
    }
}

void TriadiqueHarmonyQT(const Pixel &cdominant,char * filePath,double sizeBand){
    OCTET *ImgOut,*ImgIn;
    int nH,nW;
    lire_nb_lignes_colonnes_image_ppm(filePath, &nH, &nW);
    int nTaille = nH * nW;
    int nTaille3 = nTaille *3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);
    lire_image_ppm(filePath, ImgIn, nH * nW);
    vector<Pixel> listePixels;
    for (int i=0; i < nTaille3; i+=3){Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};listePixels.push_back(p);}
    OCTET r = cdominant.r;OCTET g = cdominant.g;OCTET b = cdominant.b;
    double hB,sB,lB,hT1,hT2;
    RGBtoHSL(r,g,b,hB,sB,lB);
    addDegree(hB,hT1,120);
    addDegree(hB,hT2,240);
    std::vector<double> hList;
    hList.emplace_back(hB);
    hList.emplace_back(hT1);
    hList.emplace_back(hT2);
    double influenceSize = (float)(360. / (double)hList.size());
    double radius = influenceSize / 2.;
    vector<Pixel> listePixelsTransform;
    for (Pixel p:listePixels) {
        double hP,sP,lP;
        OCTET rP,gP,bP;
        RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
        std::vector<double> vectorDistance = distanceMin(hList,hP);
        double distance = vectorDistance[1];
        double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
        HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
        Pixel pT = {rP,gP,bP};
        listePixelsTransform.emplace_back(pT);
    }
    for (int z=0; z < nTaille3; z+=3)
    {
        ImgOut[z] = listePixelsTransform[z/3].r;
        ImgOut[z+1] = listePixelsTransform[z/3].g;
        ImgOut[z+2] = listePixelsTransform[z/3].b;
    }
    ecrire_image_ppm("Image_Transform.ppm",ImgOut,nH,nW);
}

void SquareHarmony(const std::vector<Pixel> &pdominant,const std::vector<Pixel>& listePixels,int nH,int nW,double sizeBand){
    OCTET *ImgOut;
    int nTaille = nH * nW;
    int nTaille3 = nTaille * 3;
    for (int i = 0; i < pdominant.size(); ++i) {
        allocation_tableau(ImgOut, OCTET, nTaille3);
        OCTET r = pdominant[i].r;OCTET g = pdominant[i].g;OCTET b = pdominant[i].b;
        double hB,sB,lB,hS1,hS2,hS3;
        RGBtoHSL(r,g,b,hB,sB,lB);
        addDegree(hB,hS1,90);
        addDegree(hB,hS2,180);
        addDegree(hB,hS3,270);
        std::vector<double> hList;
        hList.emplace_back(hB);
        hList.emplace_back(hS1);
        hList.emplace_back(hS2);
        hList.emplace_back(hS3);
        double influenceSize = (float)(360. / (double)hList.size());
        double radius = influenceSize / 2.;
        vector<Pixel> listePixelsTransform;
        for (Pixel p:listePixels) {
            double hP,sP,lP;
            OCTET rP,gP,bP;
            RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
            std::vector<double> vectorDistance = distanceMin(hList,hP);
            double distance = vectorDistance[1];
            double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
            HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
            Pixel pT = {rP,gP,bP};
            listePixelsTransform.emplace_back(pT);
        }
        for (int z=0; z < nTaille3; z+=3)
        {
            ImgOut[z] = listePixelsTransform[z/3].r;
            ImgOut[z+1] = listePixelsTransform[z/3].g;
            ImgOut[z+2] = listePixelsTransform[z/3].b;
        }
        ecrire_image_ppm(("Square"+ to_string(i)+".ppm").data(),ImgOut,nH,nW);
    }
}

void SquareHarmonyQT(const Pixel &cdominant,char * filePath,double sizeBand){
    OCTET *ImgOut,*ImgIn;
    int nH,nW;
    lire_nb_lignes_colonnes_image_ppm(filePath, &nH, &nW);
    int nTaille = nH * nW;
    int nTaille3 = nTaille *3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(ImgOut, OCTET, nTaille3);
    lire_image_ppm(filePath, ImgIn, nH * nW);
    vector<Pixel> listePixels;
    for (int i=0; i < nTaille3; i+=3){Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};listePixels.push_back(p);}
    OCTET r = cdominant.r;OCTET g = cdominant.g;OCTET b = cdominant.b;
    double hB,sB,lB,hS1,hS2,hS3;
    RGBtoHSL(r,g,b,hB,sB,lB);
    addDegree(hB,hS1,90);
    addDegree(hB,hS2,180);
    addDegree(hB,hS3,270);
    std::vector<double> hList;
    hList.emplace_back(hB);
    hList.emplace_back(hS1);
    hList.emplace_back(hS2);
    hList.emplace_back(hS3);
    double influenceSize = (float)(360. / (double)hList.size());
    double radius = influenceSize / 2.;
    vector<Pixel> listePixelsTransform;
    for (Pixel p:listePixels) {
        double hP,sP,lP;
        OCTET rP,gP,bP;
        RGBtoHSL(p.r,p.g,p.b,hP,sP,lP);
        std::vector<double> vectorDistance = distanceMin(hList,hP);
        double distance = vectorDistance[1];
        double Color_Out = (distance / radius) * (sizeBand / 2) + vectorDistance[0];
        HSLtoRGB((float)Color_Out,(float)sP,(float)lP,rP,gP,bP);
        Pixel pT = {rP,gP,bP};
        listePixelsTransform.emplace_back(pT);
    }
    for (int z=0; z < nTaille3; z+=3)
    {
        ImgOut[z] = listePixelsTransform[z/3].r;
        ImgOut[z+1] = listePixelsTransform[z/3].g;
        ImgOut[z+2] = listePixelsTransform[z/3].b;
    }
    ecrire_image_ppm("Image_Transform.ppm",ImgOut,nH,nW);
}

#endif //HARMONIEDESCOULEURS_PROJETIMAGE_HARMONY_H
