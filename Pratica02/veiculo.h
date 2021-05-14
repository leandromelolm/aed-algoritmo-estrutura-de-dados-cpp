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
		Veiculo(const char * nome){
				this-> nome= nome;
				this->n=n;
				cout<<endl;
				cout << "Veiculo " << this->nome <<" construido"<<endl;
				cout<<endl;
		};
		virtual ~Veiculo(){
			cout<<"Veículo "<<nome<<" destruido"<<endl;
		};
//		virtual void mover();
		virtual void mover() =0;//4.9 - Trabalhando com métodos virtuais. <=0> Torna a classe abstrata

		Veiculo(int  n){ //5.3 - Construtor para  ser usando no construtor  protegido na classe Terrestre e Aquatico
			this->n=n;
		};

	protected:
		string nome;
		int n;
};

class Terrestre : public virtual Veiculo{
	public:
// 2.8 - construtor publico na subclasses
		Terrestre(const char * nome) : Veiculo(nome){
			this-> nome = nome;
			this->cap_pass=5; // 3.1 -  Inicialização da propriedade no construtor
			cout<<"Veiculo terrestre "<<this->nome<<" construido"<<endl;
		};
		virtual ~Terrestre(){
			cout<<"Veiculo terrestre <"<<nome<<"> destruído"<<endl;
		};

		int getCapacidadeMaxima();
		void setCapacidadeMaxima(int cp);

		virtual void mover(); //4.1 - Trabalhando com métodos virtuais

	private:
		int cap_pass; // Número máximo de passageiros.

	protected:
		Terrestre():Veiculo(n){//5.3 - Criado construtor  sem parâmetro, chamando construtor de Veiculo com um parâmetro qualquer (n).
			this->cap_pass=5;
			cout<<"Veiculo terrestre "<<nome<<" construído via construtor protegido"<<endl;
		};
};

class Aquatico : public virtual Veiculo{
	public:
		Aquatico(const char * nome): Veiculo(nome){
			this->nome = nome;
			this->carga_max = 10; // 3.1 -  Inicialização da propriedade no construtor
			cout<< "Veiculo Aquatico "<<nome<<" construído"<<endl;
		};
		virtual ~Aquatico(){
			cout<<"Veiculo aquático <"<<nome<<"> destruído"<<endl;
		};

		int getCargaMaxima();
		void setCargaMaxima(float cm);

		virtual void mover(); //4.1 - Trabalhando com métodos virtuais

	private:
		float carga_max; // Carga máxima em toneladas.

	protected: // quando declarado como protected a instruções podem ser usadas na subclasse
		Aquatico():Veiculo(n){ //5.3 - Criado construtor  sem parâmetro, chamando construtor de Veiculo com um parâmetro qualquer (n).
			this->carga_max = 10;
			cout<<"Veiculo aquático "<<nome<<" construído via construtor protegido"<<endl;
		};
};
class Aereo : public Veiculo{
	public:
		Aereo(const char * n) : Veiculo(n){
			this->nome = n;
			this->vel_max=100; // Parte 3 Passo 1 -  Inicialização da propriedade no construtor
			cout<<"Veiculo aéreo "<<nome<<" construído"<<endl;
		};
		virtual ~Aereo(){
			cout<<"Veiculo aéreo <"<<nome<<"> destruído"<<endl;
		};

		int getVelocidadeMaxima();
		void setVelocidadeMaxima(float vm);

		virtual void mover();  //Parte 4: Trabalhando com métodos virtuais

	private:
		float vel_max; // Velocidade máxima em km/h.
};
//5 -  Herança Multipla
class Anfibio: public Terrestre, public Aquatico{
public:
	Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {
		this->nome = nome;
		cout<<"Veiculo anfíbio<"<<this->nome<<"> construído"<<endl;
	};
	virtual ~Anfibio(){
		cout<<"Veiculo anfíbio<"<<nome<<"> destruído"<<endl;
	};
	virtual void mover();
};
#endif // VEICULO_H
