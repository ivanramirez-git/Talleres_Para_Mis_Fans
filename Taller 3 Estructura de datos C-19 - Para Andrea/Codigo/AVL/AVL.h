/*
 * AVL.h
 *
 *  Created on: May 3, 2015
 *      Author: bassam
 */
#ifndef AVL_H_
#define AVL_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/******************************************************************************/
/* An enum type to indicate whether an allocation failure occurred*/
typedef enum {
	MEMORY_SUCCESS, MEMORY_ERROR
} MonitorResult;
/******************************************************************************/
/* The atomic unit of the tree - a single node representation.
 * @key: the data which the node holds and characterizes it from the rest of-
 * 		 nodes in the tree
 * @leftSon: a pointer to the left son of the current node
 * @rightSon: a pointer to the right son of the current node.
 * @parent: parent of this node.
 * @height: the height of the tree. */
template<typename T>
struct Node {
	T key;
	unsigned int height;
	Node<T>* leftSon;
	Node<T>* rightSon;
	Node(T keyValue) :
			key(keyValue), height(1), leftSon(NULL), rightSon(NULL) {
	}
	virtual ~Node() {
		delete (leftSon);
		delete (rightSon);
	}
};
/******************************************************************************/
template<typename T>
bool operator==(const Node<T>& n1, const Node<T>& n2) {
	return (n1.key == n2.key);
}
/******************************************************************************/
template<typename T>
bool operator<(const Node<T>& n1, const Node<T>& n2) {
	return (n1.key < n2.key);
}
/******************************************************************************/
template<typename T>
bool operator>(const Node<T>& n1, const Node<T>& n2) {
	return (n1.key > n2.key);
}
/******************************************************************************/
/*
 * Main class.
 * Provides the API of a generic AVL tree.
 * typename T: what is the type of a single node.
 */
/******************************************************************************/
template<typename T>
class AVL {
private:
	Node<T>* root;
	int size;
	int numOfNodes;
	void updateHeight(Node<T>* node);
	Node<T>* rotateLeft(Node<T>* node);
	Node<T>* rotateRight(Node<T>* node);
	Node<T>* RR(Node<T>* node);
	Node<T>* RL(Node<T>* node);
	Node<T>* LR(Node<T>* node);
	Node<T>* LL(Node<T>* node);
	Node<T>* aux_search(T key, Node<T>* node);
	Node<T>* aux_findMin(Node<T>* node);
	Node<T>* aux_removeMin(Node<T>* node);
	Node<T>* aux_insert(Node<T>* node, T key);
	Node<T>* aux_deleteNode(Node<T>* node, T key);
	int aux_getSize(Node<T>* node);
	void aux_destroyTree(Node<T>* node);
public:
	AVL(Node<T>* root);
	AVL();
	~AVL() {
	}
	void destroyTree();
	int getHeight(const Node<T>* node) const;
	int getBalanceFactor(const Node<T>* node) const;
	MonitorResult insert(T key);
	MonitorResult deleteNode(T key);
	Node<T>* balance(Node<T>* node);
	Node<T>* search(const T key);
	int getSize();
	Node<T>* getRoot();
	Node<T>* getMin();
};
/******************************************************************************/
/*IMPLEMENTATION OF AVL API*/
/******************************************************************************/
template<typename T>
void AVL<T>::destroyTree() {
	aux_destroyTree(root);
}
/******************************************************************************/
template<typename T>
void AVL<T>::aux_destroyTree(Node<T>* node) {
	if (node) {
		aux_destroyTree(node->leftSon);
		aux_destroyTree(node->rightSon);
		delete (node);
	}
}
/******************************************************************************/
/* return the node with the minimal key in the whole AVL tree. */
template<typename T>
Node<T>* AVL<T>::getMin() {
	return aux_findMin(root);
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::getRoot() {
	return root;
}
/******************************************************************************/
template<typename T>
int AVL<T>::getSize() {
	return numOfNodes;
}
/******************************************************************************/
//Constructor
template<typename T>
AVL<T>::AVL(Node<T>* root) :
		root(root), size(0), numOfNodes(0) {
}
//default constructor:
template<typename T>
AVL<T>::AVL() :
		root(NULL), size(0), numOfNodes(0) {
}
/******************************************************************************/
/* Search for the node in the tree with the given key.
 * Return a pointer to that node.*/
template<typename T>
Node<T>* AVL<T>::search(const T key) {
	return aux_search(key, root);
}
/******************************************************************************/
/* This is a helper method to the main search function.
 * Here, the recursive part occurs.
 * I implemented this method because the main search function does receive-
 * only the key to search for*/
template<typename T>
Node<T>* AVL<T>::aux_search(T key, Node<T>* node) {
	if (node == NULL) {
		return node;
	} else if ((node->key) < key) {
		return aux_search(key, node->rightSon);
	} else if (node->key > key) {
		return aux_search(key, node->leftSon);
	}
	return node;
}
/******************************************************************************/
/*returns the height of the tree which root is passed to the function as-
 *an argument*/
template<typename T>
int AVL<T>::getHeight(const Node<T>* node) const {
	return node ? node->height : 0;
}
/******************************************************************************/
/*Returns the balance factor of the node which is passed as an argument*/
template<typename T>
int AVL<T>::getBalanceFactor(const Node<T>* node) const {
	return node ? (getHeight(node->leftSon) - getHeight(node->rightSon)) : 0;
}
/******************************************************************************/
template<typename T>
void AVL<T>::updateHeight(Node<T>* node) {
	node->height =
			(getHeight(node->leftSon) > getHeight(node->rightSon)) ?
					getHeight(node->leftSon) : getHeight(node->rightSon) + 1;
}
/******************************************************************************/
/*Perform a right rotation to the given node*/
template<typename T>
Node<T>* AVL<T>::rotateRight(Node<T>* node) {
	if (!node) {
		return NULL;
	}
	Node<T>* temp = node->leftSon;
	node->leftSon = temp->rightSon;
	temp->rightSon = node;
	updateHeight(node);
	updateHeight(temp);
	return temp;
}
/******************************************************************************/
/*Perform a left rotation to the given node*/
template<typename T>
Node<T>* AVL<T>::rotateLeft(Node<T>* node) {
	if (!node) {
		return NULL;
	}
	Node<T>* temp = node->rightSon;
	node->rightSon = temp->leftSon;
	temp->leftSon = node;
	updateHeight(node);
	updateHeight(temp);
	return temp;
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::RR(Node<T>* node) {
	return rotateLeft(node);
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::LL(Node<T>* node) {
	return rotateRight(node);
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::LR(Node<T>* node) {
	if (node) {
		node->leftSon = rotateLeft(node->leftSon);
		node = rotateRight(node);
	}
	return node;
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::RL(Node<T>* node) {
	if (node) {
		node->rightSon = rotateRight(node->rightSon);
		node = rotateLeft(node);
	}
	return node;
}
/******************************************************************************/
/* Balancing the given node.*/
template<typename T>
Node<T>* AVL<T>::balance(Node<T>* node) {
	if (getBalanceFactor(node) == 2) {
		if (getBalanceFactor(node->leftSon) >= 0) {
			node = LL(node);
		} else if (getBalanceFactor(node->leftSon) == -1) {
			node = LR(node);
		}
	} else if (getBalanceFactor(node) == -2) {
		if (getBalanceFactor(node->rightSon) <= 0) {
			node = RR(node);
		} else if (getBalanceFactor(node->rightSon) == 1) {
			node = RL(node);
		}
	}
	return node;
}
/******************************************************************************/
/* Returns the pointer to the node with the minimal key int the tree which root-
 * is the passed node as an argument. */
template<typename T>
Node<T>* AVL<T>::aux_findMin(Node<T>* node) {
	return node->leftSon ? aux_findMin(node->leftSon) : node;
}
/******************************************************************************/
/* Removes the node wit the minimal key fro the tree which root is passed as an-
 * argument to the method*/
template<typename T>
Node<T>* AVL<T>::aux_removeMin(Node<T>* node) {
	if (!node->leftSon) {
		return node->rightSon;
	}
	node->leftSon = aux_removeMin(node->leftSon);
	return balance(node);
}
/******************************************************************************/
template<typename T>
MonitorResult AVL<T>::deleteNode(T key) {
	root = aux_deleteNode(root, key);
	--numOfNodes;
	return MEMORY_SUCCESS;
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::aux_deleteNode(Node<T>* node, T key) {
	if (!node) {
		return NULL;
	}
	if (key < node->key) {
		node->leftSon = aux_deleteNode(node->leftSon, key);
	} else if (key > node->key) {
		node->rightSon = aux_deleteNode(node->rightSon, key);
	} else {
		Node<T>* l = node->leftSon;
		Node<T>* r = node->rightSon;
		if ((l == NULL) || (r == NULL)) {
			Node<T>* temp = l ? l : r;
			if (temp == NULL) { //deleting a leaf.
				temp = node;
				node = NULL;
			} else { //deleting a node with one child.
				*node = *temp;
			}
		} else {
			Node<T>* temp = aux_findMin(node->rightSon);
			node->key = temp->key;
			node->rightSon = aux_deleteNode(node->rightSon, temp->key);
		}
	}
	if (node == NULL) {
		return node;
	}
	node->height = 1
			+ (getHeight(node->leftSon) >= getHeight(node->rightSon) ?
					getHeight(node->leftSon) : getHeight(node->rightSon));
	return balance(node);
}
/******************************************************************************/
template<typename T>
Node<T>* AVL<T>::aux_insert(Node<T>* node, T key) {
	if (!node) {
		try {
			return new Node<T>(key);
		} catch (std::bad_alloc& exc) {
			return NULL;
		}
	} else if (key < node->key) {
		node->leftSon = aux_insert(node->leftSon, key);
	} else if (key > node->key) {
		node->rightSon = aux_insert(node->rightSon, key);
	}
	node->height = (
			getHeight(node->leftSon) >= getHeight(node->rightSon) ?
					getHeight(node->leftSon) : getHeight(node->rightSon)) + 1;
	node = balance(node);
	return node;
}
/******************************************************************************/
/* Adds a new node with a given key to a tree which root is the given node.
 * If an allocation failure occurred, then it returns ALLOCATION_ERROR,
 * otherwise, SUCCESS. */
template<typename T>
MonitorResult AVL<T>::insert(T key) {
	root = aux_insert(root, key);
	if (!root) {
		return MEMORY_ERROR;
	}
	++numOfNodes;
	return MEMORY_SUCCESS;
}
/******************************************************************************/
/* This struct represent a node which key is not a single element, but a pair of
 * two elements. Example: a point coordination (x,y) is a key of 2 elements for
 * a single node.
 * This struct inherts from the 'Node' struct which I implemented earlier,
 * however, I overloaded the comparison operators.
 * Comparison between 2 pairs is done like this:
 * (a,b) > (x,y) IFF (a > x) OR ((a == x) AND (b > y)),
 * symmetrically, applies to '<'
 * (a,b) = (x,y) IFF (a == x) AND (b == y)
 */
template<typename T>
struct Pair {
	// Pair node: (keyLeft, keyRight)
	T keyLeft;
	T keyRight;
	//constructor:
	Pair(T keyL, T keyR) :
			keyLeft(keyL), keyRight(keyR) {
	}
	//operators:
	inline bool operator==(const Pair<T>& node);
	inline bool operator<(const Pair<T>& node);
	inline bool operator>(const Pair<T>& node);
	inline bool operator>=(const Pair<T>& node);
	inline bool operator<=(const Pair<T>& node);
};
/******************************************************************************/
template<typename T>
inline bool Pair<T>::operator==(const Pair<T>& node) {
	return ((this->keyLeft == node.keyLeft) && (this->keyRight == node.keyRight));
}
/******************************************************************************/
template<typename T>
inline bool Pair<T>::operator<(const Pair<T>& node) {
	return (this->keyLeft < node.keyLeft)
			|| ((this->keyLeft == node.keyLeft)
					&& (this->keyRight < node.keyRight));
}
/******************************************************************************/
template<typename T>
inline bool Pair<T>::operator>(const Pair<T>& node) {
	return (this->keyLeft > node.keyLeft)
			|| ((this->keyLeft == node.keyLeft)
					&& (this->keyRight > node.keyRight));
}
/******************************************************************************/
template<typename T>
inline bool Pair<T>::operator>=(const Pair<T>& node) {
	return !(*this < node);
}
/******************************************************************************/
template<typename T>
inline bool Pair<T>::operator<=(const Pair<T>& node) {
	return !(*this > node);
}
#endif /* AVL_H_ */
