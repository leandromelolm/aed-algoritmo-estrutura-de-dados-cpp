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
		this->num_rodas=nr; // num_rodas exibe a quantidade de rodas
		this->rodas= new Roda[nr](); // executa o construtor Roda. cria a quantidade de objetos passado por nr, chamando o construtor padrão
		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " rodas." << endl;
		cout << endl;
}

/*Construtor de Veiculo*/
//Veiculo::Veiculo(const char *param){
//				this->nome = string(param);
//				cout << "Objeto " << this->nome << " construído." << endl;
//				this->rodas = NULL;
//				this->num_rodas=0;
//}


