/*
 * avl.h
 *
 *  Created on: 2 de nov de 2017
 *      Author: ramide
 */

#ifndef AVL_H_
#define AVL_H_

#include "bst.h"

#include <algorithm> // max
using namespace std;

class AVLTree : public BinaryTree {
protected:
	// Fator de balanceamento
	static int BF(Node * node) {
		return H(node->left) - H(node->right);
	}
	// Balanceada?
	static int balanced(Node * node) {
		return node == NULL || abs(BF(node)) < 2;
	}

	// Pesada à esquerda ou à direita?
	static int leftHeavy(Node * node) { return H(node->left) > H(node->right); }
	static int rightHeavy(Node * node) { return H(node->left) < H(node->right); }

	// Funções de balanceamento e rotação
	Node * rebalance(Node * node);
	Node * rotateLeft(Node * node);
	Node * rotateRight(Node * node);

protected:
	virtual Node * insert(Node * root, int key);
	virtual Node * remove(Node * root, int key);
	virtual Node * removeMax(Node * root, int & max);

	virtual void show(Node * root);
	virtual int validate(Node * root, int &min, int &max);
};


#endif /* AVL_H_ */
