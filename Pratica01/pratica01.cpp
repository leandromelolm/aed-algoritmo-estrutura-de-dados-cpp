/*
 * pratica01.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
 */
#include <iostream>
#include "veiculo.h"
#include <chrono>

using namespace std;

int main(){


//	auto start = std::chrono::high_resolution_clock::now();//Inicio de Medição de tempo
//	int i;
//	for(i=0;i<5000;i++){

		cout << "Pratica01" << endl;
		cout << "Primeira Aplicação C++" << endl;
		cout <<endl;

// Objeto delcarado sem o operador new
//		Veiculo veiculo5("v5"); // Objeto é destruido ao final do bloco automaticamente

// Objeto declarado como ponteiro e estanciado com o operador new
		Veiculo * obj1 = new Veiculo("v1");
		{ obj1->setNumRodas(2);
			Veiculo  * obj2 = new Veiculo("v2");
				{
						Veiculo * obj3 = new Veiculo("v3");
						{
//								obj1->setNumRodas(2);
//								obj2->getNumRodas();
								obj2->setNumRodas(3);
								obj3 ->setNumRodas(4);
						}
						delete obj2;
						delete obj3;
				}
				delete obj1;
		}
	Veiculo * veiculo4 = new Veiculo("carro 4");
	veiculo4->getNumRodas();
	delete veiculo4;


//	}
//	auto finish = std::chrono::high_resolution_clock::now(); //Fim da medição de tempo
//	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>
//	(finish-start).count() / 1000;
//	cout << "tempo[us] = " << elapsed << endl;

}

