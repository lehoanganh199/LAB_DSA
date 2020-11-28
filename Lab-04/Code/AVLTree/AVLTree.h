#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <iostream>

using namespace std;

#define LEFT_DEVIATION     -1
#define BALANCE             0
#define RIGHT_DEVIATION     1

struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
};

// Initialize a Node from a given value.
Node* createNode(int data);

// Add a Node with given value into a given AVL Tree.
// Notify if the given value existed.
void Insert(Node* &root, int x);

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void Remove(Node* &root, int x);

// Pre-order Traversal (key and height of Node is required).
void NLR(Node* root);

// In-order Traversal (key and height of Node is required).
void LNR(Node* root);

// Post-order Traversal (key and height of Node is required).
void LRN(Node* root);

// Level-order Traversal (key and height of Node is required).
void LevelOrder(Node* root);

// Determine if a given Binary Tree is an AVL Tree.
bool isAVL(Node* root);

// Case: the right sub-tree is skewed right or balanced.
void rotateLeft(Node* &root);

// Case: the left sub-tree is skewed left or balanced.
void rotateRight(Node* &root);

// Case: the left sub-tree is skewed right.
void rotateLeftRight(Node* &root);

// Case: the right sub-tree is skewed left.
void rotateRightLeft(Node* &root);

// Rebalanced the left sub-tree of the AVL tree.
void rebalanceLeft(Node* &root);

// Rebalanced the right sub-tree of the AVL tree.
void rebalanceRight(Node* &root);

// Rebalanced the AVL tree.
void rebalanceTree(Node* &root);

// Completely remove a given AVL Tree.
void removeTree(Node* &root);

#endif
