#include <iostream>
#include "pilha_ligada.h"
#include "pilha_array.h"
#include "pilha.h"

using namespace std;

int ehOperadorTest(char token) {
	switch(token) {
	case '+':
	case '-':
	case '*':
	case '/': return 1;
	default: return 0;
	}
}

int avaliaTest(char token, int valorEsq, int valorDir) {
	switch(token) {
	case '+': return valorEsq + valorDir;
	case '-': return valorEsq - valorDir;
	case '*': return valorEsq * valorDir;
	case '/': return valorEsq / valorDir;
	default: return 0;
	}
}

int polonesaTest(const char * exp) {
//	Pilha<int> pilha(10);
	Pilha<int> *pilhaPolonesa;
	pilhaPolonesa = new PilhaArray<int>(10);

	while (*exp) {
		char token = *exp;
		if (ehOperadorTest(token)) {
			int valorDir = pilhaPolonesa->desempilha();
			int valorEsq = pilhaPolonesa->desempilha();
			int resultado = avaliaTest(token, valorEsq, valorDir);
			pilhaPolonesa->empilha(resultado);
		} else {
			int valor = (int)(token - '0');
			pilhaPolonesa->empilha(valor);
		}
		exp++;
	}
	return pilhaPolonesa->desempilha();
}

int mainPolonesa() {
    cout<<"Calculadora Polonesa"<<endl<<endl;
	cout <<"('23+31-*'): "<<polonesaTest("23+31-*") << endl;
    cout <<"('93*42/-'): "<<polonesaTest("93*42/-") << endl;
    cout <<"('42*93/-'): "<<polonesaTest("42*93/-") << endl;
    cout <<"('31+23-*'): "<<polonesaTest("31+23-*") << endl;
    cout <<"('39*24+-'): "<<polonesaTest("39*24/-") << endl;
}
