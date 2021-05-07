#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <iostream>
#include<cstring>


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
	 char * c="";
//	int compara;
//	compara=strcmp(a,b);
//	cout << "a diferença entre "<<a<<" e "<< b << " é  de "<< compara << endl;
//	if (compara < 0) {
	if (strcmp(a,b)<0){
//		cout<<strcmp(a,b)<<endl;
		cout << a << " na ordem alfabetica vem na frente de " << b << "."	<< endl;
//		return a;
	}	else if (strcmp(a,b)>0) {
		cout << b << " na ordem alfabética vem na frente de " << a << "."	<< endl;
//		return b;
	} else if (strcmp(a,b)==0) {
		cout << "As strings são iguais: "<<a<<" e "<<b << endl;
//		return 0;
	}
	return c;
//		return 0;
	/*
				=0 -> string são iguais
				>0 -> a é maior que b
				<0 -> b é maior que a
	 */
}
template<>
char* minimo<char*>(char *a, char *b) {
	int quant_a;
	int quant_b;
	quant_a=strlen(a);
	quant_b=strlen(b);
	if(quant_a<quant_b){
		cout<<a<<":"<<quant_a<<"; "
				<<b<<":"<<quant_b<<",  menos caracteres: ";
		return a;
	}else if(quant_a>quant_b){
		cout<<a<<":"<<quant_a<<"; "
				<<b<<":"<<quant_b<<",  menos caracteres: ";
		return b;
	}else{
		cout<<a<<":"<<quant_a<<"; "
				<<b<<":"<<quant_b<<",  iguais: ";
	return a;
	}
}
#endif // FUNCOES_H_INCLUDED
