/** 
*@file funcoes.cpp
*@brief Arquivo de corpo contendo a implentacao de funcoes que realizam a busca
* do maior, do menor, da media, do desvio padrao e o total de nascimentos por ano
*@author Luís Eduardo Rique
*/

#include "histograma.h"
#include <cmath>

/**
*@brief Funcao que calcula o maior número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmax ponteiro tipo int que aponta para o vetor com o maior numero de nascimentos
*@return void
*/
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

/**
*@brief Funcao que calcula o menor número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmin ponteiro tipo int que aponta para o vetor com o menor numero de nascimentos
*@return void
*/
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
*@brief Funcao que calcula a media do número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmedia ponteiro tipo double que aponta para o vetor com as medias
*@return void
*/
void media(Stats *vetor, int cont, double *vmedia){
    double soma=0.0;
    for(int i=0; i<21; i++){
        for(int j=0; j<cont; j++){
            soma += vetor[j].nascimentos[i];
        }
        vmedia[i] = soma/21;
    }
}

/**
*@brief Funcao que calcula o desvio padrao do número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vdesvio ponteiro tipo double que aponta para o vetor com as medias
*@param *vmedia ponteiro tipo double que aponta para o vetor com as medias
*@return void
*/
void desvio(Stats *vetor, int cont, double *vdesvio, double *vmedia){
    for(int i=0; i<21; i++){
        double sum=0.0;
        for(int j=0; j<cont; j++){
            sum+= pow((double)(vetor[j].nascimentos[i] - vmedia[i]), 2);
        }
        vdesvio[i] = sqrt((1/(double)cont)*sum);
    }
}

/**
*@brief Funcao que calcula o total de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vtotal ponteiro tipo int que aponta para o vetor com as medias
*@return void
*/
void total(Stats *vetor, int cont, int *vtotal){
    
    for(int i=0; i<21; i++){
        int soma=0;
        for(int j=0; j<cont; j++){
            soma += vetor[j].nascimentos[i];
        }
        vtotal[i] = soma;
    }
}