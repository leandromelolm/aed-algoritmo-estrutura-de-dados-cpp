#include <iostream>
#include <locale>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace std;

int main()
{
//	int x = 10, y = 15, z = 30;
	float x = 5.5, y = 10.15, z = 30.7;
	cout<<"Valor de X e Y respectivamente: "<<x<<"   "<<y<<endl;
	cout<<" Método Trocar()"<<endl;
	trocar(x, y);
	cout<<"Valor de X e Y respectivamente: "<<x<<"   "<<y<<endl<<endl;
	cout << "Mínimo entre " << x << " e " << y << " é: "<< minimo(x, y) << endl;
	 cout << "Máximo entre " << y << " e " << z << " é: "<< maximo(y, z) << endl;
}


