#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <iostream>
using namespace std;

void trocar(int & a, int & b) {
	int var;
	var = a;
	a=b;
	b=var;
}
int maximo(const int a, const int b) {
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int minimo(const int a, const int b) {
	if (a<b){
		return a;
	}else{
		return b;
	}
}

#endif // FUNCOES_H_INCLUDED
