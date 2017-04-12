/** 
*@file histograma.cpp
*@brief Programa que le e faz manipulacoes em um arquivo
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*/

#include "histograma.h"
#include <iomanip>

/**
*@brief Funcao principal
*/
int main(int argc, char* argv[]){

	Stats *vetor;
	int cont=0; /**<variavel que conta e armazena o numero de linhas*/

	string args[3] = {"Nascimentos_RN.csv", "totais.dat", "estatisticas.csv"};

	ifstream arqDados(argv[1]);
	
	if(!arqDados){
		cerr << "O arquivo não pôde ser aberto 1" << endl;
	}

	string codigo;
	getline(arqDados, codigo); //Pula a primeira linha
	while(getline(arqDados, codigo)){
		cont++;
	}
	cont=cont-1;
	vetor = new Stats[cont]; //Alocacao dinamica do vetor de informacoes

	int readC = 0; /**<variavel que controla a leitura*/
	string nascimentos1; /**<string com dados dos nascimentos*/

	arqDados.clear();
	arqDados.seekg(arqDados.beg);

	int i=0;

	getline(arqDados, codigo);
	while(readC < cont){
		arqDados >> vetor[i].codigo;
		getline(arqDados, vetor[i].nome, ';');
		int somaNM = 0; //Nascimentos do municipio
		for(int j=0; j<21; j++){
			getline(arqDados, nascimentos1, ';');

			if(nascimentos1 == "-") nascimentos1 = "0";
			int aux = stoi(nascimentos1);
			vetor[i].nascimentos[j] = aux;
			somaNM = somaNM + vetor[i].nascimentos[j];
		}
		readC++;
		i++;
	}
	arqDados.clear();
	arqDados.seekg(arqDados.beg);

	getline(arqDados, codigo);
	readC = 0;
	string nascimentos2;

	while(readC < (cont+2)){
		if(readC == cont){
			getline(arqDados, nascimentos2, ';');
			int somaNA=0; //Nascimentos do ano
			for(int j=0; j<21; j++){
				getline(arqDados, nascimentos2, ';');
				for(int k=0; k<cont; k++){
					somaNA += vetor[k].nascimentos[j];
				}
			somaNA=0;
			}
		}
		readC++;
		getline(arqDados, codigo);
	}

	ofstream saida(args[1]);
	if(!saida){
		cerr << "O arquivo não pôde ser aberto 2" << endl;
	}
	int ano = 1994;
	while(ano<2015){
		
		for(int j=0; j<21; j++){
			int s=0;
			for (int k=0; k<cont; k++){
				s = s + vetor[k].nascimentos[j];
			}
			saida << ano << " ";
			saida << s;
			saida << endl;
			ano++;
		}
	}
	ofstream estatisticas(args[2]);
	if(!estatisticas){
		cerr << "O arquivo não pôde ser aberto 3" << endl;
	}
	//cout << endl;
	//cout << "O maior numero de nascimentos em cada ano: ";
	int vmax[21]; /**<vetor que guarda o maior nascimentos do ano*/
	max(vetor, cont, vmax);
	
	int vmin[21]; /**<vetor que guarda o menor nascimentos do ano*/
	min(vetor, cont, vmin);

	double vmedia[21]; /**<vetor que guarda as medias dos nascimentos do ano*/
	media(vetor, cont, vmedia);

	double vdesvio[21]; /**<vetor que guarda o desvio padrao dos nascimentos do ano*/
	desvio(vetor, cont, vdesvio, vmedia);

	int vtotal[21]; /**<vetor que guarda o total dos nascimentos do ano*/
	total(vetor, cont, vtotal);

	for(int i=0; i<21; i++){
		estatisticas << vmax[i] << "; ";
	}
	estatisticas << endl;
	for(int i=0; i<21; i++){
		estatisticas << vmin[i] << "; ";
	}
	estatisticas << endl;
	for(int i=0; i<21; i++){
		estatisticas << vmedia[i] << "; ";
	}
	estatisticas << endl;
	for(int i=0; i<21; i++){
		estatisticas << vdesvio[i] << "; ";
	}
	estatisticas << endl;
	for(int i=0; i<21; i++){
		estatisticas << vtotal[i] << "; ";
		}
	
	double queda = (double)vetor[0].nascimentos[20]/(double)vetor[0].nascimentos[19]; /**<variavel que guarda queda*/
	double cres = (double)vetor[0].nascimentos[20]/(double)vetor[0].nascimentos[19]; /**<variavel que guarda crescimento*/
	
	int inq=0; /**<variavel que guarda o indice de maior queda*/
	int inc=0; /**<variavel que guarda o indice de maior crescimento*/

	for(int i=1; i<cont; i++){
		if(queda > (double)vetor[i].nascimentos[20]/(double)vetor[i].nascimentos[19]){
			queda = (double)vetor[i].nascimentos[20]/(double)vetor[i].nascimentos[19];
			inq = i;
		}
		if(cres < (double)vetor[i].nascimentos[20]/(double)vetor[i].nascimentos[19]){
			 cres = (double)vetor[i].nascimentos[20]/(double)vetor[i].nascimentos[19];
			 inc = i;
		}
	}

	queda = 100*(queda-1);
	cres = 100*(cres-1);
	
	cout << "Municipio com maior taxa de queda 2013-2014: " << vetor[inq].nome << " " << setprecision(4) << queda << "%";
	cout << endl;
	cout << "Municipio com maior taxa de crescimento 2013-2014: " << vetor[inc].nome << " " << setprecision(4) << cres << "%"; 
	cout << endl;

	saida.close();
	arqDados.close();
	delete[] vetor;

	return 0;
}