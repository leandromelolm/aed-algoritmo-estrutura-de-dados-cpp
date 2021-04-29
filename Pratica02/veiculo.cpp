/*
 * Veiculo.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
 */

#include <iostream>
#include "veiculo.h"

using namespace std;

int Terrestre::getCapacidadeMaxima(){
	cout<<"Veiculo Terrestre - Capacidade Máxima: "<<cap_pass<<endl;
	return cap_pass;
}
void Terrestre::setCapacidadeMaxima(int cp){
	this->cap_pass = cp;
	cout<<"Veiculo Terrestre - Usando Método setCapacidadeMaxima:  "<<cap_pass<<endl;
}

int Aquatico::getCargaMaxima(){
	cout<<"Veiculo Aquatico - Carga Máxima: "<<carga_max<<endl;
	return carga_max;
}
void Aquatico::setCargaMaxima(float cm){
	this->carga_max=cm;
	cout<<"Veiculo Aquatico - Metodo setCargaMaxima: "<<carga_max<<endl;
}
int Aereo::getVelocidadeMaxima(){
	cout<<"Veiculo Aereo - Velocidade Máxima: "<<vel_max<<endl;
	return vel_max;
}
void Aereo::setVelocidadeMaxima(float vm){
	this->vel_max = vm;
	cout<<"Veiculo Aereo: Método setVelocidadeMáxima: "<<vel_max<<endl;
}

//Parte 4: Trabalhando com métodos virtuais
//Classe Veiculo é abstrata, os métodos ficam sem implementação
//void Veiculo::mover(){
//	cout<<"Veiculo "<<nome<<" moveu"<<endl;
//}

void Terrestre::mover(){
	cout<<"Veiculo terrestre "<<nome<<" moveu"<<endl;
}
void Aquatico::mover(){
	cout<<"Veiculo aquático "<<nome<<" moveu"<<endl;
}
void Aereo::mover(){
	cout<<"Veiculo aéreo "<<nome<<" moveu"<<endl;
}







