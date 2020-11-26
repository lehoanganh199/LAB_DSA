#include "AVLTree.h"
#include <queue>

// Initialize a NODE from a given value.
NODE* createNode(int data) {
    NODE* p = new NODE;

    if (p) {
        p->key = data;
        p->p_left = p->p_right = nullptr;
        p->height = 1;
    }

    return p;
}

// Add a NODE with given value into a given AVL Tree.
// Notify if the given value existed.
void Insert(NODE* &pRoot, int x) {

}

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void Remove(NODE* &pRoot, int x) {

}

// Pre-order Traversal (key and height of NODE is required).
void NLR(NODE* pRoot) {
    if (pRoot) {
        cout << "(Key: " << pRoot->key
        << ", Height: " << pRoot->height << "), ";

        NLR(pRoot->p_left);
        NLR(pRoot->p_right);
    }
}

// In-order Traversal (key and height of NODE is required).
void LNR(NODE* pRoot) {
    if (pRoot) {
        LNR(pRoot->p_left);
        cout << "(Key: " << pRoot->key
        << ", Height: " << pRoot->height << "), ";
        LNR(pRoot->p_right);
    }
}

// Post-order Traversal (key and height of NODE is required).
void LRN(NODE* pRoot) {
    if (pRoot) {
        LRN(pRoot->p_left);
        LRN(pRoot->p_right);
        cout << "(Key: " << pRoot->key
        << ", Height: " << pRoot->height << "), ";
    }
}

// Level-order Traversal (key and height of NODE is required).
void LevelOrder(NODE* pRoot) {
    if (pRoot == nullptr)
        return;

    queue<NODE*> q;

    q.push(pRoot);
    while (!q.empty()) {
        NODE* node = q.front();
        cout << "(Key: " << node->key
        << ", Height: " << node->height << "), ";
        q.pop();

        if (node->p_left != nullptr)
            q.push(node->p_left);

        if (node->p_right != nullptr)
            q.push(node->p_right);
    }
}

// Determine if a given Binary Tree is an AVL Tree.
bool isAVL(NODE* pRoot) {
    if (pRoot == nullptr)
        return false;


    NODE* left = pRoot->p_left;
    NODE* right = pRoot->p_right;

    if (left == nullptr && right == nullptr)
        return true;

    int key = pRoot->key;

    if (left == nullptr) {
        if (key >= right->key || pRoot->height > 1)
            return false;
        return true;
    }
    if (right == nullptr) {
        if (key <= left->key || pRoot->height > 1)
            return false;
        return true;
    }

    int balanceFactor = abs(left->height - right->height);
    if (balanceFactor > 1 || key <= left->key || key >= right->key)
        return false;
    return isAVL(left) && isAVL(right);
}

// Completely remove a given AVL Tree.
void removeTree(NODE* &pRoot) {
    if (pRoot) {
        removeTree(pRoot->p_left);
        removeTree(pRoot->p_right);

        delete pRoot;
        pRoot = nullptr;
    }
}
