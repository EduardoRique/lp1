/** 
*@file histograma.h
*@brief Arquivo cabecalho contendo a definicao de funcoes que realizam a busca
* do maior, do menor, da media, do desvio padrao e o total de nascimentos por ano
*@author Luís Eduardo Rique
*/


#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include <iostream>
#include <fstream>


using namespace std;

 typedef struct
{
	string codigo; /**< Codigo do municipio */
	string nome; /**< Nome do municipio */
	int nascimentos[21]; /**< Numero de nascimentos em cada ano contabilizado */
}Stats;

/**
*@brief Funcao que calcula o maior número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmax ponteiro tipo int que aponta para o vetor com o maior numero de nascimentos
*@return void
*/
void max(Stats *vetor, int cont, int *vmax);

/**
*@brief Funcao que calcula o menor número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmin ponteiro tipo int que aponta para o vetor com o menor numero de nascimentos
*@return void
*/
void min(Stats *vetor, int cont, int *vmin);

/**
*@brief Funcao que calcula a media do número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vmedia ponteiro tipo double que aponta para o vetor com as medias
*@return void
*/
void media(Stats *vetor, int cont, double *vmedia);

/**
*@brief Funcao que calcula o desvio padrao do número de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vdesvio ponteiro tipo double que aponta para o vetor com as medias
*@param *vmedia ponteiro tipo double que aponta para o vetor com as medias
*@return void
*/
void desvio(Stats *vetor, int cont, double *vdesvio, double *vmedia);

/**
*@brief Funcao que calcula o total de nascimentos em cada ano
*@param *vetor ponteiro tipo Stats que aponta para o vetor de informacoes
*@param *cont variavel tipo int que carrega o tamanho do vetor
*@param *vtotal ponteiro tipo int que aponta para o vetor com as medias
*@return void
*/
void total(Stats *vetor, int cont, int *vtotal);



#endif