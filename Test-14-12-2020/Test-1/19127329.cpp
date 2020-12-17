#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* p = new Node;
    p->key = data;
    p->left = p->right = nullptr;

    return p;
}

void LRN(Node* root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

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

int LevelOfNode(Node* root, Node* p) {
    if (p == nullptr || Search(root, p->key) == nullptr)
        return -1;

    if (root->key == p->key)
        return 1;
    if (root->key > p->key)
        return 1 + LevelOfNode(root->left, p);
    else
        return 1 + LevelOfNode(root->right, p);
}

void Insert(Node* &root, int x) {
    if (root) {
        if (root->key == x)
            return;
        if (root->key > x)
            Insert(root->left, x);
        else
            Insert(root->right, x);
    }
    else
        root = createNode(x);
}

int countNodeDivisibleB(Node* root, int b) {
    if (root == nullptr)
        return 0;

    int count = 0;
    if (root->key % b == 0)
        count = 1;

    return count + countNodeDivisibleB(root->left, b) + countNodeDivisibleB(root->right, b);
}

void searchToDelete(Node* &p, Node* &q) {
    if (q->right)
        searchToDelete(p, q->right);
    else {
        p->key = q->key;
        p = q;
        q = q->left;
    }
}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);

        delete root;
        root = nullptr;
    }
}

vector<string> split(const string& haystack, const string& separator,
    bool removeEmptyEntries = true) {

    vector<string> result;
    size_t start = 0, end;

    do {
        end = haystack.find(separator, start);

        if (end == string::npos)
            end = haystack.length();

        result.push_back(haystack.substr(start, end - start));

        if (removeEmptyEntries)
            start = haystack.find_first_not_of(separator, end);
        else
            start = separator.length() + end;

    } while (end != haystack.length() && start != string::npos);

    return result;
}

int countChildOfNodeHasValueAAndDivisibleB(Node* root, int a, int b) {
    if (root == nullptr)
        return 0;

    Node* p = Search(root, a);
    return p == nullptr ? 0 : countNodeDivisibleB(p->left, b) + countNodeDivisibleB(root->right, b);
}

bool hasTwoChildren(Node* p) {
    return p->left && p->right;
}

void removeNodeHasTwoChildrenLevelK(Node* originRoot, Node* &root, int k, bool &removeSuccessful) {
    if (root == nullptr || removeSuccessful)
        return;

    removeNodeHasTwoChildrenLevelK(originRoot, root->right, k, removeSuccessful);

    if (hasTwoChildren(root) && LevelOfNode(originRoot, root->left) == k && LevelOfNode(originRoot, root->right) == k) {
        Node* p = root;

        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
            searchToDelete(p, root->left);

        delete p;
        removeSuccessful = true;
    }

    if (removeSuccessful)
        return;

    removeNodeHasTwoChildrenLevelK(originRoot, root->left, k, removeSuccessful);
}

int main() {
    ifstream fin("/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Test-14-12-2020/Test-1/input.txt");

    if (fin) {
        string data;
        getline(fin, data);

        if (data.back() == '\r')
            data.pop_back();

        vector<string> tokens = split(data, " ");
        Node* root = nullptr;

        for (int i = 0; i < tokens.size() - 1; i++)
            Insert(root, stoi(tokens[i]));

        size_t lastIndex = tokens.size() - 1;
        if (tokens[lastIndex].back() == '.')
            tokens[lastIndex].pop_back();
        Insert(root, stoi(tokens[lastIndex]));


        // 1.
        LRN(root);
        cout << endl << endl;


        // 2.
        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        tokens = split(data, " ");
        cout << countChildOfNodeHasValueAAndDivisibleB(root, stoi(tokens[0]), stoi(tokens[1])) << endl << endl;


        // 3.
        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        int k = stoi(data);
        bool removeSuccessful = false;
        removeNodeHasTwoChildrenLevelK(root, root, k, removeSuccessful);
        LRN(root);
        cout << endl;


        removeTree(root);
        fin.close();
    }

    return 0;
}
