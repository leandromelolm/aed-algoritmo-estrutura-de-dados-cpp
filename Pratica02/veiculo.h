/*
 * Veiculo.h
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#include <iostream>
#ifndef VEICULO_H
#define VEICULO_H
using namespace std;

class Veiculo
{
    public:
        Veiculo(const char * name){
        this->nome = name;
        cout << "Construtor veículo: Objeto "<<nome<<" criado com sucesso"<<endl<<endl;
        };
        virtual ~Veiculo(){
        cout << "Destrutor veículo: Objeto "<<nome<<" destruído com sucesso" <<endl<<endl;
        };
        virtual void mover() = 0;
    protected:
        string nome;
};

class Terrestre : public virtual Veiculo{
public:
    	Terrestre(const char * name):Veiculo(name){
    	this->nome=name;
    	cout<<"Construtor Terrestre: Objeto "<<nome<<" criado com sucesso"<<endl<<endl;
    	};
    	virtual ~Terrestre(){
    	cout<<"Destrutor terrestre: Objeto "<<nome<<" destruido com sucesso"<<endl<<endl;
    	};
    	void setCapacidadeMax(int valor);
        int getCapacidadeMax();
        virtual void mover();
private:
    	string nome;
    	int cap_pass = 5;
protected:
       Terrestre():Veiculo("qualquer"){
        cout<<"Construtor Terrestre: Objeto "<<nome<<" criado com sucesso"<<endl<<endl;
       };
};

class Aquatico : public virtual Veiculo{
public:
    	Aquatico(const char * name):Veiculo(name){
        this->nome=name;
    	cout<<"Construtor Aquático: Objeto veiculo aquatico criado com sucesso"<<endl<<endl;
    	};
    	virtual ~Aquatico(){
    	cout<<"Destrutor Aquático: Objeto veiculo aquatico destruido com sucesso"<<endl<<endl;
    	};
    	void setCargaMax(float valor);
    	float getCargaMax();
        virtual void mover();
private:
        string nome;
        float carga_max = 10;
protected:
        Aquatico(): Veiculo("qualquer"){
            cout<<"Construtor Aquático: Objeto veiculo aquatico criado com sucesso"<<endl<<endl;
        };
};

class Aereo : public Veiculo{
public:
    	Aereo(const char * name):Veiculo(name){
        this->nome=name;
    	cout<<"Destrutor Áereo: Objeto veiculo aereo criado com sucesso"<<endl<<endl;
    	};
    	virtual ~Aereo(){
    	cout<<"Destrutor Áereo: Objeto veiculo aereo destruido com sucesso"<<endl<<endl;
    	};
    	void setVelocidadeMax(float valor);
    	float getVelocidadeMax();
        virtual void mover();
private:
        string nome;
        float vel_max = 100;
};

class Anfibio : public Terrestre, public Aquatico{
public:
        Anfibio(const char * nome) : Veiculo(nome), Terrestre(), Aquatico(){
            this->name = nome;
        };
        virtual ~Anfibio(){
        cout<<"Destrutor Anfíbio: Objeto veículo anfíbio destruído com sucesso"<<endl<<endl;
        };
        virtual void mover();

private:
        string name;
};
#endif // VEICULO_H
