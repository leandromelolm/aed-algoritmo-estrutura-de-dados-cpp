#ifndef FILA_LIGADA_H_
#define FILA_LIGADA_H_
#include "fila.h"

using namespace std;

template<class T>
struct NoFila{
	NoFila *prox;
	T item;
};

template <class T>
class FilaLigada : public Fila<T> {

private:
	int tam_fila;
	NoFila<T> *fila_inicio;
	NoFila<T> *fila_final;
	int tam_maximo;

public:

	FilaLigada(int cap) : Fila<T>(cap) {
		tam_fila = 0;
		fila_inicio = NULL;
		fila_final = NULL;
		tam_maximo = cap;
		cout<<"Fila Ligada criada"<<"\n";
	}

	~FilaLigada() {
		for(int i =0; i<tam_fila; i++){
			desenfileira();
		}
	}

	void enfileira(const T &item) {
		if(cheia()){    //tam_fila+1 > tam_maximo
			throw "Fila cheia";
		}
		NoFila<T> *NovoNo = new NoFila<T>;
		NovoNo->item = item;
//		if(tam_fila == 0){   // Condição válida
//		if(tam_fila == NULL){   // Condição válida
		if(vazia()){
			fila_inicio = NovoNo;
		}else{
			fila_final->prox = NovoNo;
		}
		fila_final = NovoNo;
		tam_fila++;
	}

	T desenfileira() {
//		if(fila_inicio == NULL){ // condição válida (funciona igual ao if(vazia())
		if(vazia()){
			throw"Fila Vazia";
		}
		NoFila<T> *auxNo = fila_inicio;
		T auxItem = fila_inicio->item;
		fila_inicio = fila_inicio->prox;
		delete auxNo;
//		if (fila_inicio == NULL){   //tam_fila == 0
		if (vazia()){   //tam_fila == 0
			fila_final = NULL;
		}
		tam_fila--;
		return auxItem;
	}

	int cheia() {
//		if (tam_fila == tam_maximo)	return 1; return 0; //return 0 significa que a função definida pelo usuário está retornando false.
		return tam_fila == tam_maximo; //Simplificado - quando satisfazer a condição vai retorna 1 ( true)
	}

	int vazia() {
//		if (fila_inicio == NULL) return 1; return 0;
		return fila_inicio == NULL; // simplificado - quando satisfazer a condição vai retornar 1 (true)
	}

	int tamanho() {
		return tam_fila;
	}

};
#endif /* FILA_LIGADA_H_ */




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





 	/* Método "Enfileira" - outra forma de implementação */

//	void enfileira(const T &item) {
//		if(tam_fila < cap_maxima){
//			itens[(fila_final)] = item;
//			fila_final = (fila_final + 1) % cap_maxima;
//			tam_fila++;
//		}else{
//			throw "Fila cheia";
//		}
//	}



	/* Método "Enfileira" - PseudoCódigo  */

// * proc enfileira (dado v, fila F) {
//		if tamanho_fila < capacidade_maxima {
//			itens_fila [(fila_inicio + tamanho_fila) mod capacidade_maxima] <- v
//			tamanho_fila <- tamanho_fila + 1
//	}




	/* Outras implementação para função vazia() */
//	int vazia() {
//		if(tam_fila == 0){
//			return 1;
//		}return 0;
//	}

//	int vazia() {
//		if (fila_inicio == NULL) return 1;
//		else return 0;
//	}


	/* Outras implementação para função cheia()*/
//	int cheia() {
//		if(tam_fila == tam_maximo){
//			return 1;
//		}else{
//			return 0;
//		}
//	}

