#include "histograma.h"
#include <cmath>

void max(Stats *vetor, int cont, int *vmax){
    
    for(int ii=0; ii<21; ii++){
        vmax[ii] = vetor[0]. nascimentos[ii];
    }
    for(int i=0; i<21; i++){
        for(int j=0; j<cont; j++){
            if(vmax[i] < vetor[j].nascimentos[i]) vmax[i] = vetor[j].nascimentos[i];
        }
    }
}

void min(Stats *vetor, int cont, int *vmin){

    for(int ii=0; ii<21; ii++){
        vmin[ii] = vetor[2]. nascimentos[ii];
    }
    for(int i=0; i<21; i++){
        for(int j=0; j<cont; j++){
            if(vmin[i] > vetor[j].nascimentos[i]) vmin[i] = vetor[j].nascimentos[i];
        }
    }
}

void media(Stats *vetor, int cont, double *vmedia){
    double soma=0.0;
    for(int i=0; i<21; i++){
        for(int j=0; j<cont; j++){
            soma += vetor[j].nascimentos[i];
        }
        vmedia[i] = soma/21;
    }
}

void desvio(Stats *vetor, int cont, double *vdesvio, double *vmedia){
    for(int i=0; i<21; i++){
        double sum=0.0;
        for(int j=0; j<cont; j++){
            sum+= pow((double)(vetor[j].nascimentos[i] - vmedia[i]), 2);
        }
        vdesvio[i] = sqrt((1/(double)cont)*sum);
    }
}

void total(Stats *vetor, int cont, int *vtotal){
    
    for(int i=0; i<21; i++){
        int soma=0;
        for(int j=0; j<cont; j++){
            soma += vetor[j].nascimentos[i];
        }
        vtotal[i] = soma;
    }
}