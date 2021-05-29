#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <iostream>
#include "arranjo.h"

using namespace std;

class Aluno {
	private:
		string nome;
		string mat;
	public:
		Aluno() {}
		Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {}
	friend class Arranjo<Aluno>; //romper a proteção aos membros de uma classe usando o "friend"
};
template<>
 void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {  //Member declaration not found - mesmo com esse problema o  projeto executa normalmente
	if(idx>=tamanho){
		throw "não é possível atribuir valor para essa posição de aluno no array";
	}
	// atribui nome e mat do item do array a partir de aluno
	itens[idx].nome = aluno.nome;
	itens[idx].mat = aluno.mat;
}
template<>
void Arranjo<Aluno>::exibir() { //Member declaration not found - mesmo com esse problema o  projeto executa normalmente
// exibi cada aluno do array no formato "idx : mat = nome"
	cout<<"\nidx: Mat   =   nome:"<<endl;
	for(int i=0; i<10;i++){
		cout<<i<<" :  "<<itens[i].mat<<"  =   "<<itens[i].nome<<endl;
	}
}
#endif // ALUNO_H_INCLUDED
