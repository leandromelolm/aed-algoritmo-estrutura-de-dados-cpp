#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

using namespace std;

template <class T>
class Lista {
private:
// itens da lista, capacidade e tamanho atual
T *itens;
int tamanho_max;
int tamanho_atual;
public:
Lista(int capacidade) {
// inicilizacao do array, capacidade e tamanho
    this->tamanho_max = capacidade + 1;
    this->itens = new T[this->tamanho_max];
    this->tamanho_atual = 0;//alterar para 1?
}
~Lista() {
//destruicao do array
    delete this->itens;
}
void adiciona (const T & item) {
// adiciona um item ao final da lista; lanca "Lista cheia" caso cheia
    try{
        this->itens[tamanho_atual] = item;
        tamanho_atual++;
    }catch(T e){
        cerr << "Erro:"<< e << endl;
    }
}
T pega(int idx) {
// pega um item pelo indice (comeca em 1);
// lanca "Item invalido" se posicao invalida
    if(idx < 1 || idx - 1 > this->tamanho_atual){
        cout << "P Item invalido" << endl;
    }else{
        return this->itens[idx - 1];
    }
}
void insere (int idx, const T & item) {
// insere um item na posicao indicada
// lanca "Lista cheia" caso cheia
// lanca "Item invalido" se posicao invalida
// desloca itens existentes para a direita
    if(this->tamanho_atual >= this->tamanho_max - 1){
        cout << "Lista cheia" << endl;
    }else if(idx < 1 || idx > this->tamanho_atual){
        cout << "I Item invalido" << endl;
    }else{
        for(int i = tamanho_atual; i >= (idx - 1); i--){
            this->itens[i] = this->itens[i - 1];
        }
        this->itens[idx - 1] = item;
        tamanho_atual++;
    }
}
void remove(int idx) {
// remove item de uma posicao indicada
// lanca "Item invalido" se posicao invalida
// desloca itens para a esquerda sobre o item removido
    if(idx < 1 || idx > tamanho_atual){
        cout << "R Item invalido" << endl;
    }else{
        for(int i = idx - 1; i < tamanho_atual; i++){
            this->itens[i] = this->itens[i + 1];
        }
        tamanho_atual--;
    }
}
void exibe() {
// exibe os itens da saida padrao separados por espacos
    for(int i = 0; i < this->tamanho_atual; i++){
        cout << this->itens[i] << " ";
    }
    cout << endl;
}
};


#endif // LISTA_H_INCLUDED
