/*
 * avl.cpp
 *
 *  Created on: 3 de nov de 2017
 *      Author: ramide
 */

#include <iostream>
#include "avl.h"

using namespace std;

BinaryTree::Node * AVLTree::insert(BinaryTree::Node * root, int key) {
	root = BinaryTree::insert(root, key);

	if (!balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::remove(BinaryTree::Node * root, int key) {
	if (root == NULL)
		return NULL;

	root = BinaryTree::remove(root, key);

	if (root != NULL && !balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::removeMax(BinaryTree::Node * root, int & max) {

	root = BinaryTree::removeMax(root, max);

	if (root != NULL && !balanced(root))
			root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::rebalance(Node * root) {
	ASSERT(!balanced(root), "Already balanced!");

	if (leftHeavy(root)) {
		if (rightHeavy(root->left))
			root->left = rotateLeft(root->left);

		root = rotateRight(root);
	} else { // rightHeavy
		if (leftHeavy(root->right))
			root->right = rotateRight(root->right);

		root = rotateLeft(root);
	}

	ASSERT(balanced(root), "Rebalance failed!");
	return root;
}

// Realiza a rotação a esquerda sobre "root" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateLeft(Node * root) {
	// TODO siga as ilustrações do material
	// dê updateH() nos nós modificados ao final
	return root;
}

// Realiza a rotação a direita sobre "root" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateRight(Node * root) {
	// TODO siga as ilustrações do material
	// dê updateH() nos nós modificados ao final
	return root;
}

// Exibição da árvore AVL
void AVLTree::show(Node * root) {
	// Deve exibir o valor da chave e o fator de balancemento (BF()) por nó da árvore
	// TODO
}

int AVLTree::validate(Node * root, int &min, int &max) {
	int valid = BinaryTree::validate(root, min, max);

	return valid && balanced(root);
}
