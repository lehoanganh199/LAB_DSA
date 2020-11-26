#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"

// Find and return a NODE with given value from a given Binary Search Tree.
NODE* Search(NODE* pRoot, int x);

// Add a NODE with given value into a given Binary Search Tree.
void Insert(NODE* &pRoot, int x);

// Remove a NODE with given value from a given Binary Search Tree.
void Remove(NODE* &pRoot, int x);

// Initialize a Binary Search Tree from a given array.
NODE* createTree(int a[], int n);

// Completely remove a given Binary Search Tree.
void removeTree(NODE* &pRoot);

// Count the number of NODE from a given Binary Search Tree which key value
// is less than a given value.
int countLess(NODE* pRoot, int x);

// Count the number of NODE from a given Binary Search Tree which key value
// is greater than a given value.
int countGreater(NODE* pRoot, int x);

// Determine if a given Binary Tree is Binary Search Tree.
bool isBST(NODE* pRoot);

// Determine if a given Binary Tree is a Full Binary Search Tree.
bool isFullBST(NODE* pRoot);

#endif
