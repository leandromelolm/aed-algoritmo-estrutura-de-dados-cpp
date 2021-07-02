/*
 * lista.h
 *
 *  Created on: 21 de jun. de 2021
 *      Author: lsm
 */
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
		itens = new T[cap_maxima+1];
	}
	~Lista() {
		delete []itens;
	}
	void adiciona (const T & item) {
		if(tam_lista >= cap_maxima){
			throw"Lista cheia";
		}else{
			itens[tam_lista+1] = item;
			tam_lista++;
		}
	}
	T pega(int idx) {
		if(idx < 1 || idx  > tam_lista){
			throw"Item inválido";
		}else{
			return itens[idx];
		}
	}
	void insere(int idx, const T & item) {
		if(idx < 1 && idx > cap_maxima) {
			throw "Item inválido";
		}
		if(tam_lista >= cap_maxima){
			throw "Lista cheia";
		}else{
			for( int i = tam_lista+1;  i >= idx; i--) {
				itens[i] = itens[i-1];
			}
			itens[idx] = item;
			tam_lista++;
		}
	}
	void remove(int idx) {
		if(idx < 1 || idx > tam_lista){
			throw "Item inválido";
		}else{
			for(int i = idx; i < tam_lista; i++){
				itens[i] = itens[i+1];
			}
			tam_lista--;
		}
	}
	void exibe() {
		for(int i = 1; i <= tam_lista; i++){
			cout << itens[i] << " ";
		}
		cout << endl;
	}
	int tamanho() {
		return tam_lista;
	}
};
#endif /* LISTA_H_ */




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



