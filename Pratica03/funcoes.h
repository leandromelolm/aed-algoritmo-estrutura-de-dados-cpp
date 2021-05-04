#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <iostream>
#include<cstring>
#include<string>

using namespace std;

template<class  T>
void trocar(T & a, T & b) {
	cout<<" Executando Método trocar()"<<endl;
	T var;
	var = a;
	a=b;
	b=var;
}
template<class T>
T maximo(const T a, const T b) {
	if(a>b){
		return a;
	}else{
		return b;
	}
}
template<class T>
T minimo(const T a, const T b) {
	if (a<b){
		return a;
	}else{
		return b;
	}
}
template<>
char* maximo<char*>(char *a, char *b) {
	 char * c="Teste de ordem alfabética";
	int compara;
	compara=strcmp(a,b);
//	cout << "a diferença entre "<<a<<" e "<< b << " é  de "<< retorno << endl;
//	if (compara < 0) {
	if (strcmp(a,b)<0) {
		cout << a << " na ordem alfabetica vem na frente de " <<b<<"."<<endl;
//		return a;
	} else if (compara == 0) {
		cout << "strings são iguais" << endl;
//		return 0;
	} else if (compara > 0) {
		cout << b << " na ordem alfabética vem na frente de "<<a<<"."<< endl;
//		return b;
	}
	return c;
}

//	int compara = strcmp(a,b);
////	cout <<a<<"  "<<b<<endl;
//	switch (compara) {
//	case -1:
//		cout<<a<<"\n vem primeiro na ordem alfabetica"<<endl;
//		break;
//	case 0 :
//		cout<<"\nstring são iguais"<<endl;
//		break;
//	case 1:
//		cout<<b<<"\n vem primeiro na ordem alfabetica"<<endl;
//		break;
//	}

#endif // FUNCOES_H_INCLUDED
