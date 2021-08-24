/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int validate(int * data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1]) return 0;
	}
	return 1;
}

void print(int * data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int * clone(int * array, int size) {
	int * copy = new int[size];
	for (int i = 0; i < size; i++) { copy[i] = array[i]; }
	return copy;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void noopsort(int * array, int size) {
	// no-op
}

/* Parte 1: Implementando BubbleSort  */
void bubblesort(int * array, int size) {

	int last_unordered = size - 1;
	bool change = false;
	do{
    change = false;
        for(int i = 0; i < last_unordered; i++){
            if(array[i] > array[i + 1]){
                swap(array[i], array[i + 1]);
                change = true;
            }
        }
	}while(change);

}

/* Parte 2: Implementando SelectionSort  */
void selectionsort(int * array, int size) {

	for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(array[min] > array[j])
                min = j;
        }
        swap(array[i], array[min]);
	}

}

/* Parte 2: Implementando InsertionSort  */
void insertionsort(int * array, int size) {

	for(int i = 1; i < size; i++){
        int tmp = array[i];
        int j= i - 1;
        while(array[j] > tmp && j >= 0){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
	}

}

/* Parte 3: Implementando a junção do MergeSort  */
void merge(int * target, int * buffer, int start, int mid, int finish) {

	int auxMid = mid;
	int arrPos = start;

	while(start < mid && auxMid <= finish){
        if(buffer[start] < buffer[auxMid]){
            target[arrPos] = buffer[start];
            start++;
        }else{
            target[arrPos] = buffer[auxMid];
            auxMid++;
        }
        arrPos++;
	}

	while(start < mid){
        target[arrPos] = buffer[start];
        start++;
        arrPos++;
    }

    while(auxMid <= finish){
        target[arrPos] = buffer[auxMid];
        auxMid++;
        arrPos++;
    }
}


void mergesort(int * target, int * buffer, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(buffer, target, start, mid);
	mergesort(buffer, target, mid + 1, finish);

	merge(target, buffer, start, mid + 1, finish);
}

void mergesort(int * array, int size) {
	int * copy = clone(array, size);
	mergesort(array, copy, 0, size - 1);
	delete [] copy;
}

/* Parte 4: Implementando a partição do QuickSort */
int partition(int * array, int start, int finish) {

	int p = array[finish];
	int menor = start - 1;
	for(int i = start; i <= finish - 1; i++){
        if(array[i] <= p){
            menor++;
            swap(array[menor], array[i]);
        }
	}
    swap(array[menor + 1], array[finish]);
	return menor + 1;
}

void quicksort(int * array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

void quicksort(int * array, int size) {
	quicksort(array, 0, size - 1);
}



void show(int * array, int size, const char * name, void function(int *, int), int printFlag) {
	int * copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy, size);
	delete [] copy;
}

int main() {
	int size = 10000;
	int print = 1;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	show(array, size, "NoOpSort     ", noopsort, print);
	show(array, size, "BubbleSort   ", bubblesort, print);
	show(array, size, "SelectionSort", selectionsort, print);
	show(array, size, "InsertionSort", insertionsort, print);
	show(array, size, "MergeSort    ", mergesort, print);
	show(array, size, "QuickSort    ", quicksort, print);

	delete [] array;
}






