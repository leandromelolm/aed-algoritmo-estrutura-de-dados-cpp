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
struct nodePilha {
    nodePilha *prox;
    T item;
};
template <class T>
class Pilha {
private:
    nodePilha<T> *topo_pilha;
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
        nodePilha<T> *NovoNodePilha = new nodePilha<T>;
//        cout<<tam_pilha<< " > " <<tam_maximo<<endl;
       if(tam_pilha +1 >tam_maximo){
    	   throw"Pilha cheia";
       }else{
            NovoNodePilha->item = item;
            NovoNodePilha->prox = topo_pilha;
            topo_pilha = NovoNodePilha;
            tam_pilha++;
       }
    }
    T desempilha() {
    	if(tam_pilha <= 0){
        	throw"Pilha vazia";
        } else{
            T retunedItem = topo_pilha->item;
            nodePilha<T> *auxNodePilha = topo_pilha;
            topo_pilha = topo_pilha->prox;
            delete auxNodePilha;
            tam_pilha--;
            return retunedItem;
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




/*

//Pilha2.h - Testes OK

#ifndef PILHA_H_
#define PILHA_H_

#include <iostream>

using namespace std;

template<class T>

class Pilha {
private:
	T *itens;
	int cap_maxima;
	int topo;
	int tam_pilha;
public:
	Pilha(int capacidade) {
		this->cap_maxima= capacidade;
		itens=new T[capacidade];
		topo = 0;
		tam_pilha = 0;
	}
	~Pilha() {
		delete []this->itens;
	}
	void empilha(T item) {
		if(tam_pilha<cap_maxima){
			itens[topo]=item; //indexando item no array
			topo++;
			tam_pilha = tam_pilha + 1;
		}else{
			throw "Estouro de pilha";
		}
	}
	T desempilha() {
		if(tam_pilha>0){
			topo--;
			tam_pilha = tam_pilha - 1;
		}else{
			throw"Pilha vazia";
		}
		return itens[topo];
	}
	int tamanho() {
		return this->tam_pilha;
	}
};
#endif // PILHA_H_

*/




/*

//Pilha3.h - Testes OK

#ifndef PILHA_H_
#define PILHA_H_
#include <iostream>
using namespace std;

template<class T>
class Pilha {
private:
	int tam_maximo = 0;
	int topo_pilha = 0;
	T *items;
public:
	Pilha(int capacidade) {
		this->tam_maximo = capacidade;
		items = new T[this->tam_maximo];
		cout<<"Tamanho do array "<<tam_maximo<<endl<<endl;
	}
	~Pilha() {
		delete[] items;
	}
	void empilha(T item) {
		if(topo_pilha < tam_maximo) {
			items[this->topo_pilha] = item;
			this->topo_pilha = this->topo_pilha + 1;
		}else {
			throw"Estouro da pilha!( pilha cheia)";
		}

	}
	T desempilha() {

		T item_atual;
		if (topo_pilha > 0) {
			this->topo_pilha = this->topo_pilha - 1;
			item_atual = this->items[this->topo_pilha];
//			cout<<item_atual<<endl;
		} else {
			throw"Pilha vazia";
		}
		return items[topo_pilha];
	}
	int tamanho() {
		return this->topo_pilha;
	}
};
#endif // PILHA_H_

*/


/*

// Método enpilhar (outra forma)

 	void empilha(T item) {
		if(topo_pilha<cap_maxima){
			itens[topo_pilha++]=item;
		}else{
			throw "Estouro de pilha";
		}
	}


*/

