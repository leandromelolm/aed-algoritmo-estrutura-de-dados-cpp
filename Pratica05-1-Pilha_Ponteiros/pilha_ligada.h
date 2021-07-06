/*
 * pilha.h
 *
 *  Created on: 03 de jul. de 2021
 *      Author: lsm
 */
#ifndef PILHA_LIGADA_H_
#define PILHA_LIGADA_H_
#include <iostream>

using namespace std;

template <class T>
struct NoPilha {
    NoPilha *prox;
    T item;
};
template <class T>
class Pilha {
private:
    NoPilha<T> *topo_pilha;
    int tam_maximo;
    int tam_pilha;
public:
    Pilha(int capacidade) {
        tam_maximo = capacidade;
        tam_pilha = 0;
        topo_pilha = NULL;
    }
    ~Pilha() {
        for(int i = 0; i < tam_pilha; i++){
        desempilha();
        }
    }
    void empilha(T item) {
        NoPilha<T> *NovoNoPilha = new NoPilha<T>;
        cout<<tam_pilha<< " > " <<tam_maximo<<"\n";
       if(tam_pilha +1 >tam_maximo){
    	   throw"Pilha cheia";
       }else{
            NovoNoPilha->item = item;
            NovoNoPilha->prox = topo_pilha;
            topo_pilha = NovoNoPilha;
            tam_pilha++;
       }
    }
    T desempilha() {
    	if(topo_pilha == NULL){
        	throw"Pilha vazia";
        } else{
            T ItemPilha = topo_pilha->item;
            NoPilha<T> *auxNodePilha = topo_pilha;
            topo_pilha = topo_pilha->prox;
            delete auxNodePilha;
            tam_pilha--;
            return ItemPilha;
        }
    }
	int tamanho() {
		return tam_pilha;
	}
};
#endif // PILHA_LIGADA_H_




/*

template <class T>
class Pilha {
private:
	// Atributos para array de itens, capacidade e topo da pilha
public:
	Pilha(int capacidade) {
		// instancia array de itens, inicializa capacidade e topo
	}

	~Pilha() {
		// destroy array de itens
	}

	void empilha(T item) {
		// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
	}

	T desempilha() {
		// remove um item do topo da pilha; lança “Pilha vazia” se vazia
	}

	int tamanho() {
		// retorna o número de elementos na pilha.
	}
};

*/
