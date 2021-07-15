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
		virtual void adiciona (const T & item)=0;
		virtual T pega(int idx)=0;
		virtual void insere(int idx, const T & item)=0;
		virtual void remove(int idx)=0;
		virtual void exibe()=0;
		virtual int tamanho()=0;
};
#endif // LISTA_H_



/*

Parte 4: Refatoração e reorganização do código

Refatoração de código: ListaArray e ListaLigada são subclasses da Classe Lista(abstrata)
que define a interface dessas estruturas.
a classe Lista do arquivo lista.h é uma classe Abstrata.
Em lista.cpp há um ponteiro para lista genérica que pode ser instanciado
tanto com ListaArray ou ListaLigada

*/
