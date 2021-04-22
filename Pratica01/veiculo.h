/*
 * veiculo.h
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED

using namespace std;

class Roda{

	public:
		Roda(){
			cout<<"Objeto Roda  construido"<<endl;
		}
		~Roda(){
			cout <<"Objeto roda destruido"<<endl;
		}

};


class Veiculo{
	private:
		string nome;
		int num_rodas=4;
		Roda* rodas;

	public:
		int getNumRodas();
		void setNumRodas(int nRodas);

	Veiculo(const char *param){
			this->nome = string(param);
			this->rodas = NULL;
			 cout << "Objeto " << this->nome << " construído." << endl;
   };
	~Veiculo(){
              cout << "Objeto " << this->nome << " destruido." << endl;
              delete[]rodas;
   }
};



#endif /* VEICULO_H_ */
