#include "BinarySearchTree.h"
#include <queue>

// Initialize a NODE from a given value.
NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->p_left = p->p_right = nullptr;

    return p;
}

// Pre-order Traversal.
void NLR(NODE* pRoot) {
	if (pRoot) {
		cout << pRoot->key << " ";
		NLR(pRoot->p_left);
		NLR(pRoot->p_right);
	}
}

// In-order Traversal.
void LNR(NODE* pRoot) {
	if (pRoot) {
        LNR(pRoot->p_left);
		cout << pRoot->key << " ";
        LNR(pRoot->p_right);
	}
}

// Post-order Traversal.
void LRN(NODE* pRoot) {
	if (pRoot) {
        LRN(pRoot->p_left);
        LRN(pRoot->p_right);
		cout << pRoot->key << " ";
	}
}

// Print all nodes of a specify level of Binary Tree.
void specifyLevelOrder(NODE* pRoot, int level) {
	if (pRoot == nullptr)
		return;

	if (level == 0)
		cout << pRoot->key << " ";
	else {
		specifyLevelOrder(pRoot->p_left, level - 1);
		specifyLevelOrder(pRoot->p_right, level - 1);
	}
}

// Level-order Traversal.
// Print all value of nodes from left to right by each level.
// Reference: https://www.geeksforgeeks.org/level-order-tree-traversal/
void LevelOrder(NODE* pRoot) {
    // Uses the function to print each specify level.
    // Time complexity: .
    // Space complexity: O(n).

//    int level = Level(pRoot);
//    for (int i = 0; i <= level; i++)
//        specifyLevelOrder(pRoot, i);


	// -------------------------------


    // Uses the queue structure.
    // Time complexity: O(n).
    // Space complexity: O(n).

     if (pRoot == nullptr)
         return;

     queue<NODE*> q;

     q.push(pRoot);
     while (!q.empty()) {
         NODE* node = q.front();
         cout << node->key << " ";
         q.pop();

         if (node->p_left != nullptr)
             q.push(node->p_left);

         if (node->p_right != nullptr)
             q.push(node->p_right);
     }
}

// Calculate the level of a given Binary Tree.
int Level(NODE* pRoot) {
	return Height(pRoot) - 1;
}

// Calculate the height of a given Binary Tree.
int Height(NODE* pRoot) {
	if (pRoot == nullptr)
		return 0;

	return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}

// Count the number of NODE from a given Binary Tree.
int countNode(NODE* pRoot) {
	if (pRoot == nullptr)
		return 0;

	return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}

// Calculate the total value of all NODEs from a given Binary Tree.
int sumNode(NODE* pRoot) {
	if (pRoot == nullptr)
		return 0;

	return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}

// Calculate the height of a NODE with given value. (return -1 if value not exist)
// The number of nodes in the longest path to node leaf.
int heightNode(NODE* pRoot, int value) {
	NODE* p = Search(pRoot, value);
	return p ? Height(p) : -1;
}

// Calculate the level of a given NODE.
int Level(NODE* pRoot, NODE* p) {
	if (p == nullptr || Search(pRoot, p->key) == nullptr)
        return -1;

    if (pRoot->key == p->key)
        return 0;
    if (pRoot->key > p->key)
        return 1 + Level(pRoot->p_left, p);
    else
        return 1 + Level(pRoot->p_right, p);
}

// Count the number leaves from a given Binary Tree.
int countLeaf(NODE* pRoot) {
	if (pRoot == nullptr)
		return 0;
	if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
		return 1;

	return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}
