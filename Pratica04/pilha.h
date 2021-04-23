#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Pilha {
private:
    //propriedades para array de items, capacidade e topo da pilha
    int tam_maximo = 0;
    int topo_pilha = -1;
    T * items;
public:
    Pilha(int capacidade) {
        //instancia array de items, inicializa capacidade e topo
        this->tam_maximo = capacidade;
        items = new T[this->tam_maximo];
        //cout<<"Array de tamanho "<<tam_maximo<<" criado com sucesso!"<<endl<<endl;
    }
    ~Pilha() {
        //destroy array de items
        delete [] items;
        //cout<<"Array de tamanho "<<tam_maximo<<" destruido com sucesso!"<<endl<<endl;
    }
    void empilha(T item) {
        //empilha um item no topo da pilha; lança "Estouro da pilha" se cheia
        try{
            this->topo_pilha = this->topo_pilha+1;
            items[this->topo_pilha] = item;
        } catch(T e){
        cout<<"Erro: "<<e<<endl<<endl;
        }

    }
    T desempilha() {
        //remove um item do topo da pilha; lança "Filha vazia" se vazia
        T item_atual;
        if(this->topo_pilha >= 0) {
            item_atual = this->items[this->topo_pilha];
            topo_pilha--;
        } else {
            cout<<"Pilha vazia"<<endl<<endl;
        }
        return item_atual;
    }
};

#endif // PILHA_H_INCLUDED
