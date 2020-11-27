#include "AVLTree.h"
#include <queue>

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

void InsertImp(Node* &root, int x, bool &insertSuccessful) {
    if (root) {
        if (root->key == x) {
            cout << "This value already exists." << endl;
        } else {
            if (root->key > x)
                InsertImp(root->left, x, insertSuccessful);
            else
                InsertImp(root->right, x, insertSuccessful);


            if (insertSuccessful) {
                root->height = heightNode(root);

                int balanceFactor = calculateBalanceFactor(root);
                switch (balanceFactor) {
                    case LEFT_DEVIATION:
                        rebalanceLeft(root);
                        break;
                    case RIGHT_DEVIATION:
                        rebalanceRight(root);
                        break;
                    default:
                        break;
                }
            }
        }
    } else {
        root = createNode(x);
        insertSuccessful = true;
    }
}

// Add a Node with given value into a given AVL Tree.
// Notify if the given value existed.
void Insert(Node* &root, int x) {
    bool insertSuccessful = false;
    InsertImp(root, x, insertSuccessful);
}

void searchToDelete(Node* &p, Node* &q) {
    if (q->left) {
        searchToDelete(p, q->left);
        q->height = heightNode(q);
    } else {
        p->key = q->key;
        p->height = q->height;
        p = q;
        q = q->right;
    }
}

void RemoveImp(Node* &root, int x, bool &removeSuccessful) {
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
            removeSuccessful = true;
        } else {
            if (root->key > x)
                RemoveImp(root->left, x, removeSuccessful);
            else
                RemoveImp(root->right, x, removeSuccessful);


            if (removeSuccessful) {
                root->height = heightNode(root);

                int balanceFactor = calculateBalanceFactor(root);
                switch (balanceFactor) {
                    case LEFT_DEVIATION:
                        rebalanceLeft(root);
                        break;
                    case RIGHT_DEVIATION:
                        rebalanceRight(root);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

// Remove a Node with given value from a given AVL Tree.
// Notify if the given value not existed.
void Remove(Node* &root, int x) {
    bool removeSuccessful = false;
    RemoveImp(root, x, removeSuccessful);
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


    Node* left = root->left;
    Node* right = root->right;

    if (left == nullptr && right == nullptr)
        return true;

    int key = root->key;

    if (left == nullptr) {
        if (key >= right->key || root->height > 1)
            return false;
        return true;
    }
    if (right == nullptr) {
        if (key <= left->key || root->height > 1)
            return false;
        return true;
    }

    int balanceFactor = abs(left->height - right->height);
    if (balanceFactor > 1 || key <= left->key || key >= right->key)
        return false;
    return isAVL(left) && isAVL(right);
}

void rotateLeft(Node* &root) {
    if (root && root->right) {
        Node* right = root->right;

        int balanceFactor = calculateBalanceFactor(root);
        if (balanceFactor == RIGHT_DEVIATION) {
            ++(root->height);
            ++(right->height);
        }

        root->right = right->left;
        right->left = root;
        root = right;
    }
}

void rotateRight(Node* &root) {
    if (root && root->left) {
        Node* left = root->left;

        int balanceFactor = calculateBalanceFactor(root);
        if (balanceFactor == LEFT_DEVIATION) {
            ++(root->height);
            ++(left->height);
        }

        root->left = left->right;
        left->right = root;
        root = left;
    }
}

void rotateLeftRight(Node* &root) {
    if (root && root->left && root->right) {
        Node* T1 = root->left;
        Node* T2 = T1->right;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // sub-tree left.
        T1->right = T2->left;
        T2->left = T1;

        // sub-tree right.
        root->left = T2->right;
        T2->right = root;

        root = T2;
    }
}

void rotateRightLeft(Node* &root) {
    if (root && root->right && root->right->left) {
        Node* T1 = root->right;
        Node* T2 = T1->left;

        // update height after rotate.
        --(T1->height);
        ++(T2->height);
        root->height -= 2;

        // sub-tree left.
        T1->left = T2->right;
        T2->right = T1;

        // sub-tree right.
        root->right = T2->left;
        T2->left = root;

        root = T2;
    }
}

void rebalanceLeft(Node* &root) {
    if (root && root->left) {
        int balanceFactor = calculateBalanceFactor(root->left);

        switch (balanceFactor) {
            case LEFT_DEVIATION:
                rotateRight(root);
                break;
            case BALANCE:
                rotateRight(root);
                break;
            case RIGHT_DEVIATION:
                rotateRightLeft(root);
                break;
            default:
                break;
        }
    }
}

void rebalanceRight(Node* &root) {
    if (root && root->right) {
        int balanceFactor = calculateBalanceFactor(root->right);

        switch (balanceFactor) {
            case RIGHT_DEVIATION:
                rotateLeft(root);
                break;
            case BALANCE:
                rotateLeft(root);
                break;
            case LEFT_DEVIATION:
                rotateLeftRight(root);
                break;
            default:
                break;
        }
    }
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
