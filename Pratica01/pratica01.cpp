/*
 * pratica01.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */
#include <iostream>
#include "veiculo.h"
#include <chrono>

using namespace std;
using namespace chrono;

int main(){
	cout << "Pratica01" << endl;
	cout << "Primeira Aplicação C++" << endl;
	cout <<endl;

	/*Medição de tempo - Prática 01 */
	auto start = std::chrono::high_resolution_clock::now();//Inicio de Medição de tempo

	/*Medição de tempo - steady_clock */
//	steady_clock::time_point t1 = steady_clock::now();

	int i;//
	for(i=0;i<50000;i++){



/*Objeto delcarado sem o operador new */
		Veiculo veiculo5("v5"); // Objeto é destruido ao final do bloco automaticamente

/* Objeto declarado como ponteiro e estanciado com o operador new */
		Veiculo * obj1 = new Veiculo("v1");
		{
			obj1->setNumRodas(2);
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


	} //Bloco For

	/*Medição de tempo - steady_clock */
//	steady_clock::time_point t2 = steady_clock::now();
//	duration<double> tempo = duration_cast<duration<double>>(t2-t1);
//	cout<< "Tempo de trabalho: " << tempo.count()<<" segundos"<<endl;


	/*Medição de tempo - Prática 01 - continuação do código */
	auto finish = std::chrono::high_resolution_clock::now(); //Fim da medição de tempo
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>
	(finish-start).count() / 1000;

	cout << "tempo[us] = " << elapsed << endl;
	double segundos = 0;
		segundos =elapsed/1000000;
	cout << "Tempo em segundos = " << segundos << endl;

}

/*
 * //Codido para usar a biblioteca chrono : medir tempo de processamento do programa
 * Medição de tempo - Prática 01
 *
 * Como Configurar o projeto para utilizar C++11
 *
 *  Vá em Project Properties > C++ Build > Settings: no caso do Cygwin procure por
 *	“Dialect” e selecione “ISO C++11” em “Language standard” (Essa configuração permite
 *	usar o código a seguir)
 *
 *
 * auto start = std::chrono::high_resolution_clock::now();//Inicio de Medição de tempo
 *
 * // Aqui fica o código
 *
 * auto finish = std::chrono::high_resolution_clock::now(); //Fim da medição de tempo
 * long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>
 * (finish-start).count() / 1000;
 * cout << "tempo[us] = " << elapsed << endl;
 *
 * */

