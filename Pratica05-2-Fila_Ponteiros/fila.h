#ifndef FILA_H_
#define FILA_H_
#include <iostream>
using namespace std;

template<class T>
class Fila {
	public:
		Fila(int cap){}
		virtual ~Fila(){};
		virtual void enfileira(const T &item)=0;
		virtual int desenfileira()=0;
		virtual int cheia()=0;
		virtual int vazia()=0;
		virtual int tamanho()=0;
};
#endif /* FILA_H_ */


/*
Parte 4: Refatoração e reorganização do código

Refatoração de código: FilaArray e FilaLigada são subclasses da Classe Fila(abstrata)
que define a interface dessas estruturas.
a classe Fila do arquivo fila.h é uma classe Abstrata.
Em fila.cpp há um ponteiro para lista genérica que pode ser instanciado
tanto com FilaArray ou FilaLigada
*/



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


