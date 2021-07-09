#ifndef LISTA_LIGADA_H_INCLUDED
#define LISTA_LIGADA_INCLUDED
#include <iostream>
using namespace std;

template <class T>
struct nodeLista {
	nodeLista *next;
	T item;
};

template <class T>
class Lista {
private:
	nodeLista<T> *inicialNo;
	nodeLista<T> *finalNo;
	int tam_lista;
	int tam_maximo;
public:
	Lista(int capacidade) {

		tam_lista = 0;
		tam_maximo = capacidade;
		inicialNo = NULL;
		finalNo = NULL;
		cout<<"Lista Encadeada\n";
	}
	~Lista() {
		for(int i = 0; i < tam_lista; i++) {
			remove(1);
		}
	}
	void adiciona (const T & item) {
		nodeLista<T> *newNo = new nodeLista<T>;
		newNo->item = item;
		if(tam_lista >= tam_maximo){
			throw "Lista cheia";
		}
		if(inicialNo == NULL) {
			inicialNo = newNo;
			finalNo = newNo;
			tam_lista++;
//			cout<<"add->"<<newNo->item<<"\n";
		} else {
			finalNo->next = newNo;
			finalNo = newNo;
			tam_lista++;
//			cout<<"add->"<<newNo->item<<"\n";
		}
	}
	T pega(int idx) {
		if(idx < 1 || idx  > tam_lista) {
		} else {
			nodeLista<T> *noAux = inicialNo;
			for(int i = 1; i < idx; i++) {
				noAux = noAux->next;
			}
//			cout<<"pega->"<<noAux->item<<"\n";
			return noAux->item;
		}
	}
	void insere (int idx, const T & item) {
		nodeLista<T> *noAnterior = inicialNo;
		if (idx < 1 && idx > tam_maximo){
			throw "Item inválido";
		}
		if(tam_lista >= tam_maximo){
			throw "Lista cheia";
		}
//		noAnterior->item = item;
		if(idx == 1) {
			noAnterior->next = inicialNo;
			inicialNo->next = inicialNo;
//			cout<<"insereInicio->"<<item<<"\n";
		} else if(idx >= 1 && idx-1 <= tam_lista) {
			for(int i = 1; i < idx-1; i++) {
				noAnterior = noAnterior->next;
			}
			nodeLista<T> *noAux = new nodeLista<T>;
			noAux->item = item;
			noAux->next = noAnterior->next;
			noAnterior->next = noAux;
			tam_lista++;
//			cout<<"insere->"<<item<<"\n";
		}
	}
	void remove(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw "Item inválido";
		}else {
			nodeLista<T> *noAnterior = inicialNo;
			if(idx == 1) {
				noAnterior = inicialNo;
				inicialNo = inicialNo->next;
				if(finalNo == noAnterior) {
					finalNo = NULL;
				}
				tam_lista--;
			} else if(idx > 1 && idx <= tam_lista) {
				for(int i = 1; i < idx-1; i++) {
					noAnterior = noAnterior->next;
				}
				nodeLista<T> *noAux = noAnterior->next;
				noAnterior->next = noAux->next;
				if(finalNo == noAux) {
					finalNo = noAnterior;
				}
				delete noAux;
				tam_lista--;
			}
		}
	}
	void exibe() {
		nodeLista<T> *noAux = inicialNo;
		for(int i = 0; i < tam_lista; i++) {
			cout << noAux->item << " ";
			noAux = noAux->next;
		}
		cout << endl;
	}
	int tamanho() {
		return tam_lista;
	}
};

#endif // LISTA_LIGADA_H_INCLUDED
