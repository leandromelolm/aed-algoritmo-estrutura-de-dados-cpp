/*
 * veiculo.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#include <iostream>
#include "veiculo.h"

int Veiculo::getNumRodas(){
	cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " números de rodas." << endl;
	return num_rodas;
}

void Veiculo::setNumRodas(int nRodas){//permite a modificação ao atributo encapsulado
		this->num_rodas=nRodas;
		this->rodas = new Roda[nRodas];
		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " números de rodas." << endl;
}


