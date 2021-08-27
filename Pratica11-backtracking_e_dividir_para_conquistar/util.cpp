/*
 * util.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */
#include <iostream>

#include "util.h"

using namespace std;

void print(int * array, int ini, int end) {
	for (int i = ini; i <= end; i++) cout << array[i] << " ";
}

void print(int * array, int len) {
	print(array, 0, len - 1);
	cout << endl;
}

inline int max(int a, int b) { return (a > b)?a:b; }
