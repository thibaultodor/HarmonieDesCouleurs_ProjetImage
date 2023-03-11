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

// colors using k-means algorithm
vector<Pixel> get_dominant_colors(const vector<Pixel>& pixels, int k) {
    vector<Pixel> centroids;
    kmeans(pixels, centroids, k, 30);
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
    for (int i = 0; i < min(k, static_cast<int>(centroids.size())); i++) {
        dominant_colors.push_back(centroids[cluster_counts[i].second]);
    }

    return dominant_colors;
}

int main(int argc, char* argv[]){
    char cNomImgLue[250];
    int nH, nW, nTaille;

    int taille_palette = 512;

    if (argc != 2)
    {
        printf("Usage: ImageIn.ppm \n");
        exit (1) ;
    }

    sscanf (argv[1],"%s",cNomImgLue) ;

    OCTET *ImgIn,*Palette;

    lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;

    int nTaille3 = nTaille * 3;
    allocation_tableau(ImgIn, OCTET, nTaille3);
    allocation_tableau(Palette, OCTET, (taille_palette*taille_palette)*3);
    lire_image_ppm(cNomImgLue, ImgIn, nH * nW);

    vector<Pixel> listePixels;

    for (int i=0; i < nTaille3; i+=3)
    {
        Pixel p = {ImgIn[i],ImgIn[i+1],ImgIn[i+2]};
        listePixels.push_back(p);
    }

    vector<Pixel> pdominant = get_dominant_colors(listePixels,4);

    for (Pixel p:pdominant) {
        cout << (int)p.r << " " << (int)p.g << " " << (int)p.b << endl;
    }

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
}