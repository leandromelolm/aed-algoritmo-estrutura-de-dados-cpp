/*
 * Veiculo.h
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
 */

#include <iostream>
#ifndef VEICULO_H
#define VEICULO_H
using namespace std;

class Veiculo{

};

class Terrestre : public Veiculo{

};

class Aquatico : public  Veiculo{
public:

};

class Aereo : public Veiculo{

};

class Anfibio : public Terrestre, public Aquatico{
public:

};
#endif // VEICULO_H
