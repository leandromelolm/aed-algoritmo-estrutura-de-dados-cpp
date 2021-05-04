#include <iostream>
#include <locale>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"
#include<string.h>

using namespace std;

int main()
{
//	int x = 10, y = 15, z = 30;
	float x = 5.5, y = 10.15, z = 30.7;
	char a = 'a', b = 'b', c = 'c';
	char str1[20]="gato";  char str2[20]="pato";  char str3[20]="cachorro";  char str4[20]="boi";  char str5[20]="pato";
//	char str1[20]={'pato'}; char str2[20]={'gato'}; char str3[20]={'cachorro'};

	cout<<"Valor de X e Y respectivamente: "<<x<<"   "<<y<<endl;
	trocar(x, y);
	cout<<"Valor de X e Y respectivamente: "<<x<<"   "<<y<<endl<<endl;

	cout << "Mínimo entre " << x << " e " << y << " é: "<< minimo(x, y) << endl;
	cout << "Máximo entre " << y << " e " << z << " é: "<< maximo(y, z) << endl;

	cout << "Mínimo entre " << a << " e " << b << " é: "<< minimo(a, b) << endl;
	cout << "Máximo entre " << c << " e " << b << " é: "<< maximo(c, b) << endl;

	cout<<"\nVerificação de ordem alfabética\n"<<endl;
	cout << maximo(str1,str3) << endl;
	cout <<maximo(str1,str2) << endl;
	cout <<maximo(str4,str3) << endl;
	cout <<maximo(str2,str5) << endl;

}


