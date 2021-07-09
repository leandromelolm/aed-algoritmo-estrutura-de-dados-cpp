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


