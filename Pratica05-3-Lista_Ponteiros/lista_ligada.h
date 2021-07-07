/*
 * lista.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: lsm
 */
#ifndef LISTA_LIGADA_H_
#define LISTA_LIGADA_H_
using namespace std;

template <class T>
struct NoLista {
    NoLista *prox;
    T item;
};
template<class T>
class Lista {
private:
	int tam_lista;
	int tam_maximo;
    NoLista<T> *no_Inicio;
    NoLista<T> *no_Final;
//	T *itens;
public:
	Lista(int capacidade) {
		tam_lista = 0;
		no_Inicio = NULL;
		no_Final = NULL;
		tam_maximo = capacidade;
	}
	~Lista() {
        for(int i = 0; i < tam_lista; i++) {
            remove(1);
        }
	}
	void adiciona (const T & item) {
		NoLista<T> *NovoNo = new NoLista<T>;
//		NovoNo->item = item;
		if(tam_lista+1 > tam_maximo){
			throw"Lista Cheia";
		}
		NovoNo->item = item;
		if(tam_lista == 0){
			no_Inicio = NovoNo;
			no_Final = NovoNo;
		}else{
			no_Final->prox = NovoNo;
			no_Final = NovoNo;
		}
		tam_lista++;
	}
	T pega(int idx) {
//		NoLista<T> *auxNo = no_Inicio;
//		if(idx < 1 || idx  > tam_lista){
//			throw"Item inválido";
//		}else{
//
//				for(int i = 1; i < idx; i++){
//					auxNo = auxNo->prox;
//				}
//			return auxNo->item;
//		}


            NoLista<T> *auxNo = no_Inicio;
            for(int i = 1; i < idx; i++) {
                auxNo = auxNo->prox;
            }
//            cout<<auxNo->item<<"\n";
//            return auxNo->item;
         if(idx < 1 || idx  > tam_lista) {
        	throw"Item inválido";
        }return auxNo->item;

	}
	void insere(int idx, const T & item) {
		NoLista<T> *novoNo = no_Inicio;

			 if(idx == 1) {
			       novoNo->prox = no_Inicio;
			       no_Inicio = novoNo;

		}else if(idx >= 1 && idx < tam_lista){
			for(int i = 1; i < idx - 1; i++) {
			  novoNo = novoNo->prox;
			}
            NoLista<T> *auxNo = new NoLista<T>;
            auxNo->item = item;
            auxNo->prox = novoNo->prox;
            novoNo->prox = auxNo;
//            tam_lista++;
		}else if(tam_lista +1 > tam_maximo){
			throw "Lista cheia";
		} tam_lista++;
	}
	void remove(int idx) {
            NoLista<T> *noAnterior = no_Inicio;
            if(idx == 1) {
                noAnterior = no_Inicio;
                no_Inicio = no_Inicio->prox;
                if(no_Final == noAnterior) {
                	no_Final = NULL;
                }
                tam_lista--;
            } else if(idx > 1 && idx <= tam_lista) {
                for(int i = 1; i < idx - 1; i++) {
                    noAnterior = noAnterior->prox;
                }
                NoLista<T> *auxNo = noAnterior->prox;
                noAnterior->prox = auxNo->prox;
                if(no_Final == auxNo) {
                	no_Final = noAnterior;
                }
                delete auxNo;
                tam_lista--;
            }else {
            throw "Lista vazia";
        }
}


	void exibe() {
		 NoLista<T> *auxNo = no_Inicio;
		        for(int i = 0; i < tam_lista; i++) {
		            cout << auxNo->item << " ";
		            auxNo = auxNo->prox;
		        }
	}
	int tamanho() {
		return tam_lista;
	}
};
#endif /* LISTA_LIGADA_H_ */




/*
 *
 	ATENÇÃO: A lista deve ser indexada a partir de 1, e não de 0 como em arrays. Isto é,
	numa lista com capacidade 10, os índices dos elementos vão de 1 a 10. A
	implementação interna deve evitar desperdício de memória e acesso a áreas de
	memória não alocadas.
 *
 * */





/*

template <class T>
class Lista {
private:
	// itens da lista, capacidade e tamanho atual
public:
	Lista(int capacidade) {
		// inicilização do array, capacidade e tamanho
	}

	~Lista() {
		//destruição do array
	}

	void adiciona (const T & item) {
	// adiciona um item ao final da lista; lança “Lista cheia” caso cheia
	}

	T pega(int idx) {
		// pega um item pelo indice (começa em 1);
		// lança “Item inválido” se posição inválida
	}

	void insere (int idx, const T & item) {
		//insere um item na posição indicada (a partir de 1).
		//lança “Lista cheia” caso cheia
		//lança “Item inválido” se posição inválida
		//desloca itens existentes para a direita
	}

	void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
	}

	void exibe() {
		// exibe os itens da saida padrão separados por espaços
	}

	int tamanho() {
		// retorna a quantidade de itens atualmente na lista
	}
};

*/





/*

// Alternativa ao metodo insere
void insere (int idx, const T & item) {
 insere um item na posicao indicada
 lanca "Lista cheia" caso cheia
 lanca "Item invalido" se posicao invalida
 desloca itens existentes para a direita
if(this->tamanho_atual >= this->tamanho_max - 1){
        cout << "Lista cheia" << endl;
	throw "Lista cheia";
}else if(idx < 1 || idx > this->tamanho_atual){
        cout << "I Item invalido" << endl;
	throw "Item invalido";
}else{
    for(int i = tamanho_atual; i >= (idx - 1); i--){
        this->itens[i] = this->itens[i - 1];
    }
    this->itens[idx - 1] = item;
    tamanho_atual++;
}
}

*/


/*

lista2.h Testes OK

#ifndef LISTA_H_
#define LISTA_H_

using namespace std;

template<class T>

class Lista {
private:
	int tam_lista;
	int cap_maxima;
	T *itens;
public:
	Lista(int capacidade) {
		tam_lista = 0;
		cap_maxima = capacidade;
		itens = new T[cap_maxima + 1];
	}
	~Lista() {
		delete []itens;
	}
	void adiciona (const T & item) {
		if(tam_lista< cap_maxima){
			itens[tam_lista] = item;
			tam_lista++;
		}else{
			throw"Lista cheia";
		}
	}
	T pega(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw"Item inválido";
		}else{
//			cout<<idx<<": "<<itens[idx-1]<<endl;
			return itens[idx-1];
		}
	}
	void insere(int idx, const T & item) {
		if (idx >= 1 && idx <= cap_maxima) {
			if (tam_lista + 1 <= cap_maxima) {
				for ( int i = tam_lista + 1;  i >=idx ; i--) {
					itens[i] = itens[i-1];
				}
				itens[idx-1] = item;
				tam_lista++;
			} else {
				throw "Lista cheia";
			}
		} else {
			throw "Item inválido";
		}
	}
	void remove(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw "Item inválido";
		}else{
			for(int i = idx - 1; i < tam_lista; i++){
				itens[i] = itens[i + 1];
			}
			tam_lista--;
		}
	}
	void exibe() {
		for(int i = 0; i < tam_lista; i++){
			cout << itens[i] << " ";
		}
		cout << endl;
	}
	int tamanho() {
		return tam_lista;
	}
};

#endif // LISTA_H_


*/



