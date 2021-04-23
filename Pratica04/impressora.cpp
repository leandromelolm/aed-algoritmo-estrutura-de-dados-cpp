/*
 * impressora.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <stdlib.h> // rand()
#include <iostream> // cout

#include <thread>
#include <chrono>

//#define PAUSA(tempo) std::this_thread::sleep_for(std::chrono::milliseconds(tempo * 1000));

#include "fila.h"

using namespace std;

void PAUSE(int n) {
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {

       }
   }
}

int main4() {
    cout<<"Impressora"<<endl<<endl;
	Fila<int> impressora(10);
	int i = 0;
	while (1) {
		// 70% de chance do usuário mandar imprimir um documento
		if ((rand() % 100) < 30) {
			if (!impressora.cheia()) {
				cout << "Adicionado documento " << ++i << endl;
				impressora.enfileira(i);
			}
		}

		cout << "Status: " << impressora.tamanho() << " item(s) na fila" << endl;

		// 50% de chance da impressora imprimir um documento
		if ((rand() % 100) < 70) {
			if (!impressora.vazia()) {
				cout << "Imprimindo documento " << impressora.desenfileira() << endl;
			}
		}
        //PAUSA(1);
		PAUSE(10000);
	}
}




