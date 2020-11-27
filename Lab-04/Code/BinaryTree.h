#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

// Initialize a Node from a given value.
Node* createNode(int data);

// Pre-order Traversal.
void NLR(Node* root);

// In-order Traversal.
void LNR(Node* root);

// Post-order Traversal.
void LRN(Node* root);

// Level-order Traversal.
void LevelOrder(Node* root);

// Calculate the level of a given Binary Tree.
int Level(Node* root);

// Calculate the height of a given Binary Tree.
int Height(Node* root);

// Count the number of Node from a given Binary Tree.
int countNode(Node* root);

// Calculate the total value of all Nodes from a given Binary Tree.
int sumNode(Node* root);

// Calculate the height of a Node with given value. (return -1 if value not exist)
int heightNode(Node* root, int value);

// Calculate the level of a given Node.
int Level(Node* root, Node* p);

// Count the number leaves from a given Binary Tree.
int countLeaf(Node* root);

#endif
