#include <iostream>
#include <time.h>
#include "pilha_ligada.h"
#include "pilha_array.h"
#include "pilha.h"


#define MAX 10

using namespace std;

int main() {

//	PilhaLigada<int> pilha(MAX);

	Pilha *pilha;
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


	return 0;
}


