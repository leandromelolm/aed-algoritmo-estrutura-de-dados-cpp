/*
 * Veiculo.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#include <iostream>
#include "veiculo.h"

using namespace std;
void Terrestre::setCapacidadeMax(int valor){
    this->cap_pass=valor;
}

int Terrestre::getCapacidadeMax(){
    return cap_pass;
}

void Terrestre::mover(){
    cout<<"Movimentação terrestre: Veículo terreste "<<nome<<" moveu-se"<<endl<<endl;
}

void Aquatico::setCargaMax(float valor){
    this->carga_max=valor;
}

float Aquatico::getCargaMax(){
    return carga_max;
}

void Aquatico::mover(){
    cout<<"Movimentação terrestre: Veículo aquatico "<<nome<<" moveu-se"<<endl<<endl;
}

void Aereo::setVelocidadeMax(float valor){
    this->vel_max=valor;
}

float Aereo::getVelocidadeMax(){
    return vel_max;
}

void Aereo::mover(){
    cout<<"Movimentação terrestre: Veículo aereo "<<nome<<" moveu-se"<<endl<<endl;
}

void Anfibio::mover(){
    //cout<<"Movimentação anfíbia: Veículo anfíbio "<<this->name<<" moveu-se"<<endl<<endl;
    Terrestre::mover();
    Aquatico::mover();
}
