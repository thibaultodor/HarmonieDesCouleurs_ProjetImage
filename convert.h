/* #include "image_ppm.h" */

void OctetToIntPGM(OCTET *ImgIn, int *tabImgIn, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            tabImgIn[i*nW+j] = ImgIn[i*nW+j];
        }
    }
}

void IntToOctetPGM(int *tabImgIn, OCTET *ImgIn, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            ImgIn[i*nW+j] = tabImgIn[i*nW+j];
        }
    }
}

void copieTabPGM(int *ImgIn, int *ImgOut, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            ImgOut[i*nW+j] = ImgIn[i*nW+j];
        }
    }
}

void OctetToIntPPM(OCTET *ImgIn, int *tabImgIn, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            tabImgIn[i*nW+j] = ImgIn[i*nW+j];
            tabImgIn[i*nW+1+j] = ImgIn[i*nW+1+j];
            tabImgIn[i*nW+2+j] = ImgIn[i*nW+2+j];
        }
    }
}

void IntToOctetPPM(int *tabImgIn, OCTET *ImgIn, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            ImgIn[i*nW+j] = tabImgIn[i*nW+j];
            ImgIn[i*nW+1+j] = tabImgIn[i*nW+1+j];
            ImgIn[i*nW+2+j] = tabImgIn[i*nW+2+j];
        }
    }
}

void copieTabPPM(int *ImgIn, int *ImgOut, int nH, int nW){
    for (int i=0; i < nH; i++){
        for (int j=0; j < nW; j++){
            ImgOut[i*nW+j] = ImgIn[i*nW+j];
            ImgOut[i*nW+1+j] = ImgIn[i*nW+1+j];
            ImgOut[i*nW+2+j] = ImgIn[i*nW+2+j];
        }
    }
}