#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <iostream>
using namespace std;


template <class T>
class Pilha {
	public:
		Pilha(int capacidade){}
		virtual ~Pilha(){};
		virtual void empilha(T item)=0;
		virtual T desempilha()=0;
		virtual int tamanho()=0;
};
#endif // PILHA_H_INCLUDED

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

refatoração de código: pilha_arrray e Pilha_ligada para ser subclasses de pilha(abstrata). Em pilha.cpp há um ponteiro para
Pilha genérica que pode ser instanciado tanto com PilhaArray ou PilhaLigada


*/
