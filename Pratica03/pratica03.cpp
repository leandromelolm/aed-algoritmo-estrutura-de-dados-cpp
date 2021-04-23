/*
 * pratica03.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#include <iostream>
#include <locale>
#include "funcoes.h"
using namespace std;
#include "arranjo.h"
#include "aluno.h"

int main()
{
    setlocale(LC_ALL, "");
    cout << "Prática sobre templates" << endl<<endl;
    /**Declaração inicial das variáveis*/
    //int x = 5, y = 10, z = 30;
    char a = 'a', b = 'b', c = 'c';
    int i = 10, j = 15, k = 30;
    float x = 5.5, y = 10.15, z =30.7;
    cout<<"X antes da troca: "<<x<<endl;
    cout<<"Y antes da troca: "<<y<<endl<<endl;
    trocar(x, y);
    cout<<"Valor de X: "<<x<<endl;
    cout<<"Valor de Y: "<<y<<endl<<endl;
    cout<<"Float:"<<endl;
    cout << "Mínimo entre " << x << " e " << y << " eh "<< minimo(x, y) << endl;
    cout << "Máximo entre " << y << " e " << z << " eh "<< maximo(y, z) << endl<<endl;
    cout<<"Caractere:"<<endl;
    cout << "Mínimo entre " << a << " e " << b << " eh "<< minimo(a, b) << endl;
    cout << "Máximo entre " << b << " e " << c << " eh "<< maximo(b, c) << endl<<endl;
    cout<<"Inteiro:"<<endl;
    cout << "Mínimo entre " << i << " e " << j << " eh "<< minimo(i, j) << endl;
    cout << "Máximo entre " << j << " e " << k << " eh "<< maximo(j, k) << endl<<endl;
    Arranjo<int> arr(10);
    arr.set(4, 5);
    arr.set(7, 15);
    arr.set(8, 22);
    cout<<"Array de Inteiros: "<<endl;
    arr.exibir();
    Arranjo<float> arr2(5);
    arr2.set(0,0.1);
    arr2.set(1,0.2);
    arr2.set(2,0.3);
    arr2.set(3,0.4);
    arr2.set(4,0.5);
    cout<<"Array de Floats: "<<endl;
    arr2.exibir();
    Arranjo<Aluno> turma(3);
    turma.set(0, Aluno("Joao", "1234"));
    turma.set(1,Aluno("Maria", "5235"));
    turma.set(2, Aluno("Jose", "2412"));
    turma.exibir();
    return 0;
}


