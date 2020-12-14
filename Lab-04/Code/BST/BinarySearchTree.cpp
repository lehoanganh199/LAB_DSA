#include "BinarySearchTree.h"

// This function to find an element to replacement the removed element (p).
// Case: p have two sub-tree.
void searchToDelete(Node* &p, Node* &q);
void searchToDelete(Node* &p, Node* &q) {
    if (q->left)
        searchToDelete(p, q->left);
    else {
        p->key = q->key;
        p = q;
        q = q->right;
    }
}

// Find and return a Node with given value from a given Binary Search Tree.
Node* Search(Node* root, int x) {
    while (root) {
        if (root->key == x)
            return root;
        if (root->key > x)
            root = root->left;
        else
            root = root->right;
    }

    return nullptr;
}

// Add a Node with given value into a given Binary Search Tree.
void Insert(Node* &root, int x) {
    // Uses recursive.
    if (root) {
        if (root->key == x)
            return;
        if (root->key > x)
            Insert(root->left, x);
        else
            Insert(root->right, x);
    } else {
        root = createNode(x);
    }


    // Uses loop.
    //    if (root == nullptr) {
    //        root = createNode(x);
    //        return;
    //    }
    //
    //    Node* p = root;
    //    while (p) {
    //        if (p->key == x)
    //            return;
    //        if (p->key > x) {
    //            if (p->left == nullptr) {
    //                p->left = createNode(x);
    //                return;
    //            }
    //
    //            p = p->left;
    //        } else {
    //            if (p->right == nullptr) {
    //                p->right = createNode(x);
    //                return;
    //            }
    //
    //            p = p->right;
    //        }
    //    }
}

// Remove a Node with given value from a given Binary Search Tree.
void Remove(Node* &root, int x) {
    if (root) {
        if (root->key == x) {
            Node* p = root;

            if (root->left == nullptr && root->right == nullptr)
                root = nullptr;
            else if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            else
                searchToDelete(p, root->right);

            delete p;
        }

        if (root->key > x)
            Remove(root->left, x);
        else
            Remove(root->right, x);
    }
}

// Initialize a Binary Search Tree from a given array.
Node* createTree(int a[], int n) {
    Node* root = nullptr;

    for (int i = 0; i < n; i++)
        Insert(root, a[i]);

    return root;
}

// Completely remove a given Binary Search Tree.
void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}

// Count the number of Node from a given Binary Search Tree which key value
// is less than a given value.
int countLess(Node* root, int x) {
    if (root) {
        if (root->key <= x)
            return (root->key < x ? 1 : 0) + countNode(root->left);

        if (root->key > x)
            return countLess(root->left, x);
    }

    return 0;
}

// Count the number of Node from a given Binary Search Tree which key value
// is greater than a given value.
int countGreater(Node* root, int x) {
    if (root) {
        if (root->key >= x)
            return (root->key > x ? 1 : 0) + countNode(root->left);

        if (root->key < x)
            return countLess(root->right, x);
    }

    return 0;
}

// Determine if a given Binary Tree is Binary Search Tree.
bool isBST(Node* root) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;

        if (left == nullptr && right == nullptr)
            return true;

        int key = root->key;
        if (left == nullptr) 
            return key >= right->key ? false : isBST(right);
        if (right == nullptr)
            return key <= right->key ? false : isBST(left);
        if (key <= left->key || key >= right->key)
            return false;

        return isBST(left) && isBST(right);
    }

    return false;
}

// Determine if a given Binary Tree is a Full Binary Search Tree.
// The node is not a leaf must have left and right node.
bool isFullBST(Node* root) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;

        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        int key = root->key;

        if (key <= left->key || key >= right->key)
            return false;
        return isFullBST(left) && isFullBST(right);
    }

    return false;
}
