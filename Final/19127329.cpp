#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#define LEFT_DEVIATION     -1
#define BALANCE             0
#define RIGHT_DEVIATION     1

using namespace std;

enum Direction { LEFT, RIGHT };

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int data);

void LRN(Node* root);

void insert(Node* &root, int x);
void insertImp(Node* &root, int x, bool &insertSuccessful);

int calculateBalanceFactor(Node* root);
int heightOfNode(Node* root);

void rotateLeft(Node* &root);
void rotateRight(Node* &root);
void rotateLeftRight(Node* &root);
void rotateRightLeft(Node* &root);
void rebalanceLeft(Node* &root);
void rebalanceRight(Node* &root);
void rebalanceTree(Node* &root);

void removeTree(Node* &root);

vector<string> split(const string& str, const string& separator, bool removeEmptyEntries = true);

void findAllNodesHasSumAllDescendantsLessThanA(Node* root, vector<int> &result, int a);

int sumAllNodes(Node* root);
void searchToDelete(Node* &p, Node* &q);
void removeNode(Node* &root, bool &removeSuccessful);

int main() {
    string filename = "/Users/lehoanganh/Desktop/final/final/input.txt";
    ifstream fin(filename);

    if (!fin.is_open())
        cout << "Can't not open file. Please check the path." << endl;
    else {
        string data;

        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        int numberOfNodes = stoi(data);

        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        vector<string> tokens = split(data, " ");

        Node* root = nullptr;
        for (int i = 0; i < numberOfNodes; i++)
            insert(root, stoi(tokens[i]));

        LRN(root);
        cout << endl;

        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        int a = stoi(data);

        vector<int> result;
        findAllNodesHasSumAllDescendantsLessThanA(root, result, a);
        sort(result.rbegin(), result.rend());
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;

        bool removeSuccessful = false;
        removeNode(root, removeSuccessful);
        LRN(root);
        cout << endl;

        fin.close();
    }

    return 0;
}

Node* createNode(int data) {
    Node* p = new Node;

    if (p) {
        p->key = data;
        p->left = p->right = nullptr;
        p->height = 1;
    }

    return p;
}

void LRN(Node* root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

void insert(Node* &root, int x) {
    bool insertSuccessful = false;
    insertImp(root, x, insertSuccessful);
}

void insertImp(Node* &root, int x, bool &insertSuccessful) {
    if (root) {
        if (root->key == x)
            return;
        else {
            if (root->key > x)
                insertImp(root->left, x, insertSuccessful);
            else
                insertImp(root->right, x, insertSuccessful);


            if (insertSuccessful) {
                root->height = heightOfNode(root);
                rebalanceTree(root);
            }
        }
    } else {
        root = createNode(x);
        insertSuccessful = true;
    }
}

int calculateBalanceFactor(Node* root) {
    if (root == nullptr)
        return BALANCE;

    int heightSubTreeLeft = (root->left ? root->left->height : 0);
    int heightSubTreeRight = (root->right ? root->right->height : 0);
    return heightSubTreeRight - heightSubTreeLeft;
}

int heightOfNode(Node* root) {
    if (root == nullptr)
        return 0;

    int heightLeft = (root->left ? root->left->height : 0);
    int heighRight = (root->right ? root->right->height : 0);
    return max(heightLeft, heighRight) + 1;
}

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

void rebalanceTree(Node* &root) {
    int balanceFactor = calculateBalanceFactor(root);
    if (balanceFactor > RIGHT_DEVIATION) // right deviation.
        rebalanceRight(root);
    else if (balanceFactor < LEFT_DEVIATION) // left deviation.
        rebalanceLeft(root);
}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}

vector<string> split(const string& str, const string& separator, bool removeEmptyEntries) {
    vector<string> result;
    size_t start = 0, end;

    do {
        end = str.find(separator, start);

        if (end == string::npos)
            end = str.length();

        result.push_back(str.substr(start, end - start));

        if (removeEmptyEntries)
            start = str.find_first_not_of(separator, end);
        else
            start = separator.length() + end;

    } while (end != str.length() && start != string::npos);

    return result;
}

void findAllNodesHasSumAllDescendantsLessThanA(Node* root, vector<int> &result, int a) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    int sum = sumAllNodes(root) - root->key;
    if (sum < a)
        result.push_back(root->key);

    if (root->left)
        findAllNodesHasSumAllDescendantsLessThanA(root->left, result, a);
    if (root->right)
        findAllNodesHasSumAllDescendantsLessThanA(root->right, result, a);
}

int sumAllNodes(Node* root) {
    int sum = 0;

    if (root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            sum += node->key;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return sum;
}

void searchToDelete(Node* &p, Node* &q) {
    if (q->right ) {
        searchToDelete(p, q->right);
        q->height = heightOfNode(q);

        rebalanceTree(q);
    } else {
        p->key = q->key;
        p = q;
        q = q->left;
    }
}

void removeNode(Node* &root, bool &removeSuccessful) {
    if (root == nullptr)
        return;

    if (removeSuccessful && root) {
        root->height = heightOfNode(root);
        rebalanceTree(root);
    }

    removeNode(root->right, removeSuccessful);

    if (!removeSuccessful && root->left && root->right && (root->right->key % root->left->key == 0)) {
        Node* p = root;

        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
            searchToDelete(p, root->left);

        delete p;
        removeSuccessful = true;

        root->height = heightOfNode(root);
        rebalanceTree(root);

        return;
    }

    removeNode(root->left, removeSuccessful);
}
