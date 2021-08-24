/*
 * fila.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE
 */

#include <iostream>
#include "fila.h"

#define MAX 100

using namespace std;

int mainF() {
	Fila<int> fila(MAX);

	try {
		cerr << "Testando enfileira() [normal]: ";
		for (int i = 0; i < MAX; i++) {
			fila.enfileira(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
	if (fila.tamanho() != MAX) {
		cerr << "FALHOU (tam = " << fila.tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando enfileira() [overflow]: ";
		fila.enfileira(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	cerr << "Testando desenfileira() [normal]: ";
	for (int i = 0; i < MAX; i++) {
		if (fila.desenfileira() != i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;


	cerr << "Testando tamanho() [vazia]: ";
	if (fila.tamanho() != 0) {
		cerr << "FALHOU (tam = " << fila.tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;


	try {
		cerr << "Testando desenfileira() [underflow]: ";
		fila.desenfileira();
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	return 0;
}





