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

void reset(int * array, int len) {
	for (int i = 0; i < len; i++) array[i] = 0;
}

int sum(const int * array, const int * subset, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
		if (subset[i])
			sum += array[i];
	return sum;
}

int finished(const int * subset, int len) {
	for (int i = 0; i < len; i++) if(!subset[i]) return 0;
	return 1;
}

void next(int * subset, int len) {
	for (int i = 0; i < len; i++) {
		if (subset[i]) {
			subset[i] = 0;
		} else {
			subset[i] = 1;
			break;
		}
	}
}

int subsetSumBF(int * array, int len, int value, int * subset, long & count) {
	int tmp = 0;
	reset(subset, len);
	while(!((tmp = sum(array, subset, len)) == value) && !finished(subset, len)) {
		next(subset, len);
		count++;
	}
	return tmp == value;
}

/* funções Backtracking V1 ----------------- */

int __subsetSumBT(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	// Sucesso!
	if (sum == value) return 1;

	if (pos >= len) return 0;
	count++;

	// Adicionando n�mero na posição atual ao conjunto
	subset[pos] = 1;
	if (__subsetSumBT(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	// Desfazendo (Backtracking) porque não deu certo e tentando de novo
	subset[pos] = 0;
	if (__subsetSumBT(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBT(int * array, int len, int value, int * subset, long & count) {
	return __subsetSumBT(array, len, value, subset, 0, 0, count);
}

/* funções Backtracking V2 ----------------- */

int __subsetSumBTv2(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	// Sucesso!
	if (sum == value) return 1;

	if (pos >= len) return 0;
	count++;

	//implementado - prunning - condição para parar a busca
	if (sum > value) return 0;

	// Adicionando número na posição atual ao conjunto
	subset[pos] = 1;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	// Desfazendo (Backtracking) porque não deu certo e tentando de novo
	subset[pos] = 0;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBTv2(int * array, int len, int value, int * subset, long & count) {

    int total = 0;
	for(int i = 0; i < len; i++){
        total += array[i];
	}
	//verificação se numero fornecido é maior que a soma do array
	if(value > total) return 0;

	return __subsetSumBTv2(array, len, value, subset, 0, 0, count);
}

/* -------------------------------------- */

void runSubseqMax(const char * name,	int func(int *, int, int, int *, long &), int * array, int len, int value) {
	long count = 0;
	int * subset = new int[len];
	reset(subset, len);

	auto start = std::chrono::high_resolution_clock::now();

	int found = func(array, len, value, subset, count);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << (found?"YES ":" NO ");
	if (found) {
		cout << "[ ";
		for (int i = 0; i < len; i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << "[time: "<< elapsed << "us] ";
	cout << "[count: "<< count << "]" << endl;


	delete [] subset;
}

int main_SUBSETSUM() {
//int main() {
	int size = 19;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		cout << (array[i] = rand() % (size * 2)) << " ";
	}

//	int array[20]= {3,24,34,6,30,7,31,30,16,11,11,26,33,10,17,26,8,12,14,2};
//	//int array[20]= {1,2,4,5,6,7,8,10,11,12,14,16,17,22,23,26,30,32,33,35};
//	//int array[20]= {35,33,32,30,26,23,22,17,16,14,12,11,10,8,7,6,5,4,2,1};
//	for (int i = 0; i<20; i++){
//		cout<< array[i] <<" ";
//	}

	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		 value += (rand() % (size * 2));

//	int valores[20] = {17,25,58,89,117,117,141,161,176,203,238,243,282,301,301,307,315,344,365,370};
//	int value;
//	for(int i=0;i <20;i++){
//		value = valores[i];

		cout << i << ": Trying " << value << " ..." << endl;

		runSubseqMax("Bruteforce     ", subsetSumBF, array, size, value);
		runSubseqMax("Backtracking   ", subsetSumBT, array, size, value);
		runSubseqMax("Backtracking V2", subsetSumBTv2, array, size, value);
	}

	return 0;
}










/*
 *
//Main Teste2 ( valores de testes inseridos)
	int size = 20;
//	int * array = new int[size];
//
//	for (int i = 0; i < size; i++) {
//		cout << (array[i] = rand() % (size * 2)) << " ";
//	}
	int array[20]= {3,24,34,6,30,7,31,30,16,11,11,26,33,10,17,26,8,12,14,2};
	//int array[20]= {1,2,4,5,6,7,8,10,11,12,14,16,17,22,23,26,30,32,33,35}; //array ordenado menor para maior
	//int array[20]= {35,33,32,30,26,23,22,17,16,14,12,11,10,8,7,6,5,4,2,1}; //array ordenado maior para menor
	for (int i = 0; i<20; i++){
		cout<< array[i] <<" ";
	}
	cout << endl;
//	int value = 0;
//	for (int i = 0; i < 20; i++) {
//		 value += (rand() % (size * 2));
	int valores[20] = {17,25,58,89,117,117,141,161,176,203,238,243,282,301,301,307,315,344,365,370};
	int value;
	for(int i=0;i <20;i++){
		value = valores[i];
		cout << i << ": Trying " << value << " ..." << endl;
		runSubseqMax("Bruteforce     ", subsetSumBF, array, size, value);
		runSubseqMax("Backtracking   ", subsetSumBT, array, size, value);
		runSubseqMax("Backtracking V2", subsetSumBTv2, array, size, value);
	}
	return 0;
 * */
