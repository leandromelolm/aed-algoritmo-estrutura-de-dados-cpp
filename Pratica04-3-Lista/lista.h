/*
 * lista.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: melo
 */

#ifndef LISTA_H_
#define LISTA_H_

using namespace std;

template <class T>
class Lista {
private:
	T *itens;
	int cap_maxima;
	int tam_lista;
public:
	Lista(int capacidade) {
		this->cap_maxima = capacidade;
		this->itens = new T[this->cap_maxima];
		this->tam_lista = 0;
	}
	~Lista() {
		delete this->itens;
	}
	void adiciona (const T & item) {
		if(this->tam_lista< cap_maxima){
			this->itens[tam_lista] = item;
			tam_lista++;
		}else{
			throw"Lista cheia";
		}
	}
	T pega(int idx) {
		if(idx < 1 || idx - 1 > this->tam_lista){
			throw"Item inválido";
		}else{
//			cout<<idx<<": "<<itens[idx-1]<<endl;
			return this->itens[idx - 1];
		}
	}
	void insere(int idx, const T & item) {
		if (idx >= 1 && idx <= cap_maxima) {
			if (tam_lista + 1 <= cap_maxima) {
				for ( int i = tam_lista+1;  i >=idx ; i--) {
					itens[i] = itens[i-1];
				}
				itens[idx-1] = item;
				tam_lista++;
			} else {
				throw "Lista cheia";
			}
		} else {
			throw "Item inválido";
		}
	}
	void remove(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw "Item inválido";
		}else{
			for(int i = idx - 1; i < tam_lista; i++){
				this->itens[i] = this->itens[i + 1];
			}
			tam_lista--;
		}
	}
	void exibe() {
		for(int i = 0; i < this->tam_lista; i++){
			cout << this->itens[i] << " ";
		}
		cout << endl;
	}
	int tamanho() {
		return tam_lista;
	}
};
#endif /* LISTA_H_ */



/*

template <class T>
class Lista {
private:
	// itens da lista, capacidade e tamanho atual
public:
	Lista(int capacidade) {
		// inicilização do array, capacidade e tamanho
	}

	~Lista() {
		//destruição do array
	}

	void adiciona (const T & item) {
	// adiciona um item ao final da lista; lança “Lista cheia” caso cheia
	}

	T pega(int idx) {
		// pega um item pelo indice (começa em 1);
		// lança “Item inválido” se posição inválida
	}

	void insere (int idx, const T & item) {
		//insere um item na posição indicada (a partir de 1).
		//lança “Lista cheia” caso cheia
		//lança “Item inválido” se posição inválida
		//desloca itens existentes para a direita
	}

	void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
	}

	void exibe() {
		// exibe os itens da saida padrão separados por espaços
	}

	int tamanho() {
		// retorna a quantidade de itens atualmente na lista
	}
};

 * */







/*
// Alternativa ao metodo insere
void insere (int idx, const T & item) {
 insere um item na posicao indicada
 lanca "Lista cheia" caso cheia
 lanca "Item invalido" se posicao invalida
 desloca itens existentes para a direita
if(this->tamanho_atual >= this->tamanho_max - 1){
        cout << "Lista cheia" << endl;
	throw "Lista cheia";
}else if(idx < 1 || idx > this->tamanho_atual){
        cout << "I Item invalido" << endl;
	throw "Item invalido";
}else{
    for(int i = tamanho_atual; i >= (idx - 1); i--){
        this->itens[i] = this->itens[i - 1];
    }
    this->itens[idx - 1] = item;
    tamanho_atual++;
}
}
 */
