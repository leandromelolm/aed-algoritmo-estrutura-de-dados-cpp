#ifndef LISTA_LIGADA_H_INCLUDED
#define LISTA_LIGADA_INCLUDED
#include <iostream>
using namespace std;

template <class T>
struct Node {
	Node *next; //Ponteiro para próximo elemento
	T item;
};

template <class T>
class Lista {
private:
	Node<T> *head;	//Ponteiro para início da lista
	Node<T> *tail; //Ponteiro para último elemento
	int tam_lista;
	int tam_maximo;
public:
	Lista(int capacidade) {

		tam_lista = 0;
		tam_maximo = capacidade;
		head = NULL;
		tail = NULL;
		cout<<"Lista Encadeada\n";
	}
	~Lista() {
		for(int i = 0; i < tam_lista; i++) {
			remove(1);
		}
	}
	void adiciona (const T & item) {
		Node<T> *newNo = new Node<T>;
		newNo->item = item;
		if(tam_lista >= tam_maximo){
			throw "Lista cheia";
		}
		if(head == NULL) {
			head = newNo;
			tail = newNo;
			tam_lista++;
			cout<<"add->"<<newNo->item<<"\n";
		} else {
			tail->next = newNo;
			tail = newNo;
			tam_lista++;
			cout<<"add->"<<newNo->item<<"\n";
		}
	}
	T pega(int idx) {
		if(idx < 1 || idx  > tam_lista) {
		} else {
			Node<T> *noAux = head;
			for(int i = 1; i < idx; i++) {
				noAux = noAux->next;
			}
			cout<<"pega->"<<noAux->item<<"\n";
			return noAux->item;
		}
	}
	void insere (int idx, const T & item) {
		Node<T> *newNo = new Node<T>;
		Node<T> *tmp = head;

		if (idx < 1 || idx > tam_maximo){ // Verifica se o índice é maior que o tamanho da lista
			// (idx < 1 || idx > tam_lista+1) Verifica se é um indice maior que a lista
			throw "Posição inválida";
		}
		if(tam_lista >= tam_maximo){
			throw "Lista cheia";
		}
		newNo->item = item;
		if(idx == 1) { //Primeiro elemento
			newNo->next = head;
			head = newNo;
			cout<<"insereInicio->"<<newNo->item<<"\n"; // "(*newNo).item" é igual a "newNo->item"
			tam_lista++;
		}
		else if(idx >= 1 && idx-1 <= tam_lista) {
			for(int i = 1; i < idx-1; i++) {
				tmp = tmp->next;
			}
			Node<T> *noAux = new Node<T>;
			noAux->item = item;
			noAux->next = tmp->next;
			tmp->next = noAux;
			tam_lista++;
			cout<<"insere(MEIO)-> "<<item<<" na posição "<<idx<<"\n"; // Insere entre a posição 2 e a penultima posição da lista
		}
	}
	void remove(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw "Item inválido";
		}else {
			Node<T> *temp = head;
			if(idx == 1) {
				temp = head;
				head = head->next;
				if(tail == temp) {
					tail = NULL;
				}
				cout<<"remove->"<<tam_lista<<"\n";
				tam_lista--;
			} else if(idx > 1 && idx <= tam_lista) {
				for(int i = 1; i < idx-1; i++) {
					temp = temp->next;
				}
				Node<T> *noAux = temp->next;
				temp->next = noAux->next;
				if(tail == noAux) {
					tail = temp;
				}
				delete noAux;
				cout<<"remove2->"<<tam_lista<<"\n";
				tam_lista--;
			}
		}
	}
	void exibe() {
		Node<T> *noAux = head;
		while(noAux != NULL ){
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


/*
void insere (int idx, const T & item) {
		nodeLista<T> *newNo = new nodeLista<T>;

		nodeLista<T> *noAnterior = inicialNo;

//		if (idx < 1 && idx > tam_maximo){
//			throw "Item inválido";
//		}
		if(tam_lista >= tam_maximo){
			throw "Lista cheia";
		}
//		noAnterior->item = item; // ERRO - altera no inicio
		newNo->item = item;


		if(idx == 1) { //Primeiro elemento
//			noAnterior->next = inicialNo;
//			noAnterior->next = inicialNo;
//			newNo->next = inicialNo;
			newNo->next = inicialNo;


			cout<<newNo<<" "<<inicialNo<<"\n";
//			inicialNo->next = inicialNo;
//			inicialNo->next = newNo->item;
//			newNo = inicialNo->next;
			inicialNo = newNo;


			cout<<"insereInicio->"<<newNo->item<<"\n";


			cout<<"insereInicio->"<<item<<"\n";

//			cout<<"insereInicio->"<<(*newNo).item<<"\n";  // "(*newNo).item" é igual a "newNo->item"


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

*/


