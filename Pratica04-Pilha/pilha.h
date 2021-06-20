/*
 * pilha.h
 *
 *  Created on: 20 de jun de 2021
 *
 */

#ifndef PILHA_H_
#define PILHA_H_
#include <iostream>
using namespace std;

template <class T>
class Pilha {
private:
// Atributos para array de items, capacidade e topo da pilha
	int tam_maximo = 0;
	int topo_pilha = -1;
	T *items;
public:
Pilha(int capacidade) {
// instancia array de items, inicializa capacidade e topo
	this->tam_maximo = capacidade;
	items = new T[this->tam_maximo];
}
~Pilha() {
// destroy array de items
	delete[] items;
}
void empilha(T item) {
// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
	try {
		this->topo_pilha = this->topo_pilha + 1;
		items[this->topo_pilha] = item;
	} catch (T e) {
		cout << "Erro: " << e << endl;
	}
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
//	return sizeof items;
}
};




#endif /* PILHA_H_ */
