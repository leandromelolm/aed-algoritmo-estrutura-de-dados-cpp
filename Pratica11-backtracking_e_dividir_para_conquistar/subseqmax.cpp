/*
 * subseqmax.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */

/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "util.h"

using namespace std;

/* fun��es for�a bruta -----------------*/

int subseqMaxBF(int * array, int len, int & ini, int & end, long & count) {
	int max = -9999, sum;
	ini = end = -1;
	for (int i = 0; i < len; i++) {
		sum = 0;
		for (int j = i; j < len; j++) {
			count++;

			sum += array[j];
			if (sum > max) {
				max = sum;
				ini = i;
				end = j;
			}
		}

	}
	return max;
}

/* fun��es Dividir e Conquistar ----------------- */

int subseqMaxMiddle(int * array, int start, int middle, int finish, int & ini, int & end, long & count) {
	int maxL = 0, maxR = 0;
	int sumL = 0, sumR = 0;

	ini = end = middle;

	for (int i = middle - 1; i >= start; i--) {
		count ++;
		sumL += array[i];
		if (sumL > maxL) {
			maxL = sumL;
			ini = i;
		}
	}

	for (int i = middle + 1; i <= finish; i++) {
		count ++;
		sumR += array[i];
		if (sumR > maxR) {
			maxR = sumR;
			end = i;
		}
	}

	return maxL + maxR + array[middle];
}

// array:	o array sendo processado
// start:	posi��o a ser considerada in�cio do array
// finish:	posi��o a ser considerada final do array
// ini:		(Resultado) deve conter ao final a posi��o de in�cio da subsequ�ncia m�xima
// end: 	(Resultado)	deve contar ao final a posi��o de final da subsequ�ncia m�xima
// RETORNO:	soma da subsequ�ncia m�xima
int __subseqMaxDC(int * array, int start, int finish, int & ini, int & end, long & count) {
	if (start > finish) return -9999; // caso de retorno

	 int middle = (start + finish)/2;

	 int iniL = ini;
	 int endL = end;
	 int maxSumL = __subseqMaxDC(array, start, middle-1, iniL, endL, count);

	 int iniR = ini;
	 int endR = end;
	 int maxSumR = __subseqMaxDC(array, middle+1, finish, iniR, endR, count);

	 int maxSumM = subseqMaxMiddle(array, start, middle, finish, ini, end, count);

	if(maxSumL > maxSumM && maxSumL > maxSumR){
	    ini = iniL;
	    end = endL;
	    return maxSumL;
	}else if(maxSumR > maxSumM && maxSumR > maxSumL){
	    ini = iniR;
	    end = endR;
	    return maxSumR;
	}else{
	    return maxSumM;
	}


	// Calcule a posi��o central (middle)
	//	O meio est� entre start e finish

	// Chame a fun��o recursivamente para as duas metades:
	// 	Lado esquerdo (start at� middle -1) e Lado direito (middle + 1 at� finish)
	//  Para cada metade, devem ser retornados a soma da subseqmax, os os inicios (ini) e finais (end)
	//     Salve esses valores em vari�veis tempor�rias adequadas para cada metade

	// Use subseqMaxMiddle() para achar a sequ�ncia com soma m�xima que passa no meio do array (middle)
	// 	Lembre de salvar o retorno (soma m�xima) e limites da sequ�ncia (ini e end) em vari�veis pr�prias

	// Identifique qual dos tr�s cen�rios (esquerda, direita, meio) gerou a maior soma:
	// 	Esse valor ser� o retornado pelo fun��o e vai determinar
	// 	quais limites ser�o salvo nos par�metros ini e end da chamada atual

	//return -9999; // corrigir com o retorno certo
}

int subseqMaxDC(int * array, int len, int & ini, int & end, long & count) {
	return __subseqMaxDC(array, 0, len - 1, ini, end, count);
}

/* -------------------------------------- */

void runSubseqMax(const char * name, int func(int *, int, int&, int&, long &), int * array, int len, int printSeq) {
	long count = 0;

	int ini, end;

	auto start = std::chrono::high_resolution_clock::now();

	int max = func(array, len, ini, end, count);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";

	if (printSeq) { cout << "[ "; print(array, ini, end); cout << "] "; }

	cout << "[time: "<< elapsed << "us] ";
	cout << "[count: "<< count << "]" << endl;

}

int main_SUBSEQMAX() {
//int main() {
	int printSeq = 0;
	int size = 20;

	int * array = new int[size];

	for (int i = 0; i < 10; i++) {

		for (int i = 0; i < size; i++) {
			array[i] = (rand() % size) - (size / 2);
		}
		cout << i << ": " << endl; //print(array, size);

		runSubseqMax("Bruteforce    ", subseqMaxBF, array, size, printSeq);
		runSubseqMax("Divide&Conquer", subseqMaxDC, array, size, printSeq);
	}

	delete [] array;

	return 0;
}






