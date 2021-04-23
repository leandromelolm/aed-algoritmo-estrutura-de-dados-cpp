#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

using namespace std;

template <class T>
class Fila {
private:
// array de itens, capacidade, tamanho, posicao inicial, etc.
T *itens;
int tam_maximo;
int tam_fila;
int posicao_inicial;
int posicao_final;

public:
Fila(int cap) {
// inicializar array de items, capacidade, tamanho, posicao inicial
    this->tam_maximo = cap;
    this->tam_fila = 0;
    this->posicao_final = 0;
    this->posicao_inicial = 0;
    this->itens = new T[this->tam_maximo];
}
~Fila() {
// destruir array de itens
    delete[] this->itens;
}
void enfileira(const T &item) {
// adiciona um item ao final da fila; lança "Fila cheia" caso cheia
    if(this->tam_fila < tam_maximo){
        this->itens[(this->posicao_final)] = item;
        this->posicao_final = (this->posicao_final + 1) % this->tam_maximo;
        this->tam_fila++;
    }else{
        cout << "Fila cheia" << endl;
    }
}
T desenfileira() {
// remove um item do inicio da fila; lança "Fila vazia" caso vazia
    T aux;
    if(this->tam_fila > 0){
        aux = this->itens[this->posicao_inicial];
        this->posicao_inicial = (this->posicao_inicial + 1) %this->tam_maximo;
        this->tam_fila--;
        return aux;
    }else{
        cout << "Fila vazia" << endl;
    }
}
int cheia() {
// retorna 1 se cheia, 0 caso contrário
    if(this->tam_fila == this->tam_maximo){
        return 1;
    }else{
        return 0;
    }
}
int vazia() {
// retorna 1 se vazia, 0 caso contrário
    if(this->tam_fila == 0){
        return 1;
    }else{
        return 0;
    }
}
int tamanho() {
//retorna a quantidade de itens atualmente na fila
    return this->tam_fila;
}
};


#endif // FILA_H_INCLUDED
