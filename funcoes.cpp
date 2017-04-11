#include "histograma.h"

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
/**
media(Stats *vetor, int cont){

}
desvio(Stats *vetor, int cont){

}
total(Stats *vetor, int cont){

}*/