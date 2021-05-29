#include <iostream>
#include <locale>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"
#include<string.h>

using namespace std;

int main() {
	int x1 = 10, y1 = 15, z1 = 30;
	float x = 5.5, y = 10.15, z = 30.7;
	char a = 'a', b = 'b', c = 'c';
	char str1[20] = "gato";
	char str2[20] = "pato";
	char str3[20] = "cachorro";
	char str4[20] = "boi";
	char str5[20] = "pato";
	char str6[20] = "ornitorrinco";

	cout << "Valor de X e Y respectivamente: " << x << "   " << y << endl;
	trocar(x, y);
	cout << "Valor de X e Y respectivamente: " << x << "   " << y << endl
			<< endl;

	cout << "\nVerificação de número Máximo e Mínimo \n" << endl;
	cout << "Mínimo entre " << x1 << " e " << y1 << " é: " << minimo(x1, y1)
			<< endl;
	cout << "Máximo entre " << y1 << " e " << z1 << " é: " << maximo(y1, z1)
			<< endl;
	cout << "Mínimo entre " << x << " e " << y << " é: " << minimo(x, y)
			<< endl;
	cout << "Máximo entre " << y << " e " << z << " é: " << maximo(y, z)
			<< endl;
	cout << "Mínimo entre " << a << " e " << b << " é: " << minimo(a, b)
			<< endl;
	cout << "Máximo entre " << c << " e " << b << " é: " << maximo(c, b)
			<< endl;

	cout << "\nVerificação de ordem alfabética\n" << endl;
	cout << maximo(str1, str3) << endl;
	cout << maximo(str1, str2) << endl;
	cout << maximo(str4, str3) << endl;
	cout << maximo(str2, str5) << endl;

	cout << "\nVerificação de quantidade de caracteres\n" << endl;
	cout << "Quant caracteres: " << minimo(str1, str3) << endl;
	cout << "Quant caracteres: " << minimo(str2, str5) << endl;
	cout << "Quant caracteres: " << minimo(str6, str3) << endl;
	cout << "Quant caracteres: " << minimo(str3, str2) << endl;

	cout << "\nArray do tipo inteiro" << endl;
	try {
		Arranjo<int> arr(10);
		arr.set(4, 5);
		arr.set(7, 15);
		arr.set(8, 22);
		arr.set(1, 13);
		arr.set(9, 11);
//	arr.set(11, 18); // Provoca erro
		arr.exibir();
	} catch (const char *msg) {
		cout << "Erro: " << msg << endl;
	}

	cout << "\nArray do tipo Float" << endl;
	try {
		Arranjo<float> arr_float(10);
		arr_float.set(4, 0.3);
		arr_float.set(7, 15.5);
		arr_float.set(8, 22.9);
		arr_float.set(1, 19.1);
		arr_float.set(0, 8.2);
		arr_float.set(2, 50.356);
//		arr_float.set(10, 30.31); // Provoca erro
		arr_float.set(9, 30.31);
		arr_float.exibir();
	} catch (const char *msg) {
		cout << "Erro: " << msg << endl;
	}

	cout << "\nArray de Alunos" << endl;
	Arranjo<Aluno> turma(8);
	try {
		turma.set(0, Aluno("Joao.", "1234"));
		turma.set(1, Aluno("Maria", "5235"));
		turma.set(2, Aluno("Jose", "2412"));
		turma.set(3, Aluno("Carl", "2400"));
		turma.set(7, Aluno("Leo", "2412"));
//		turma.set(8, Aluno("Leandro", "2412")); // erro (array vai até a posição 7)
		turma.exibir();
	} catch (const char *msg) {
		cout << "Erro: " << msg << endl;
	}
}

