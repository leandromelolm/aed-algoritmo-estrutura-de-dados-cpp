#ifndef PILHA_H_
#define PILHA_H_
#include <iostream>

using namespace std;

template<class T>

class Pilha {
private:
	// propriedades para array de items, capacidade e topo da pilha
	int capacidade;
	int topo;
	T item;
	T *array;
public:
	Pilha(int capacidade) {
		// instancia array de items, inicializa capacidade e topo
		this->capacidade= capacidade;
		topo=0;
		array=new T[capacidade];
		//		cout<<"A pilha foi construída"<<endl;
	}
	~Pilha() {
		// destroy array de items
		delete []array;
	}
	void empilha(T item) {
		// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
		if(topo<capacidade){
			array[topo]=item;
			topo = topo+1;
		}else{throw "Estouro de pilha";}
	}
	T desempilha() {
		// remove um item do topo da pilha; lança “Pilha vazia” se vazia
		if(topo!=0){
			array[topo]={};
			topo--;}

		else {throw"Pilha vazia";};
		return array[topo];
	}
	int tamanho() {
		// retorna o número de elementos na pilha.
		return topo;
	}
};
#endif // PILHA_H_

