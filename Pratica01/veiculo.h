/*
 * veiculo.h
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#ifndef VEICULO_H_
#define VEICULO_H_

using namespace std;

class Roda{
	public:

	Roda();
	~Roda();

//		Roda(){
//			cout<<"Objeto roda construido"<<endl;
//		}
//		~Roda(){
//			cout <<"Objeto roda destruido"<<endl;
//		}

};



class Veiculo{
	private:
		string nome;
		int num_rodas;
		Roda *rodas;
	public:

		int getNumRodas();

		void setNumRodas(int nr);

		/*Protótipo do Método Construtor*/
			Veiculo(const char *param);
		/*Protótipo do Método Destrutor*/
				~Veiculo();

//	int getNumRodas(){
//		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " rodas." << endl;
//		return num_rodas;
//	}
//
///*set permite a modificação do  atributo encapsulado*/
//	void setNumRodas(int nr){
//		this->num_rodas=nr; // num_rodas exibe a quantidade de rodas
//		this->rodas= new Roda[nr](); // executa o construtor Roda. cria a quantidade de objetos passado por nr, chamando o construtor padrão
//		cout << "Objeto "<< this->nome<<" com "<< this->num_rodas << " rodas." << endl;
//		cout << endl;
//	}
//
//	Veiculo(const char *param){
//			this->nome = string(param);
//			this->rodas = NULL;
//			this->num_rodas=0;
//			 cout << "Objeto " << this->nome << " construído." << endl;
//   };
//
//	~Veiculo(){
//			delete[]rodas;
//			 cout<<"destruição de "<<num_rodas<<" roda(s) do objeto "<<nome<<endl;
//             cout << "Objeto " << this->nome << " destruido." << endl;
//
//             cout << endl;
//   }

};

#endif /* VEICULO_H_ */
