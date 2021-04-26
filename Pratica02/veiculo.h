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
	public:
		Veiculo(const char * n){
				this-> nome= n;
				cout << "Veiculo " << nome <<" construido"<<endl;
		};

	protected:
		string nome;
};

class Terrestre : public Veiculo{
	public:
//construtores publicos na subclasses
		Terrestre(const char * n) : Veiculo(n){
			this-> nome = n;
			cout<<"Veiculo terrestre "<<nome<<" construido"<<endl;
		};
};

class Aquatico : public  Veiculo{
	public:
		Aquatico(const char * n): Veiculo(n){
			this->nome = n;
			cout<< "Veiculo Aquatico "<<nome<<" construído"<<endl;
		};
};
class Aereo : public Veiculo{
	public:
		Aereo(const char * n) : Veiculo(n){
			this->nome = n;
			cout<<"Veiculo aéreo "<<nome<<" construído"<<endl;
		};
};

class Anfibio : public Terrestre, public Aquatico{
//	public:
//		Anfibio(const char * nome) : Veiculo(nome), Terrestre(),Aquatico(){
//			this->nomeAnfibio = nome;
//		};
//	private:
//		string nomeAnfibio;
};

#endif // VEICULO_H
