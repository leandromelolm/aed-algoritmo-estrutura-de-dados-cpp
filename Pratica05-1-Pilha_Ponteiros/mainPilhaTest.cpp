#include <iostream>
#include <time.h>
#include "pilha_ligada.h"
#include "pilha_array.h"
#include "pilha.h"


#define MAX 10

using namespace std;

int ehOperador(char token) {
	switch(token) {
	case '+':
	case '-':
	case '*':
	case '/': return 1;
	default: return 0;
	}
}

int avalia(char token, int valorEsq, int valorDir) {
	switch(token) {
	case '+': return valorEsq + valorDir;
	case '-': return valorEsq - valorDir;
	case '*': return valorEsq * valorDir;
	case '/': return valorEsq / valorDir;
	default: return 0;
	}
}

int polonesa(const char * exp) {
	PilhaLigada<int> pilha(10);
	while (*exp) {
		char token = *exp;
		if (ehOperador(token)) {
			int valorDir = pilha.desempilha();
			int valorEsq = pilha.desempilha();
			int resultado = avalia(token, valorEsq, valorDir);
			pilha.empilha(resultado);
		} else {
			int valor = (int)(token - '0');
			pilha.empilha(valor);
		}
		exp++;
	}
	return pilha.desempilha();
}


int mainTest() {
//int main() {

//	PilhaLigada<int> pilha(MAX);

	Pilha<int> *pilha;
	pilha = new PilhaLigada<int>(MAX); // Pilha Ligada
//	pilha = new PilhaArray<int>(MAX); //  Pilha Array


	try {
		cerr << "Testando empilha() [normal]: ";
		for (int i = 0; i < MAX; i++) {
//			pilha.empilha(i);
			pilha->empilha(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
	if (pilha->tamanho() != MAX) {
		cerr << "FALHOU (tam = " << pilha->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando empilha() [overflow]: ";
		pilha->empilha(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	cerr << "Testando desempilha() [normal]: ";
	for (int i = (MAX - 1); i >= 0; i--) {
		if (pilha->desempilha() != i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando tamanho() [vazia]: ";
	if (pilha->tamanho() != 0) {
		cerr << "FALHOU (tam = " << pilha->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando desempilha() [underflow]: ";
		pilha->desempilha();
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}


	//Código para atrasar a execução do teste da calculadora Polonesa
	time_t start_t, end_t;
	double diff_t;
//	  cout<<"Inicio do programa Polonesa\n";
	time(&start_t);
	while(diff_t<=2.000000){
		time(&end_t);
		diff_t = difftime(end_t, start_t);
	}
	cout<<"\n";
	cout<<"Inicio do teste de calculadora Polonesa\n";

	cout <<"Valor calculado('23+31-*'): "<<polonesa("23+31-*") << endl;
	cout <<"Valor calculado('93*42/-'): "<< polonesa("93*42/-") << endl;
	cout <<"Valor calculado('42*93/-'): "<< polonesa("42*93/-") << endl;
	cout <<"Valor calculado('31+23-*'): "<<polonesa("31+23-*") << endl;
	cout <<"Valor calculado('39*24+-'): "<< polonesa("39*24/-") << endl;



	return 0;
}


