#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

void NLR(Node* root) {
    if (root) {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
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

void searchToDelete(Node* &p, Node* &q) {
    if (q->left)
        searchToDelete(p, q->left);
    else {
        p->key = q->key;
        p = q;
        q = q->right;
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

vector<string> split(const string& haystack, const string& seperator,
    bool removeEmptyEntries = true) {

    vector<string> result;
    size_t start = 0, end;

    do {
        end = haystack.find(seperator, start);

        if (end == string::npos)
            end = haystack.length();

        result.push_back(haystack.substr(start, end - start));

        if (removeEmptyEntries)
            start = haystack.find_first_not_of(seperator, end);
        else
            start = seperator.length() + end;

    } while (end != haystack.length());

    return result;
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int sumNodeSameHeightAndGreaterKey(Node* root, int h, int x) {
    if (root == nullptr)
        return 0;

    if (root->key > x) {
        int heightCurrentKey = height(root);

        if (heightCurrentKey == h)
            return root->key;
        else if (heightCurrentKey > h)
            return sumNodeSameHeightAndGreaterKey(root->left, h, x) + sumNodeSameHeightAndGreaterKey(root->right, h, x);
        else
            return 0;
    }
    else
        return sumNodeSameHeightAndGreaterKey(root->right, h, x);
}

void removeGreaterNodeAndTwoChildrenAndDivisorOfM(Node* &root, int m, bool &removeSuccessful) {
    if (root == nullptr || removeSuccessful)
        return;

    removeGreaterNodeAndTwoChildrenAndDivisorOfM(root->right, m, removeSuccessful);

    if (m % root->key == 0) {
        Node* p = root;

        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
            searchToDelete(p, root->right);

        delete p;
        removeSuccessful = true;
        return;
    }

    removeGreaterNodeAndTwoChildrenAndDivisorOfM(root->left, m, removeSuccessful);
}

int main() {
    ifstream fin("/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Test-14-12-2020/input.txt");

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
        NLR(root);
        cout << endl << endl;


        // 2.
        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        tokens = split(data, " ");
        cout << sumNodeSameHeightAndGreaterKey(root, stoi(tokens[0]), stoi(tokens[1])) << endl << endl;


        // 3.
        getline(fin, data);
        if (data.back() == '\r')
            data.pop_back();
        int m = stoi(data);
        bool removeSuccessful = false;
        removeGreaterNodeAndTwoChildrenAndDivisorOfM(root, m, removeSuccessful);
        NLR(root);
        cout << endl;

        removeTree(root);
        fin.close();
    }

    return 0;
}
