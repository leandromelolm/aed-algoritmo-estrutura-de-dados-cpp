/*
 * lista.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: melo
 */

#ifndef FILA_H_
#define FILA_H_

#include <iostream>

using namespace std;

template <class T>

class Fila {
private:
// array de itens, capacidade, tamanho, posicao inicial, etc.
	T *itens;
	int cap_maxima;
	int tam_fila;
	int pos_inicial;
	int pos_final;

public:
	Fila(int cap) {
		// inicializar array de items, capacidade, tamanho, posicao inicial
		this->cap_maxima = cap;
		this->tam_fila = 0;
		this->pos_final = 0;
		this->pos_inicial = 0;
		this->itens = new T[this->cap_maxima];
	}
	~Fila() {
		// destruir array de itens
		delete[]this->itens;
	}
	void enfileira(const T &item) {
		// adiciona um item ao final da fila; lança "Fila cheia" caso cheia
		if(this->tam_fila < cap_maxima){
			this->itens[(this->pos_final)] = item;
			this->pos_final = (this->pos_final + 1) % this->cap_maxima;
			this->tam_fila++;
		}else{
			throw "Fila cheia";
		}
	}
	T desenfileira() {
		// remove um item do inicio da fila; lança "Fila vazia" caso vazia
		T aux;
		if(this->tam_fila > 0){
			aux = this->itens[this->pos_inicial];
			this->pos_inicial = (this->pos_inicial + 1) % this->cap_maxima;
			this->tam_fila--;
			return aux;
		}else{
			throw"Fila vazia";
		}
	}
	int cheia() {
		// retorna 1 se cheia, 0 caso contrário
		if(this->tam_fila == this->cap_maxima){
			return 1;
		}else{
			return 0;
		}
	}
	int vazia() {
		// retorna 1 se vazia, 0 caso contrário
		if(this->tam_fila == 0){
			return 1;
		}else{
			return 0;
		}
	}
	int tamanho() {
		//retorna a quantidade de itens atualmente na fila
		return this->tam_fila;
	}
};


#endif /* FILA_H_ */
