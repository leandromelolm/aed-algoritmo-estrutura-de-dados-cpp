#ifndef PILHA_LIGADA_H_
#define PILHA_LIGADA_H_
#include <iostream>
#include "pilha.h"

using namespace std;

template <class T>
struct NoPilha {
    NoPilha *prox;
    T item;
};
template <class T>
class PilhaLigada : public Pilha<T>{
private:
    NoPilha<T> *topo_pilha;
    int tam_maximo;
    int tam_pilha;
public:
    PilhaLigada(int capacidade):Pilha<T>(capacidade) {
        tam_maximo = capacidade;
        tam_pilha = 0;
        topo_pilha = NULL;
		cout<<"Pilha Encadeada criada\n";
    }
    ~PilhaLigada() {
        for(int i = 0; i < tam_pilha; i++){
        desempilha();
        }
    }
    void empilha(T item) {
       if(tam_pilha +1 >tam_maximo){
    	   throw"Pilha cheia";
       }else{
    	   NoPilha<T> *NovoNo = new NoPilha<T>;
            NovoNo->item = item;
            NovoNo->prox = topo_pilha;
            topo_pilha = NovoNo;
            tam_pilha++;
       }
    }
    T desempilha() {
    	if(topo_pilha == NULL){
        	throw"Pilha vazia";
        } else{
            T ItemPilha = topo_pilha->item;
            NoPilha<T> *auxNo = topo_pilha;
            topo_pilha = topo_pilha->prox;
            delete auxNo;
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

