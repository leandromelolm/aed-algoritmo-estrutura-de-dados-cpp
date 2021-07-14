/*
 * lista.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: lsm
 */
#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>

using namespace std;

template<class T>
class Lista {
	int tam_lista=0;
	public:
		Lista(int capacidade){}
		virtual ~Lista(){}
		virtual void adiciona (const int & item);
//		virtual int pega(int idx)=0;
		virtual T pega(int idx)=0;
//		virtual void insere(int idx, const int & item)=0;
		virtual void insere(int idx, const T & item)=0;
		virtual void remove(int idx)=0;;
		virtual void exibe()=0;;
//		virtual int tamanho()=0;
		int tamanho(){
			return tam_lista;
		};
};
#endif // LISTA_H_



/*

Parte 4: Refatore e reorganize o código
Passo 1: Refatore o código de forma que as duas implementações (com Array e Ponteiros) da
classe Pilha sejam subclasses de uma classe abstrata Pilha, que define a interface dessas
estruturas.
Crie a classe abstrata num arquivo pilha.h, e inclua em pilha_array.h e pilha_ligada.h.
Renomeie as classes para PilhaArray e PilhaLigada e faça com que elas derivem de
Pilha.
Passo 2: Adeque o código de pilha.cpp e polonesa.cpp de forma que haja um ponteiro para
Pilha genérica que pode ser instanciado tanto com PilhaArray ou PilhaLigada.
Passo 3: Repita os passos acima para as estruturas Fila e Lista e seus respectivos arquivos .h e
.cpp.


*/


/*
template<class T>
class Lista {
	public:
		Lista(int capacidade){}
		virtual ~Lista(){}
		virtual void adiciona (const T & item);
		virtual T pega(int idx);
		virtual void insere(int idx, const T & item);
		virtual void remove(int idx);
		virtual void exibe();
		virtual int tamanho();
};
*/
