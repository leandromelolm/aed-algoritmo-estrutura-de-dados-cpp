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
				cout<<endl;
				cout << "Veiculo " << nome <<" construido"<<endl;
				cout<<endl;
		};
		~Veiculo(){
			cout<<"Veículo "<<nome<<" destruido"<<endl;
		};

		virtual void mover();//Parte 4: Trabalhando com métodos virtuais

	protected:
		string nome;
};

class Terrestre : public Veiculo{
	public:
//construtor publico na subclasses
		Terrestre(const char * n) : Veiculo(n){
			this-> nome = n;
			this->cap_pass=5; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<"Veiculo terrestre "<<nome<<" construido"<<endl;

		};
		~Terrestre(){
			cout<<"Veiculo terrestre <"<<nome<<"> destruído"<<endl;
		};

		int getCapacidadeMaxima();
		void setCapacidadeMaxima(int cp);

		virtual void mover(); //Parte 4: Trabalhando com métodos virtuais

	private:
		int cap_pass; // Número máximo de passageiros.
};

class Aquatico : public  Veiculo{
	public:
		Aquatico(const char * n): Veiculo(n){
			this->nome = n;
			this->carga_max = 10; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<< "Veiculo Aquatico "<<nome<<" construído"<<endl;
		};
		~Aquatico(){
			cout<<"Veiculo aquático <"<<nome<<"> destruído"<<endl;
		}

		int getCargaMaxima();
		void setCargaMaxima(float cm);

		virtual void mover(); //Parte 4: Trabalhando com métodos virtuais

	private:
		float carga_max; // Carga máxima em toneladas.
};
class Aereo : public Veiculo{
	public:
		Aereo(const char * n) : Veiculo(n){
			this->nome = n;
			this->vel_max=100; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<"Veiculo aéreo "<<nome<<" construído"<<endl;
		};
		~Aereo(){
			cout<<"Veiculo aéreo <"<<nome<<"> destruído"<<endl;
		}

		int getVelocidadeMaxima();
		void setVelocidadeMaxima(float vm);

		virtual void mover();  //Parte 4: Trabalhando com métodos virtuais

	private:
		float vel_max; // Velocidade máxima em km/h.
};

#endif // VEICULO_H
