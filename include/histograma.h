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

void max(Stats *vetor, int cont, int *vmax);

void min(Stats *vetor, int cont, int *vmin);
void media(Stats *vetor, int cont, double *vmedia);
void desvio(Stats *vetor, int cont, double *vdesvio, double *vmedia);
void total(Stats *vetor, int cont, int *vtotal);



#endif