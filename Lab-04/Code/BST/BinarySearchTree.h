#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"

// Find and return a Node with given value from a given Binary Search Tree.
Node* Search(Node* root, int x);

// Add a Node with given value into a given Binary Search Tree.
void Insert(Node* &root, int x);

// Remove a Node with given value from a given Binary Search Tree.
void Remove(Node* &root, int x);

// Initialize a Binary Search Tree from a given array.
Node* createTree(int a[], int n);

// Completely remove a given Binary Search Tree.
void removeTree(Node* &root);

// Count the number of Node from a given Binary Search Tree which key value
// is less than a given value.
int countLess(Node* root, int x);

// Count the number of Node from a given Binary Search Tree which key value
// is greater than a given value.
int countGreater(Node* root, int x);

// Determine if a given Binary Tree is Binary Search Tree.
bool isBST(Node* root);

// Determine if a given Binary Tree is a Full Binary Search Tree.
bool isFullBST(Node* root);

#endif
