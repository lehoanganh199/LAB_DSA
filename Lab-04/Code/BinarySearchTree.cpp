#include "BinarySearchTree.h"

// Find and return a NODE with given value from a given Binary Search Tree.
NODE* Search(NODE* pRoot, int x) {
	if (pRoot) {
		if (pRoot->key == x)
			return pRoot;
		if (pRoot->key > x)
			return Search(pRoot->p_left, x);
        return Search(pRoot->p_right, x);
	}

	return nullptr;
}

// Add a NODE with given value into a given Binary Search Tree.
void Insert(NODE* &pRoot, int x) {
    if (pRoot) {
    	if (pRoot->key == x)
        	return;
	    if (pRoot->key > x)
	        Insert(pRoot->p_left, x);
	    else
	        Insert(pRoot->p_right, x);
    }

    pRoot = createNode(x);
}

// Remove a NODE with given value from a given Binary Search Tree.
void Remove(NODE* &pRoot, int x) {
	if (pRoot) {
		if (pRoot->key == x) {
			NODE* p = pRoot;

			if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
				pRoot = nullptr;
			else if (pRoot->p_left == nullptr)
				pRoot = pRoot->p_right;
			else if (pRoot->p_right == nullptr)
				pRoot = pRoot->p_left;
			else {
				NODE* left = pRoot->p_left;
				
				while (left->p_right)
					left = left->p_right;

				left->p_right = pRoot->p_right;
				pRoot = pRoot->p_left;
			}

			delete p;
		}
	
		if (pRoot->key > x)
			Remove(pRoot->p_left, x);
        else 
        	Remove(pRoot->p_right, x);
	}
}

// Initialize a Binary Search Tree from a given array.
NODE* createTree(int a[], int n) {
	NODE* root = nullptr;

	for (int i = 0; i < n; i++) 
		Insert(root, a[i]);

	return root;
}

// Completely remove a given Binary Search Tree.
void removeTree(NODE* &pRoot) {
	if (pRoot) {
        removeTree(pRoot->p_left);
        removeTree(pRoot->p_right);
		
		delete pRoot;
		pRoot = nullptr;
	}
}

// Count the number of NODE from a given Binary Search Tree which key value
// is less than a given value.
int countLess(NODE* pRoot, int x) {
    if (pRoot) {
        if (pRoot->key <= x)
            return (pRoot->key < x ? 1 : 0) + countNode(pRoot->p_left);

        if (pRoot->key > x)
            return countLess(pRoot->p_left, x);
    }

	return 0;
}

// Count the number of NODE from a given Binary Search Tree which key value
// is greater than a given value.
int countGreater(NODE* pRoot, int x) {
    if (pRoot) {
        if (pRoot->key >= x)
            return (pRoot->key > x ? 1 : 0) + countNode(pRoot->p_left);

        if (pRoot->key < x)
            return countLess(pRoot->p_right, x);
    }

	return 0;
}

// Determine if a given Binary Tree is Binary Search Tree.
bool isBST(NODE* pRoot) {
	if (pRoot) {
		NODE* left = pRoot->p_left;
		NODE* right = pRoot->p_right;

		if (left == nullptr && right == nullptr)
			return true;

        int key = pRoot->key;

        if (left == nullptr) {
            if (key >= right->key)
                return false;
            return isBST(right);
        }
        if (right == nullptr) {
            if (key <= left->key)
                return false;
            return isBST(left);
        }


		if (key <= left->key || key >= right->key)
			return false;
        return isBST(left) && isBST(right);
	}

	return false;
}

// Determine if a given Binary Tree is a Full Binary Search Tree.
// The node is not a leaf must have left and right node.
bool isFullBST(NODE* pRoot) {
	if (pRoot) {
		NODE* left = pRoot->p_left;
		NODE* right = pRoot->p_right;

        if (left == nullptr && right == nullptr)
            return true;
		if (left == nullptr || right == nullptr)
			return false;

        int key = pRoot->key;

        if (key <= left->key || key >= right->key)
            return false;
        return isFullBST(left) && isFullBST(right);
	}

	return false;
}
