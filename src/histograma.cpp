#include "histograma.h"

int main(){

	Stats *vetor;
	int cont=0; /**<variavel que conta e armazena o numero de linhas*/

	string argv[3] = {"Nascimentos_RN.csv", "totais.dat", "estatisticas.csv"};

	ifstream arqDados(argv[0]);
	
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

	ofstream saida(argv[1]);
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
	ofstream estatisticas(argv[2]);
	if(!estatisticas){
		cerr << "O arquivo não pôde ser aberto" << endl;
	}
	//cout << endl;
	//cout << "O maior numero de nascimentos em cada ano: ";
	int vmax[21];
	max(vetor, cont, vmax);
	
	int vmin[21];
	min(vetor, cont, vmin);

	double vmedia[21];
	media(vetor, cont, vmedia);

	double vdesvio[21];
	desvio(vetor, cont, vdesvio, vmedia);

	int vtotal[21];
	total(vetor, cont, vtotal);

	for(int i=0; i<21; i++){
		estatisticas << vmax[i] << "; ";
		estatisticas << vmin[i] << "; ";
		estatisticas << vmedia[i] << "; ";
		estatisticas << vdesvio[i] << "; ";
		estatisticas << vtotal[i] << "; ";
		for(int j=0; j<1; j++){
			estatisticas << endl;
		}
	}
	
	saida.close();
	arqDados.close();
	delete[] vetor;

	return 0;
}