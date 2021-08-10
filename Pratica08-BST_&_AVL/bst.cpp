/*
 * bst.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <climits> // INT_MIN e INT_MAX

#include "bst.h"

// Inserção, ver material.
BinaryTree::Node * BinaryTree::insert(BinaryTree::Node * root, int key) {
	// TODO

    if(root == NULL){
        root = new Node(key);
    }else if(key > root->key)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);

    updateH(root);

	return root;

}

// Busca, ver material.
BinaryTree::Node * BinaryTree::search(BinaryTree::Node * root, int key) {

	// TODO
	if (root == NULL) return NULL;

	if (root->key == key) return root;

	if (root->key < key)
		return search(root->right, key);
	else
		return search(root->left, key);

}

// Exibir a árvore EM ORDEM
void BinaryTree::show(Node * root) {

	if (root == NULL) return;
	// TODO
	// Percorrer a árvore: esquerda, raiz, direita

	show(root->left);
	cout << "(" << root->key << ", " << root->height << ") ";
	show(root->right);

}

// Acha nó sucessor (succ) a chave (key)
void BinaryTree::successor(Node * root, Node * & succ, int key) {
	// TODO Ver predecessor

	if (root == NULL) return;

	if (root->key == key) {
		root = root->right;
		while (root != NULL) {
			succ = root;
			root = root->left;
		}
	} else {
		if (key > root->key)
			successor(root->right, succ, key);
		else
			successor(root->left, succ = root, key);
	}

}

// Acha nó predecessor (pred) a chave (key)
void BinaryTree::predecessor(Node * root, Node * & pred, int key) {
	if (root == NULL) return;

	if (root->key == key) { 		// Chave encontrada
		root = root->left;			// Desce a esquerda, pred não é mexido inicialmente
		while (root != NULL) {
			pred = root;			// pred vai ser o elemento mais a direita
			root = root->right;
		}
	} else {
		if (key < root->key)		// Chave se encontra a esquerda da raiz
			// não mexemos em pred aqui
			predecessor(root->left, pred, key);
		else						// Chave se encontra a direita
			// No caso de predecessor, pred é atualizado quando descemos a direita
			predecessor(root->right, pred = root, key);
	}
}

BinaryTree::Node * BinaryTree::remove(BinaryTree::Node * root, int key) {

	if (root == NULL) return NULL; // (sub)árvore vazia, nada a fazer

	if (key == root->key) { // Chave encontrada!
		if (root->left != NULL && root->right != NULL) { // Caso 3
			int maxLeft;
			// Removo o maior filho da esquerda e
			// substituo o valor do nó atual com o valor que era dele
			root->left = removeMax(root->left, maxLeft);
			root->key = maxLeft;
		} else { // Casos 1 e 2
			Node * tmp = root;
			root = (root->right != NULL)?root->right:root->left;
			delete tmp;
		}
	} else {
		if (key > root->key)
			root->right = remove(root->right, key);
		else
			root->left = remove(root->left, key);
	}

	// Lembrar sempre de atualizar a altura; importante para a AVL
	if (root != NULL) updateH(root);

	return root;
}

BinaryTree::Node * BinaryTree::removeMax(BinaryTree::Node * root, int & max) {
	if (root == NULL) throw "ERRO";

	if (root->right != NULL) {
		root->right = removeMax(root->right, max);
	} else {
		max = root->key;
		Node * tmp = root;
		root = root->left;
		delete tmp;
	}

	if (root != NULL)
		updateH(root);

	return root;
}

// Valida a árvore
// min e max são o menor e o maior valores contidas na árvore, respectivamente
int BinaryTree::validate(Node * root, int &min, int &max) {

	if (root == NULL) { // Árvore vazia é válida
		min = INT_MAX;
		max = INT_MIN;
		return 1;
	}

	int lmin, lmax; // menor e maior a esquerda
	int rmin, rmax; // menor e maior a direita

	// Se árvore à esquerda é inválida ou maior a esquerda > raiz então INVÁLIDA
	if (!validate(root->left, lmin, lmax) || (lmax > root->key)) return 0;

	// Se árvore à direita é inválida ou menor à direita < raiz então INVÁLIDA
	if (!validate(root->right, rmin, rmax) || (rmin < root->key)) return 0;

	// Computando menor e maior para árvore em root
	min = (root->left != NULL)?lmin:root->key;
	max = (root->right != NULL)?rmax:root->key;

	return 1;
}


