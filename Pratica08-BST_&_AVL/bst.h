/*
 * bst.h
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#ifndef BST_H_
#define BST_H_

#include <algorithm> // max

using namespace std;

#define ASSERT(X, E) if(!(X)) throw (E);

class BinaryTree {
protected:
	struct Node {
		int key;
		int height; // altura da árvore em níveis
		Node * left;
		Node * right;
		Node(int key) : key(key), height(1), left(NULL), right(NULL) {}
	};


	// Pega a altura. Simplifica código no caso de subárvore vazia (NULL)
	static int H(Node * node) { return (node != NULL)?node->height:0; }

	// Atualiza a altura de um nó da árvore. Assume que a altura das subárvore está correta.
	static void updateH(Node * node) { node->height = max(H(node->left), H(node->right)) + 1; }

	Node * root;

public:
	BinaryTree() {
		root = NULL;
	}

	virtual ~BinaryTree() {
		deleteTree(root);
	}

	void insert(int key) {
		root = insert(root, key);
		ASSERT(validate(), "inser(): invalid tree!");
	}

	void remove(int key) {
		root = remove(root, key);
		ASSERT(validate(), "remove(): invalid tree!");
	}

	int  search(int key) {
		return search(root, key) != NULL;
	}

	int  predecessor(int key) {
		Node * node = NULL;
		predecessor(root, node, key);
		return (node != NULL)?node->key:-1;
	}

	int  successor(int key) {
		Node * node = NULL;
		successor(root, node, key);
		return (node != NULL)?node->key:-1;
	}

	int  validate() {
		int min, max;
		return validate(root, min, max);
	}

	void show() {
		show(root);
	}

	int  empty() {
		return root == NULL;
	}

protected:
	void deleteTree(Node * node) {
		if (node == NULL) return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	virtual Node * insert(Node * root, int key);
	virtual Node * remove(Node * root, int key);
	virtual Node * removeMax(Node * root, int & max);
	virtual Node * search(Node * root, int key);

	virtual void predecessor(Node * root, Node * & pred, int key);
	virtual void successor(Node * root, Node * & succ, int key);

	virtual void   show(Node * root);
	virtual int    validate(Node * root, int &min, int &max);
};



#endif /* BST_H_ */
