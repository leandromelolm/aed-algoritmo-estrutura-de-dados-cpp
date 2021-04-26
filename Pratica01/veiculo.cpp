/*
 * veiculo.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
 */

#include <iostream>
#include "veiculo.h"

int Veiculo::getNumRodas(){
	cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " rodas." << endl;
	return num_rodas;
}

//set permite a modificação do  atributo encapsulado
void Veiculo::setNumRodas(int nr){
		this->num_rodas=nr;
		this->rodas= new Roda[nr];
		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " rodas." << endl;
		cout << endl;
}

Veiculo::Veiculo(const char *param){
				this->nome = string(param);
				cout << "Objeto " << this->nome << " construído." << endl;
				this->rodas = NULL;
//				this->num_rodas=0;
}


