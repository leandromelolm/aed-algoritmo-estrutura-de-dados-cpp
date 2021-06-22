#ifndef PILHA_H_
#define PILHA_H_

#include <iostream>

using namespace std;

template<class T>

class Pilha {
private:
	// propriedades para array de items, capacidade e topo da pilha
	T item;
	T *array;
	int cap_maxima;
	int topo;
	int tam_pilha;

public:
	Pilha(int capacidade) {
		// instancia array de items, inicializa capacidade e topo
		this->cap_maxima= capacidade;
		array=new T[capacidade];
		topo = 0;
		tam_pilha = 0;
	}
	~Pilha() {
		// destroy array de items
		delete []this->array;
	}
	void empilha(T item) {
		// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
		if(tam_pilha<cap_maxima){
			array[topo]=item; //idexando item no array
//			cout<<array[topo]<<": "<<item<<endl;
			topo++;
			tam_pilha = tam_pilha + 1;
		}else{throw "Estouro de pilha";}
	}
	T desempilha() {
		// remove um item do topo da pilha; lança “Pilha vazia” se vazia
		if(tam_pilha>0){
			topo--;
			tam_pilha = tam_pilha - 1;
		}else {throw"Pilha vazia";};
		return array[topo];
	}
	int tamanho() {
		// retorna o número de elementos na pilha.
		return this->tam_pilha;
	}
};
#endif // PILHA_H_

