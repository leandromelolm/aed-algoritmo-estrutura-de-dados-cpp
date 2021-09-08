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

/* funções força bruta -----------------*/

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

/* funções Dividir e Conquistar ----------------- */

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
// start:	posição a ser considerada início do array
// finish:	posição a ser considerada final do array
// ini:		(Resultado) deve conter ao final a posição de início da subsequência máxima
// end: 	(Resultado)	deve contar ao final a posição de final da subsequência máxima
// RETORNO:	soma da subsequência máxima
int __subseqMaxDC(int * array, int start, int finish, int & ini, int & end, long & count) {
	if (start > finish) return -9999; // caso de retorno

	 int middle = (start + finish)/2;

	 int iniLeft = ini;
	 int endLeft = end;
	 int maxSumL = __subseqMaxDC(array, start, middle-1, iniLeft, endLeft, count);

	 int iniRight = ini;
	 int endRight = end;
	 int maxSumR = __subseqMaxDC(array, middle+1, finish, iniRight, endRight, count);

	 int iniMidle = ini;
	 int endMidle = end;
	 int maxSumM = subseqMaxMiddle(array, start, middle, finish, iniMidle, endMidle, count);

	if(maxSumL > maxSumM && maxSumL > maxSumR){
	    ini = iniLeft;
	    end = endLeft;
	    return maxSumL;
	}else if(maxSumR > maxSumM && maxSumR > maxSumL){
	    ini = iniRight;
	    end = endRight;
	    return maxSumR;
	}else{
	    return maxSumM;
	}


	// Calcule a posição central (middle)
	//	O meio está entre start e finish

	// Chame a função recursivamente para as duas metades:
	// 	Lado esquerdo (start até middle -1) e Lado direito (middle + 1 até finish)
	//  Para cada metade, devem ser retornados a soma da subseqmax, os os inicios (ini) e finais (end)
	//     Salve esses valores em variáveis temporárias adequadas para cada metade

	// Use subseqMaxMiddle() para achar a sequência com soma máxima que passa no meio do array (middle)
	// 	Lembre de salvar o retorno (soma máxima) e limites da sequência (ini e end) em variáveis próprias

	// Identifique qual dos três cenários (esquerda, direita, meio) gerou a maior soma:
	// 	Esse valor será o retornado pelo função e vai determinar
	// 	quais limites serão salvo nos parámetros ini e end da chamada atual

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

//int main_SUBSEQMAX() {
int main() {
	int printSeq = 1;
	int size = 50;

	int * array = new int[size];

//	srand(1234);
//	srand(time(NULL));
	for (int i = 0; i < 10; i++) {

		for (int i = 0; i < size; i++) {
			array[i] = (rand() % size) - (size / 2);
		}
		cout << i << ": " << endl; print(array, size);

		runSubseqMax("Bruteforce    ", subseqMaxBF, array, size, printSeq);
		runSubseqMax("Divide&Conquer", subseqMaxDC, array, size, printSeq);
	}

	delete [] array;

	return 0;
}


