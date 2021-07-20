#include <iostream>

using namespace std;

class ListaOrdenada {
private:
	int * items;
	int tamanho, capacidade;
public:
	ListaOrdenada(int cap) {
		this->capacidade = cap;
		this->tamanho = 0;
		items = new int[cap];
	}

	~ListaOrdenada() {
		delete [] items;
	}

	void insere(int key) {
    	int i =tamanho;
		while(( i>0) &&  (key < items[i-1])) {
			items[i] = items[i-1];
			i--;
		}
		items[i] = key;
		tamanho++;
    }

	int buscaSequencial(int key) {
        for(int i=0; i < tamanho; i++) {
        	if (key < items[i])
        		return -1;
            if(key == items[i])
                return i;
        }
        return -1;
	}

	int buscaBinaria(int item) {
		return buscaBinaria(0, tamanho - 1, item);
	}

	int valida() {
		for (int i = 0; i < tamanho - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void exibe() {
		for (int i = 0; i < tamanho; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}

    void remove(int item){
        int idx = buscaBinaria(item);
        if(idx != -1){
            for(int i = idx; i < tamanho; i++){
                items[i] = items[i + 1];
            }
            tamanho--;
        }
	}

private:

	int buscaBinaria(int inicio, int final, int item) {
        if(inicio > final){
            return -1;
        }else{
            int meio = (inicio + final)/2;
            if(items[meio] == item){
                return meio;
            }else if(items[meio] > item){
                return buscaBinaria(inicio, meio -1, item);
            }else{
                return buscaBinaria(meio + 1, final, item);
            }
        }
    }

};

int main() {

	ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

	cout<<"Ordem de inserção: {10, 5, 25, 1, 5, 13, 50, 99, 33, 12} \n";

	for (int i = 0; i < 10; i++) {
		lista.insere(elementos[i]);
	}

	cout << "Lista válida: " << (lista.valida()?"sim":"não") << endl;
	lista.exibe();

	int teste [] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};

	for (int i = 0; i < 10; i++) {
		cout << "Buscando " << teste[i] << ": sequencial = " << lista.buscaSequencial(teste[i])
				<< " binaria = " << lista.buscaBinaria(teste[i]) << endl;

	}


    lista.remove(13);
	lista.remove(25);
	lista.remove(99);
	lista.remove(12);
	lista.remove(1);

	cout<<"---Lista pós remoção---\n ";
	cout << "Lista válida: " << (lista.valida()?"sim":"não") << endl;
	lista.exibe();

	for (int i = 0; i < 10; i++) {
		cout << "Buscando " << teste[i] << ": sequencial = " << lista.buscaSequencial(teste[i])
				<< " binaria = " << lista.buscaBinaria(teste[i]) << endl;

	}

} 











/*

// Com codigo para exibir saídas no console

	void insere(int key) {
    	int i =tamanho;
		while(( i>0) &&  (key < items[i-1])) {
			items[i] = items[i-1];
			i--;
		}
		items[i] = key;
		tamanho++;
//		cout<<"insere "<<items[i]<<"    ";
//		exibe();
    }

	int buscaSequencial(int key) {
        for(int i=0; i < tamanho; i++) {
//        	cout<<" ("<<key<<" = "<<items[i]<<") ";
        	if (key < items[i])
        		return -1;
            if(key == items[i])
                return i;
        }
        return -1;
	}

	int buscaBinaria(int item) {
		return buscaBinaria(0, tamanho - 1, item);
	}

	int valida() {
		for (int i = 0; i < tamanho - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void exibe() {
		for (int i = 0; i < tamanho; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}

    void remove(int item){
        int idx = buscaBinaria(item);
//        cout<<"índice "<<idx<<"  ";
//        cout<<"remove "<<item<<"  ";

        if(idx != -1){
            for(int i = idx; i < tamanho; i++){
                items[i] = items[i + 1];
            }
            tamanho--;
        }
//        exibe();
	}


*/

