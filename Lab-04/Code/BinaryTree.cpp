#include "BinarySearchTree.h"
#include <queue>

// Initialize a Node from a given value.
Node* createNode(int data) {
	Node* p = new Node;
	p->key = data;
	p->left = p->right = nullptr;

    return p;
}

// Pre-order Traversal.
void NLR(Node* root) {
	if (root) {
		cout << root->key << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

// In-order Traversal.
void LNR(Node* root) {
	if (root) {
        LNR(root->left);
		cout << root->key << " ";
        LNR(root->right);
	}
}

// Post-order Traversal.
void LRN(Node* root) {
	if (root) {
        LRN(root->left);
        LRN(root->right);
		cout << root->key << " ";
	}
}

// Print all nodes of a specify level of Binary Tree.
void specifyLevelOrder(Node* root, int level) {
	if (root == nullptr)
		return;

	if (level == 0)
		cout << root->key << " ";
	else {
		specifyLevelOrder(root->left, level - 1);
		specifyLevelOrder(root->right, level - 1);
	}
}

// Level-order Traversal.
// Print all value of nodes from left to right by each level.
// Reference: https://www.geeksforgeeks.org/level-order-tree-traversal/
void LevelOrder(Node* root) {
    // Uses the function to print each specify level.
    // Time complexity: .
    // Space complexity: O(n).

//    int level = Level(root);
//    for (int i = 0; i <= level; i++)
//        specifyLevelOrder(root, i);


	// -------------------------------


    // Uses the queue structure.
    // Time complexity: O(n).
    // Space complexity: O(n).

     if (root == nullptr)
         return;

     queue<Node*> q;

     q.push(root);
     while (!q.empty()) {
         Node* node = q.front();
         cout << node->key << " ";
         q.pop();

         if (node->left != nullptr)
             q.push(node->left);

         if (node->right != nullptr)
             q.push(node->right);
     }
}

// Calculate the level of a given Binary Tree.
int Level(Node* root) {
	return Height(root) - 1;
}

// Calculate the height of a given Binary Tree.
int Height(Node* root) {
	if (root == nullptr)
		return 0;

	return 1 + max(Height(root->left), Height(root->right));
}

// Count the number of Node from a given Binary Tree.
int countNode(Node* root) {
	if (root == nullptr)
		return 0;

	return 1 + countNode(root->left) + countNode(root->right);
}

// Calculate the total value of all Nodes from a given Binary Tree.
int sumNode(Node* root) {
	if (root == nullptr)
		return 0;

	return root->key + sumNode(root->left) + sumNode(root->right);
}

// Calculate the height of a Node with given value. (return -1 if value not exist)
// The number of nodes in the longest path to node leaf.
int heightNode(Node* root, int value) {
	Node* p = Search(root, value);
	return p ? Height(p) : -1;
}

// Calculate the level of a given Node.
int Level(Node* root, Node* p) {
	if (p == nullptr || Search(root, p->key) == nullptr)
        return -1;

    if (root->key == p->key)
        return 0;
    if (root->key > p->key)
        return 1 + Level(root->left, p);
    else
        return 1 + Level(root->right, p);
}

// Count the number leaves from a given Binary Tree.
int countLeaf(Node* root) {
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;

	return countLeaf(root->left) + countLeaf(root->right);
}
