/*
 * fila.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE
 */

#include <iostream>
#include "fila.h"
#include "fila_array.h"
#include "fila_ligada.h"

#include <thread>
#include <chrono>
#define PAUSA(tempo) std::this_thread::sleep_for(std::chrono::milliseconds(tempo * 1000));

#define MAX 100

using namespace std;

int mainQueueTest() {
//int main() {
//	FilaLigada<int> fila(MAX);

	Fila<int> *fila;
	fila = new FilaLigada<int>(MAX); // Fila Ligada
//	fila = new FilaArray<int>(MAX); // Fila Array

	try {
		cerr << "Testando enfileira() [normal]: ";
		for (int i = 0; i < MAX; i++) {
			fila->enfileira(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
	if (fila->tamanho() != MAX) {
		cerr << "FALHOU (tam = " << fila->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando enfileira() [overflow]: ";
		fila->enfileira(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	cerr << "Testando desenfileira() [normal]: ";
	for (int i = 0; i < MAX; i++) {
		if (fila->desenfileira() != i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;


	cerr << "Testando tamanho() [vazia]: ";
	if (fila->tamanho() != 0) {
		cerr << "FALHOU (tam = " << fila->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;


	try {
		cerr << "Testando desenfileira() [underflow]: ";
		fila->desenfileira();
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

//	FilaLigada<int> impressora(10);

	Fila<int> *impressora;
	impressora = new FilaArray<int>(10);
//	impressora = new FilaLigada<int>(10);

	int i = 0;
	while (1) {
		// 70% de chance do usu�rio mandar imprimir um documento
		if ((rand() % 100) < 70) {
			if (!impressora->cheia()) {
				cout << "Adicionado documento " << ++i << endl;
				impressora->enfileira(i);
			}
		}

		cout << "Status: " << impressora->tamanho() << " item(s) na fila" << endl;

		// 50% de chance da impressora imprimir um documento
		if ((rand() % 100) < 70) {
			if (!impressora->vazia()) {
				cout << "Imprimindo documento " << impressora->desenfileira() << endl;
			}
		}

		PAUSA(1);
	}

	return 0;
}





