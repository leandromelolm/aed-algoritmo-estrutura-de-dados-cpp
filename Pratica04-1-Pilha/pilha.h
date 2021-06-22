#ifndef PILHA_H_
#define PILHA_H_

#include <iostream>

using namespace std;

template <class T>
class Pilha {
	private:
	T* pilha;       //propriedades para array  de itens
	int capacidade; //propriedades capacidade e topo da pilha
	int altura;     //propriedades topo da pilha
public:
	Pilha(int capacidade){
		altura = 0; //inicializa topo
		this->capacidade=capacidade; //inicializa capacidade
		pilha = new T[capacidade]; //instancia um array de itens,
	}
	~Pilha(){
		delete []pilha; //destroi
	}
	void empilha(T item){
		if(altura<capacidade){
			pilha[altura] = item; //empilha um item no topo da pilha;
//			cout<<pilha[altura]<<": "<<item<<endl;
			altura++;
		}
		else{
			throw "Estouro de pilha"; //lança "estouro da pilha" se cheia
		}
	}
	T desempilha(){
		if(altura> 0){
//			cout<<pilha[altura]<<endl;
			return pilha[--altura]; //remove um item do topo da pilha;

		}else{
			throw "Pilha vazia";     //lança "pilha vazia" se vazia
		}
	}
	int tamanho() {
		cout<<altura<<endl;
		return this->altura;
	}
};

#endif // PILHA_H_




/*

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
//			cout<<itens[topo]<<": "<<item<<endl;
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
template <class T>
class Pilha {
private:
	// Atributos para array de items, capacidade e topo da pilha
public:
	Pilha(int capacidade) {
		// instancia array de items, inicializa capacidade e topo
	}

	~Pilha() {
		// destroy array de items
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
