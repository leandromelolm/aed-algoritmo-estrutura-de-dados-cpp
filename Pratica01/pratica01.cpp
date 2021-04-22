/*
 * pratica01.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */
#include <iostream>

using namespace std;

class Veiculo{
private:
	string nome;
	int num_rodas=4;

public:
	int getNumRodas();
	void setNumRodas(int nr);

	Veiculo(const char *param){
			this->nome = string(param);
			 cout << "Objeto " << this->nome << " construído." << endl;
};
~Veiculo(){
              cout << "Objeto " << this->nome << " destruido." << endl;
}
};

int Veiculo::getNumRodas(){
	cout << "Objeto"<< this->nome<<" com "<< this->num_rodas << " números de rodas." << endl;
	return num_rodas;
}

	void Veiculo::setNumRodas(int nr){//permite a modificação ao atributo encapsulado
		num_rodas=nr;
		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " números de rodas." << endl;
	}


	int main(){
		Veiculo * obj1 = new Veiculo("v1");
			{
				Veiculo * obj2 = new Veiculo("v2");
					{
						Veiculo * obj3 = new Veiculo("v3");
						obj1->setNumRodas(2);

						delete obj3;
					}
					delete obj2;
			}
			delete obj1;
	}




