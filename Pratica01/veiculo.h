/*
 * veiculo.h
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
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
		int num_rodas;
		Roda * rodas;

	public:
		int getNumRodas();
		void setNumRodas(int nr);

		Veiculo(const char * param);
//	Veiculo(const char * param){
//			this->nome = string(param);
//			this->rodas = NULL;
//			 cout << "Objeto " << this->nome << " construído." << endl;
//   };

	~Veiculo(){
			delete[]rodas;
             cout << "Objeto " << this->nome << " destruido." << endl;
             cout << endl;
   }
};
#endif /* VEICULO_H_ */
