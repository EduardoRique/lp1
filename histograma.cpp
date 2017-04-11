#include "histograma.h"

int main(int argc, char* argv[]){

	Stats *vetor;
	int cont=0; /**<variavel que conta e armazena o numero de linhas*/

	ifstream arqDados(argv[1]);
	
	if(!arqDados){
		cerr << "O arquivo não pôde ser aberto" << endl;
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
	arqDados.close();

	ofstream saida(argv[2]);
	if(!saida){
		cerr << "O arquivo não pôde ser aberto" << endl;
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
	cout << endl;
	cout << "O maior numero de nascimentos em cada ano: ";
	int vmax[21];
	max(vetor, cont, vmax);
	for(int i=0; i<21; i++){
		cout << vmax[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << "O menor numero de nascimentos em cada ano: ";
	int vmin[21];
	min(vetor, cont, vmin);
	for(int i=0; i<21; i++){
		cout << vmin[i] << " ";
	}
	cout << endl;
	//min(vetor, cont);
	//media(vetor, cont);
	//desvio(vetor, cont);
	//total(vetor, cont);
	
	saida.close();
	
	delete[] vetor;

	return 0;
}