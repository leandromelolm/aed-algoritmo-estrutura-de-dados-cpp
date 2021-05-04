#ifndef ARRANJO_H_INCLUDED
#define ARRANJO_H_INCLUDED
#include <iostream>

using namespace std;

template<class T>
class Arranjo {
private:
	int tamanho; // tamanho do arranjo
	T *itens; //items do arranjo
public:
	Arranjo(int tam) {
// instanciar o array de items com new (pratica 1) e seta tamanho;
		itens= new T[tam];
		this->tamanho=tam;
	}
	virtual ~Arranjo() {
// destruir o array de items (prática 1);
		delete[]itens;
		cout<<"Array de itens deletado"<<endl;
	}
	virtual T get(int idx) {
// retornar um item do array a partir do indice;
		return itens[idx];
	}
	virtual void set(int idx, const T &item) {
// set o item do array apontado pelo indice usando =
		itens[idx]=item;
	}
	virtual void exibir();
};
template<class T>
void Arranjo<T>::exibir() {
// exibir cada item numa linha da forma "<idx>: <item>"
	for(int i=0; i<tamanho; i++){
		cout<<"<"<<i<<">"<<": "<<"<"<<itens[i]<<">"<<endl;
	}
}

#endif // ARRANJO_H_INCLUDED
