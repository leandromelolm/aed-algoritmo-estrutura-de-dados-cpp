/*
 * main.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <chrono>
#include <stdlib.h>

#include "bst.h"
#include "avl.h"

using namespace std;

void searchRemoveShow(BinaryTree &tree, int value, int show) {
	auto start = std::chrono::high_resolution_clock::now();

	int found = tree.search(value);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 1000;

	if (found) tree.remove(value);

	int valid = tree.validate();

	cout    << "Value: " << value
			<< " Found/removed = " << (found ? "YES" : "NO ")
			<< " [" << (valid ? "valid" : "invalid")<< "]"
			<< " [time = " << elapsed << "] ";

	if (show) tree.show();

	cout << endl;
}

int main() {
	int values [10] = {10, 35, 22, 16, 1, 45, 17, 88, 62, 7}; // ordem de inserção (não ordenado)
//	int values [10] = {1, 7, 10, 16, 17, 22, 35, 45, 62, 88}; // ordem de inserção (ordenado)
	int sorted [10] = {1, 7, 10, 16, 17, 22, 35, 45, 62, 88}; // ordem natural, para testes (ordenado)
	int size = 10;

//	int values [11] = {10, 35, 22, 16, 1, 45, 17, 88, 62, 7,63}; // ordem de inserção
//	int sorted [11] = {1, 7, 10, 16, 17, 22, 35, 45, 62, 63, 88}; // ordem natural, para testes
//	int size = 11;

/**** Testes BST e AVl *****/

	BinaryTree * tree = new BinaryTree();   // Teste BST

//	BinaryTree * tree = new AVLTree();      // Teste AVL

	try {

		for (int i = 0; i < size; i++) {
//			int value = rand() % size;

			int value = values[i];			// Para teste BST (Teste com valores não ordenados)

//			int value = sorted[i];			// Para teste AVL (Teste com valores ordenado - força rotações)

			tree->insert(value);
		}

		cout << "Tree is valid: " << (tree->validate() ? "yes" : "no") << endl;
		tree->show();
		cout << endl;

		cout << "Testing Successor and Predecessor:" << endl;
		for (int i = 1; i < size - 1; i++) {
			int val = sorted[i];
			int pred = sorted[i - 1];
			int succ = sorted[i + 1];

			cout << "Successor   of " << val << " == " << succ << "? " << ((tree->successor(val) == succ)?"YES":"NO") << endl;
			cout << "Predecessor of " << val << " == " << pred << "? " << ((tree->predecessor(val) == pred)?"YES":"NO") << endl;
		}

		cout << "Testing Search and Remove:" << endl;
		for (int i = 0; i < size; i++) {
			int val = sorted[i];

			searchRemoveShow(*tree, val, 1);
		}


	} catch (const char * msg) {
		cout << "ERRO: " << msg << endl;
		tree->show();
		cout << endl;
	}

	delete tree;
}

