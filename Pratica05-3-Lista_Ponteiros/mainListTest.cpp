/*
 * lista.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>

#include "lista_ligada.h"
#include "lista_array.h"
#include "lista.h"

#define MAX 100

void testaTamanho2(Lista<int> & lista, const char * subcaso, int tamanho) {
	cerr << "Testando tamanho() [" << subcaso << "]: " ;
	if (lista.tamanho() != tamanho) {
		cerr << "FALHOU (tam = " << lista.tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;
}

int mainPratica05LinkedListTest(){
//int main() {

//	Lista<int> lista(MAX); //linha original

//	Lista<int>*lista = new ListaLigada<int>(MAX);
//	Lista<int>*lista = new ListaArray<int>(MAX);

	Lista<int> *lista;

//	lista = new ListaArray<int>(MAX);
	lista = new ListaLigada<int>(MAX);

	try {
		cerr << "Testando adiciona() [normal]: ";
		for (int i = 1; i <= MAX; i++) {
//			lista.adiciona(i); //linha original
			lista->adiciona(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}
//	testaTamanho(lista, "cheia", MAX); //linha original
	testaTamanho2(*lista, "cheia", MAX);

	try {
		cerr << "Testando adiciona() [overflow]: ";
		lista->adiciona(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char *ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	cerr << "Testando pega() [todos]: ";
	for (int i = MAX; i >= 1; i--) {
		if (lista->pega(i) != i) {
			cerr << "FALHOU em " << i << endl;
			lista->exibe();
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando remove() [pares]: "; // remove elementos pares de tr�s pra frente
	try {
		for (int i = MAX/2; i >= 1; i--) {
			lista->remove(2 * i);
		}
	} catch (const char * ex) {
		cerr << "FALHOU (" << ex << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	testaTamanho2(*lista, "metade", MAX/2);

	cerr << "Testando pega() [impares]: ";
	for (int i = 1; i <= MAX/2; i++) {
		try {
			if (lista->pega(i) != ((i - 1)* 2) + 1) {
				cerr << "FALHOU em " << i << endl;
				lista->exibe();
				exit(1);
			}
		} catch (...) {
			cerr << "FALHOU em " << i << "(exce��o)" << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando insere() [pares]: ";
	for (int i = MAX/2; i >= 1; i--) {
		try {
			lista->insere(i + 1, 2 * i);
		} catch (...) {
			cerr << "FALHOU em " << i << " (exce��o)" << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	testaTamanho2(*lista, "cheia", MAX);

	cerr << "Testando pega() [todos, 2o round]: ";
	for (int i = MAX; i >= 1; i--) {
		try {
			if (lista->pega(i) != i) {
				cerr << "FALHOU em " << i << " (valor = " << lista->pega(i) << ")" << endl;
				lista->exibe();
				exit(1);
			}
		} catch (...) {
			cerr << "FALHOU em " << i << " (exce��o)" << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando remove() [tudo]: ";
	try {
		for (int i = 1; i <= MAX; i++) {
			lista->remove(1);
		}
	} catch (const char * ex) {
		cerr << "FALHOU (" << ex << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	testaTamanho2(*lista, "vazia", 0);

	try {
		cerr << "Testando remove() [underflow]: ";
		lista->remove(1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char *ex) {
		cerr << "OK (" << ex << ")" << endl;
	}


//		Código para atrasar a execução do trecho "Teste Lista Char"
		time_t start_t, end_t;
		double diff_t;
//		  cout<<"Inicio\n";
		time(&start_t);
		while(diff_t<=2.000000){
			time(&end_t);
			diff_t = difftime(end_t, start_t);
		}

	try{
		cout<<"\nTeste Lista Char"<<endl<<endl;

		//		ListaLigada<char> listaChar(10);

		Lista<char> *listaChar;
		listaChar = new ListaLigada<char>(10);
//		listaChar = new ListaArray<char>(10);


		listaChar->adiciona('a');	// a
		listaChar->adiciona('b');	// a b
		listaChar->adiciona('c');	// a b c
		listaChar->adiciona('d');	// a b c d
		listaChar->adiciona('e');	// a b c d e
		listaChar->exibe(); 			// a b c d e (saída)

		listaChar->remove(3); 		// a b d e
		listaChar->exibe(); 			// a b d e (saída)

		listaChar->pega(4); 			// e
		listaChar->insere(2, 'f'); 	// a f b d e
		listaChar->exibe(); 			// a f b d e (saída)

		listaChar->adiciona('g'); 	// a f b d e g
		listaChar->insere(4, 'h'); 	// a f b h d e g
		listaChar->pega(2); 			// f
		listaChar->exibe(); 			// a f b h d e g (saída)

		listaChar->insere(2, 'Z');
		listaChar->exibe(); 			// a Z f b h d e g (saída)

		listaChar->insere(1, 'K');
		listaChar->exibe(); 			// K a Z f b h d e g (saída)

		listaChar->insere(1, 'Y');
		listaChar->exibe(); 			// Y K a Z f b h d e g (saída) 10 itens

//		listaChar->insere(1, 'P');
//		listaChar->exibe(); 			// P Y K a Z f b h d e g (saída) 11 itens
//
//		listaChar->insere(1, 'j');
//		listaChar->exibe(); 			// j P Y K a Z f b h d e g (saída) 12 itens
//
//		listaChar->insere(7, 'c');
//		listaChar->exibe(); 			// c j P Y K a Z f b h d e g (saída) 13 itens
//
//		listaChar->insere(17, 'E');  // Erro (Posição inválida
		listaChar->exibe(); 			// E c j P Y K a Z f b h d e g (saída) 14 itens

		listaChar->tamanho();

		cout<<"Tamanho da listaChar: "<<listaChar->tamanho();
	}catch(const char *ex){
		cerr << "Erro (" << ex << ")" << endl;
	}
	return 0;
}

