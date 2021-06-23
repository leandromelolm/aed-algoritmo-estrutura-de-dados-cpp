#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <iostream>
#include "arranjo.h"

using namespace std;

class Aluno {
	private:
		string nome_alu;
		string mat_alu;
	public:
		Aluno() {}
		Aluno(const char * nome, const char * mat) : nome_alu(nome), mat_alu(mat) {}
	friend class Arranjo<Aluno>; //romper a proteção aos membros de uma classe usando o "friend"
};
template<>
 void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {  //Member declaration not found - mesmo com esse problema o  projeto executa normalmente
	if(idx>=tamanho){
		throw "não é possível atribuir valor para uma posição de aluno no array";
	}else{
	// atribui nome e mat do item do array a partir de aluno
	itens[idx].nome_alu = aluno.nome_alu;
	itens[idx].mat_alu = aluno.mat_alu;
	}
}
template<>
void Arranjo<Aluno>::exibir() { //Member declaration not found - mesmo com esse problema o  projeto executa normalmente
// exibi cada aluno do array no formato "idx : mat = nome"
	cout<<"\nidx: Mat   =  nome:"<<endl;
	for(int i=0; i<10;i++){
		cout<<i<<" :  "<<itens[i].mat_alu<<"  = "<<itens[i].nome_alu<<endl;
	}
}
#endif // ALUNO_H_INCLUDED
