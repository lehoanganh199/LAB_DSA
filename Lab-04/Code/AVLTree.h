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

int calculateBalanceFactor(Node* root);

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

void rotateLeft(Node* &root);

void rotateRight(Node* &root);

void rotateLeftRight(Node* &root);

void rotateRightLeft(Node* &root);

void rebalanceLeft(Node* &root);

void rebalanceRight(Node* &root);

// Completely remove a given AVL Tree.
void removeTree(Node* &root);

#endif
