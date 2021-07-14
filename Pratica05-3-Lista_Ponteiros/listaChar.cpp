/*
 * lista.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>

#include "lista_ligada.h"
using namespace std;
//mainChar
int mainChar() {
	try{
		ListaLigada<char> listaChar(10);

		listaChar.adiciona('a');	// a
		listaChar.adiciona('b');	// a b
		listaChar.adiciona('c');	// a b c
		listaChar.adiciona('d');	// a b c d
		listaChar.adiciona('e');	// a b c d e
		listaChar.exibe(); 			// a b c d e (saída)

		listaChar.remove(3); 		// a b d e
		listaChar.exibe(); 			// a b d e (saída)

		listaChar.pega(4); 			// e
		listaChar.insere(2, 'f'); 	// a f b d e
		listaChar.exibe(); 			// a f b d e (saída)

		listaChar.adiciona('g'); 	// a f b d e g
		listaChar.insere(4, 'h'); 	// a f b h d e g
		listaChar.pega(2); 			// f
		listaChar.exibe(); 			// a f b h d e g (saída)

		listaChar.insere(2, 'Z');
		listaChar.exibe(); 			// a Z f b h d e g (saída)

		listaChar.insere(1, 'K');
		listaChar.exibe(); 			// K a Z f b h d e g (saída)

		listaChar.insere(1, 'Y');
		listaChar.exibe(); 			// Y K a Z f b h d e g (saída) 10 itens

//		listaChar.insere(1, 'P');
//		listaChar.exibe(); 			// P Y K a Z f b h d e g (saída) 11 itens
//
//		listaChar.insere(1, 'j');
//		listaChar.exibe(); 			// j P Y K a Z f b h d e g (saída) 12 itens
//
//		listaChar.insere(7, 'c');
//		listaChar.exibe(); 			// c j P Y K a Z f b h d e g (saída) 13 itens
//
//		listaChar.insere(17, 'E');  // Erro (Posição inválida
//		listaChar.exibe(); 			// E c j P Y K a Z f b h d e g (saída) 14 itens

		listaChar.tamanho();

		cout<<"Tamanho da listaChar: "<<listaChar.tamanho();
	}catch(const char *ex){
		cerr << "Erro (" << ex << ")" << endl;
	}
	return 0;
}


