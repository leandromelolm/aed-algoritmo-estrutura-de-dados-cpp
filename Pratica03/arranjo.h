#ifndef ARRANJO_H_INCLUDED
#define ARRANJO_H_INCLUDED
#include <iostream>

using namespace std;

template<class T>
class Arranjo {
	private:
		int tamanho; // tamanho do arranjo
		T *itens; //itens do arranjo
	public:
		Arranjo(int tam) {
			// instancia o array de itens com new (pratica 1) e seta tamanho;
			itens= new T[tam];
			this->tamanho=tam;
		}
		virtual ~Arranjo() {
			// destroi o array de itens (prática 1);
			delete[]itens;
			cout<<"Array de itens deletado"<<endl;
		}
		virtual T get(int idx) {
			// retorna um item do array a partir do indice;
			return itens[idx];
		}
		virtual void set(int idx, const T &item) {
			// seta o item do array apontado pelo indice usando =
			if(idx>=tamanho){
			throw "não é possível atribuir valor para uma posição do array";
			}else{
			itens[idx]=item;
			}
		}
	virtual void exibir();
};

template<class T>
void Arranjo<T>::exibir() {
	// exibi cada item numa linha da forma "<idx>: <item>"
	for(int i=0; i<tamanho; i++){
		cout<<"<"<<i<<">"<<": "<<"<"<<itens[i]<<">"<<endl;
	}
}

#endif // ARRANJO_H_INCLUDED
