/*
 * fila.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: lsm
 */
#ifndef FILA_H_
#define FILA_H_

using namespace std;

template<class T>

class Fila {
private:
	int tam_fila;
	int fila_inicio;
	int fila_final;
	int cap_maxima;
	T *itens;
public:
	Fila(int cap) {
		tam_fila = 0;
		fila_inicio = 0;
		fila_final = 0;
		cap_maxima = cap;
		itens = new T[cap_maxima];
	}
	~Fila() {
		delete[]itens;
	}
	void enfileira(const T &item) {
		if(tam_fila < cap_maxima){
			itens[(fila_inicio + tam_fila) % cap_maxima] = item;
			tam_fila++;
		}else{
			throw "Fila cheia";
		}
	}
	T desenfileira() {
		T aux;
		if(tam_fila > 0){
			aux = itens[fila_inicio];
			fila_inicio = (fila_inicio + 1) % cap_maxima;
			tam_fila--;
			return aux;
		}else{
			throw"Fila vazia";
		}
	}
	int cheia() {
		if(tam_fila == cap_maxima){
			return 1;
		}else{
			return 0;
		}
	}
	int vazia() {
		if(tam_fila == 0){
			return 1;
		}else{
			return 0;
		}
	}
	int tamanho() {
		return tam_fila;
	}
};


#endif /* FILA_H_ */


/*

template <class T>
class Fila {
private:
// array de itens, capacidade, tamanho, posição inicial, etc.
public:
Fila(int cap) {
// inicializar array de items, capacidade, tamanho, posição inicial
}
~Fila() {
// destruir array de itens
}
void enfileira(const T & item) {
// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
}
T desenfileira() {
// remove um item do inicio da fila; lança “Fila vazia” caso vazia
}
int cheia() {
// retorna 1 se cheia, 0 caso contrário
}
int vazia() {
// retorna 1 se vazia, 0 caso contrário
}
int tamanho() {
// retorna a quantidade de itens atualmente na fila
}
};

*/





/*

 	// Método "Enfileira" - outra forma de implementação

	void enfileira(const T &item) {
		if(tam_fila < cap_maxima){
			itens[(fila_final)] = item;
			fila_final = (fila_final + 1) % cap_maxima;
			tam_fila++;
		}else{
			throw "Fila cheia";
		}
	}

*/


/*

 // Método "Enfileira" - PseudoCódigo

 * proc enfileira (dado v, fila F) {
		if tamanho_fila < capacidade_maxima {
			itens_fila [(fila_inicio + tamanho_fila) mod capacidade_maxima] <- v
			tamanho_fila <- tamanho_fila + 1
	}

 */


