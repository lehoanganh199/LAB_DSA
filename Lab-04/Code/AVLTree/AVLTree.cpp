#include "AVLTree.h"
#include <queue>

// --------------------------------------------------------
// Some functions to support.
// --------------------------------------------------------


// --------------------------------------------------------
// Declaration.
int calculateBalanceFactor(Node* root);
int heightNode(Node* root);
void insertImp(Node* &root, int x, bool &insertSuccessful);
void searchToDelete(Node* &p, Node* &q);
void removeImp(Node* &root, int x, bool &removeSuccessful);
// End of declaration.
// --------------------------------------------------------


// --------------------------------------------------------
// Implementation.
int calculateBalanceFactor(Node* root) {
    if (root == nullptr)
        return BALANCE;

    int heightSubTreeLeft = (root->left ? root->left->height : 0);
    int heightSubTreeRight = (root->right ? root->right->height : 0);
    return heightSubTreeRight - heightSubTreeLeft;
}

int heightNode(Node* root) {
    if (root == nullptr)
        return 0;

    int heightLeft = (root->left ? root->left->height : 0);
    int heighRight = (root->right ? root->right->height : 0);
    return max(heightLeft, heighRight) + 1;
}

void insertImp(Node* &root, int x, bool &insertSuccessful) {
    if (root) {
        if (root->key == x) {
            cout << "This value already exists." << endl;
        } else {
            if (root->key > x)
                insertImp(root->left, x, insertSuccessful);
            else
                insertImp(root->right, x, insertSuccessful);


            if (insertSuccessful) {
                root->height = heightNode(root);
                rebalanceTree(root);
            }
        }
    } else {
        root = createNode(x);
        insertSuccessful = true;
    }
}

void searchToDelete(Node* &p, Node* &q) {
    if (q->left) {
        searchToDelete(p, q->left);
        q->height = heightNode(q);

        rebalanceTree(q);
    } else {
        p->key = q->key;
        p = q;
        q = q->right;
    }
}

void removeImp(Node* &root, int x, bool &removeSuccessful) {
    if (root) {
        if (root->key == x) {
            Node* p = root;

            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            else
                searchToDelete(p, root->right);

            delete p;
            removeSuccessful = true;
        } else if (root->key > x) {
            removeImp(root->left, x, removeSuccessful);
        } else {
            removeImp(root->right, x, removeSuccessful);
        }

        if (removeSuccessful && root) {
            root->height = heightNode(root);
            rebalanceTree(root);
        }
    }
}
// End of implementation.
// --------------------------------------------------------




// --------------------------------------------------------
// Implement functions declared in AVLTree.h file.
// --------------------------------------------------------


// Initialize a Node from a given value.
Node* createNode(int data) {
    Node* p = new Node;

    if (p) {
        p->key = data;
        p->left = p->right = nullptr;
        p->height = 1;
    }

    return p;
}

// Add a Node with given value into a given AVL Tree.
// Notify if the given value existed.
void Insert(Node* &root, int x) {
    bool insertSuccessful = false;
    insertImp(root, x, insertSuccessful);
}

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void Remove(Node* &root, int x) {
    bool removeSuccessful = false;
    removeImp(root, x, removeSuccessful);
}

// Pre-order Traversal (key and height of Node is required).
void NLR(Node* root) {
    if (root) {
        cout << "(Key: " << root->key
        << ", Height: " << root->height << "), ";

        NLR(root->left);
        NLR(root->right);
    }
}

// In-order Traversal (key and height of Node is required).
void LNR(Node* root) {
    if (root) {
        LNR(root->left);
        cout << "(Key: " << root->key
        << ", Height: " << root->height << "), ";
        LNR(root->right);
    }
}

// Post-order Traversal (key and height of Node is required).
void LRN(Node* root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << "(Key: " << root->key
        << ", Height: " << root->height << "), ";
    }
}

// Level-order Traversal (key and height of Node is required).
void LevelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        cout << "(Key: " << node->key
        << ", Height: " << node->height << "), ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }
}

// Determine if a given Binary Tree is an AVL Tree.
bool isAVL(Node* root) {
    if (root == nullptr)
        return false;


    int balanceFactor = calculateBalanceFactor(root);
    if (abs(balanceFactor) > 1)
        return false;

    Node* left = root->left;
    Node* right = root->right;
    if (left == nullptr && right == nullptr)
        return true;

    int key = root->key;
    if (left == nullptr)
        return key < right->key;
    if (right == nullptr)
        return key > left->key;
    if (key <= left->key || key >= right->key)
        return false;


    return isAVL(left) && isAVL(right);
}

// Case: the right sub-tree is skewed right or balanced.
void rotateLeft(Node* &root) {
    if (root && root->right) {
        Node* right = root->right;

        // update height after rotate.
        int balanceFactor = calculateBalanceFactor(root->right);
        switch (balanceFactor) {
            case BALANCE:
                --(root->height);
                ++(right->height);
                break;
            case RIGHT_DEVIATION:
                root->height -= 2;
                break;
            default:
                break;
        }

        // rotate.
        root->right = right->left;
        right->left = root;
        root = right;
    }
}

// Case: the left sub-tree is skewed left or balanced.
void rotateRight(Node* &root) {
    if (root && root->left) {
        Node* left = root->left;

        // update height after rotate.
        int balanceFactor = calculateBalanceFactor(root->left);
        switch (balanceFactor) {
            case BALANCE:
                --(root->height);
                ++(left->height);
                break;
            case LEFT_DEVIATION:
                root->height -= 2;
                break;
            default:
                break;
        }

        // rotate.
        root->left = left->right;
        left->right = root;
        root = left;
    }
}

// Case: the left sub-tree is skewed right.
void rotateLeftRight(Node* &root) {
    if (root && root->left && root->left->right) {
        Node* T1 = root->left;
        Node* T2 = T1->right;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // rotate ==> sub-tree left.
        T1->right = T2->left;
        T2->left = T1;

        // rotate ==> sub-tree right.
        root->left = T2->right;
        T2->right = root;

        root = T2;
    }
}

// Case: the right sub-tree is skewed left.
void rotateRightLeft(Node* &root) {
    if (root && root->right && root->right->left) {
        Node* T1 = root->right;
        Node* T2 = T1->left;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // rotate ==> sub-tree left.
        T1->left = T2->right;
        T2->right = T1;

        // rotate ==> sub-tree right.
        root->right = T2->left;
        T2->left = root;

        root = T2;
    }
}

// Rebalanced the left sub-tree of the AVL tree.
void rebalanceLeft(Node* &root) {
    if (root && root->left) {
        int balanceFactor = calculateBalanceFactor(root->left);

        switch (balanceFactor) {
            case LEFT_DEVIATION:
            case BALANCE:
                rotateRight(root);
                break;
            case RIGHT_DEVIATION:
                rotateLeftRight(root);
                break;
            default:
                break;
        }
    }
}

// Rebalanced the right sub-tree of the AVL tree.
void rebalanceRight(Node* &root) {
    if (root && root->right) {
        int balanceFactor = calculateBalanceFactor(root->right);

        switch (balanceFactor) {
            case RIGHT_DEVIATION:
            case BALANCE:
                rotateLeft(root);
                break;
            case LEFT_DEVIATION:
                rotateRightLeft(root);
                break;
            default:
                break;
        }
    }
}

// Rebalanced the AVL tree.
void rebalanceTree(Node* &root) {
    int balanceFactor = calculateBalanceFactor(root);
    if (balanceFactor > RIGHT_DEVIATION) // right deviation.
        rebalanceRight(root);
    else if (balanceFactor < LEFT_DEVIATION) // left deviation.
        rebalanceLeft(root);
}

// Completely remove a given AVL Tree.
void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}
