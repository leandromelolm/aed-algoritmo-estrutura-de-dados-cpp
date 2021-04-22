/*
 * pratica01.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */
#include <iostream>
#include "veiculo.h"

using namespace std;

	int main(){

		cout << "Pratica01" << endl;
		cout << "Primeira Aplicação C++" << endl;

		Veiculo * obj1 = new Veiculo("v1");
			{
				Veiculo * obj2 = new Veiculo("v2");
					{
						Veiculo * obj3 = new Veiculo("v3");
							{
								obj1->setNumRodas(2);
//								obj2->getNumRodas();
								obj2->setNumRodas(3);
								obj3 ->setNumRodas(8);

								delete obj3;
							}
							delete obj2;
					}
					delete obj1;
			}
	Veiculo * veiculo4 = new Veiculo("v4");
	veiculo4->setNumRodas(4);
	delete veiculo4;
}


