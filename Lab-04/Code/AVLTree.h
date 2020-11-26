#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <iostream>

using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

// Initialize a NODE from a given value.
NODE* createNode(int data);

// Add a NODE with given value into a given AVL Tree.
// Notify if the given value existed.
void Insert(NODE* &pRoot, int x);

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void Remove(NODE* &pRoot, int x);

// Pre-order Traversal (key and height of NODE is required).
void NLR(NODE* pRoot);

// In-order Traversal (key and height of NODE is required).
void LNR(NODE* pRoot);

// Post-order Traversal (key and height of NODE is required).
void LRN(NODE* pRoot);

// Level-order Traversal (key and height of NODE is required).
void LevelOrder(NODE* pRoot);

// Determine if a given Binary Tree is an AVL Tree.
bool isAVL(NODE* pRoot);

// Completely remove a given AVL Tree.
void removeTree(NODE* &pRoot);

#endif
