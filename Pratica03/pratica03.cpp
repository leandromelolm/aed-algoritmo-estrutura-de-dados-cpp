#include <iostream>
#include <locale>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace std;

int main()
{
	int x = 10, y = 15, z = 30;
	cout<<"Valor de X e Y respectivamente: "<<x<<" "<<y<<endl;
	cout<<" Método swap"<<endl;
	swap(x, y);
	cout<<"Valor de X e Y respectivamente: "<<x<<" "<<y<<endl<<endl;
	cout << "Mínimo entre " << x << " e " << y << " é: "<< minimo(x, y) << endl;
	 cout << "Máximo entre " << x << " e " << y << " é: "<< maximo(x, y) << endl;
}


