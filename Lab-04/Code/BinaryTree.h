#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};

// Initialize a NODE from a given value.
NODE* createNode(int data);

// Pre-order Traversal.
void NLR(NODE* pRoot);

// In-order Traversal.
void LNR(NODE* pRoot);

// Post-order Traversal.
void LRN(NODE* pRoot);

// Level-order Traversal.
void LevelOrder(NODE* pRoot);

// Calculate the level of a given Binary Tree.
int Level(NODE* pRoot);

// Calculate the height of a given Binary Tree.
int Height(NODE* pRoot);

// Count the number of NODE from a given Binary Tree.
int countNode(NODE* pRoot);

// Calculate the total value of all NODEs from a given Binary Tree.
int sumNode(NODE* pRoot);

// Calculate the height of a NODE with given value. (return -1 if value not exist)
int heightNode(NODE* pRoot, int value);

// Calculate the level of a given NODE.
int Level(NODE* pRoot, NODE* p);

// Count the number leaves from a given Binary Tree.
int countLeaf(NODE* pRoot);

#endif
