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
/*
	=0 -> string são iguais
	>0 -> a é maior que b
	<0 -> b é maior que a
*/

/*
 * A função strcmp compara duas strings e devolve um valor inteiro
 * que lhe diz qual das strings vem antes no código ASCII
 * */

	if (strcmp(a,b)<0){
//		cout<<strcmp(a,b)<<endl;
		cout << a << " e " << b << ". Quem vêm antes na ordem alfabética é: ";
		return a;
	}	else if (strcmp(a,b)>0) {
//		cout<<strcmp(a,b)<<endl;
		cout << b << " e " << a << ". Quem vêm antes na ordem alfabética é: ";
		return b;
	} else if (strcmp(a,b)==0) {
		cout << "As strings são iguais. As duas são: ";
		return a;
	}
		return 0;

}
template<>
char* minimo<char*>(char *a, char *b) {
/*
 * strlen interpreta a cadeia de caracteres como uma cadeia de caracteres de byte único,
 * portanto, seu valor de retorno é sempre igual ao número de bytes, mesmo que a cadeia
 * de caracteres contenha caracteres multibyte.
 * */

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
