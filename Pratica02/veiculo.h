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

		void mover();

	protected:
		string nome;
};

class Terrestre : public Veiculo{
	public:
//construtor publico na subclasses
		Terrestre(const char * n) : Veiculo(n){
			this-> nome = n;
			this->cap_pass=5; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<endl;
			cout<<"Veiculo terrestre "<<nome<<" construido"<<endl;

		};
		int getCapacidadeMaxima();
		void setCapacidadeMaxima(int cp);

		virtual void mover();

	private:
		int cap_pass; // Número máximo de passageiros.
};

class Aquatico : public  Veiculo{
	public:
		Aquatico(const char * n): Veiculo(n){
			this->nome = n;
			this->carga_max = 10; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<endl;
			cout<< "Veiculo Aquatico "<<nome<<" construído"<<endl;
		};
		int getCargaMaxima();
		void setCargaMaxima(float cm);

//		virtual void mover();

	private:
		float carga_max; // Carga máxima em toneladas.
};
class Aereo : public Veiculo{
	public:
		Aereo(const char * n) : Veiculo(n){
			this->nome = n;
			this->vel_max=100; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<endl;
			cout<<"Veiculo aéreo "<<nome<<" construído"<<endl;
		};
		int getVelocidadeMaxima();
		void setVelocidadeMaxima(float vm);

//		virtual void mover();

	private:
		float vel_max; // Velocidade máxima em km/h.
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
