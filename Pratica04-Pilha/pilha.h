/*
 * pilha.h
 *
 *  Created on: 27 de ago de 2019
 *      Author: ALUNO
 */

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
//		cout<<"A pilha foi destruída"<<endl;
		delete []array;
	}

	void empilha(T item) {
		// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
		if(topo<capacidade){
//			cout<<topo<<endl;
			array[topo]=item;
			topo = topo+1;
//		} else {cout <<"Estouro de pilha"<<endl;}
		} else {throw "Estouro de pilha";}
	}

	T desempilha() {
		// remove um item do topo da pilha; lança “Pilha vazia” se vazia

		if(topo!=0){
		array[topo]={};
		topo--;}
//		else {cout<<"Pilha vazia"<<endl;};
		else {throw"Pilha vazia";};
		return array[topo];
	}
	int tamanho() {
	// retorna o número de elementos na pilha.
	//	T item_atual;
//		cout<<topo<<endl;
		return topo;
	}



};
#endif // PILHA_H_







/*
 * pilha.h
 *
 *  Created on: 20 de jun. de 2021
 *      Author: melo
 */




/*

#ifndef PILHA_H_
#define PILHA_H_
#include <iostream>
using namespace std;

template <class T>
class Pilha {
private:
// Atributos para array de items, capacidade e topo da pilha
	int p_max = 0;
	int topo_pilha = -1;
	T *items;
public:
Pilha(int capacidade) {
// instancia array de items, inicializa capacidade e topo
	this->p_max = capacidade;
	items = new T[this->p_max];
}
~Pilha() {
// destroy array de items
	delete[] items;
}
void empilha(T item) {
// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia

		if(this->topo_pilha < this->p_max){
			this->topo_pilha = this->topo_pilha + 1;
			items[this->topo_pilha] = item;
		}else {
			cout << "Estouro da pilha " << endl;
		}


//	try {
//		this->topo_pilha = this->topo_pilha + 1;
//		items[this->topo_pilha] = item;
//	} catch (T e) {
//		cout << "Erro: " << e << endl;
//	}
}
T desempilha() {
// remove um item do topo da pilha; lança “Pilha vazia” se vazia
	T item_atual;
	if (this->topo_pilha >= 0) {
		item_atual = this->items[this->topo_pilha];
		topo_pilha--;
	} else {
		cout << "Pilha vazia" << endl;
	}
	return item_atual;
}
int tamanho() {
// retorna o número de elementos na pilha.
//	T item_atual;
	return this->topo_pilha+1;
}
};


#endif // PILHA_H_

 */

