#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        string key;
        Node *left;
        Node *right;


        Node (string key) {
            this->key = key;
            left = right = NULL;
        }
        
};

const string operations = "+-*/";
vector<string> input;
int n;
int calTree(Node *root) {
    if (operations.find(root->key[0]) == -1) {
        return stoi(root->key);
    } else {
        if (root->key[0] == '+') {
            return calTree(root->left) + calTree(root->right);
        } else if (root->key[0] == '-') {
            return calTree(root->left) - calTree(root->right);
        } else if(root->key[0] == '*') {
            return calTree(root->left) * calTree(root->right);
        } else {
            return calTree(root->left) / calTree(root->right);
        }
    }
}
void printInOrder(Node *root) {
    if (root == NULL) {
        return;
    } 
    printInOrder(root->left);
    cout << root->key;
    printInOrder(root->right);
}
Node *buildTree(Node *root, int i) {
    
    if (i < n) {
        root = new Node(input[i]);
        root->left = buildTree(root, i * 2 + 1);
        root->right = buildTree(root, i * 2 + 2);
    }
    return root;
}

void testCase() {
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    Node *root = NULL;
    root = buildTree(root, 0);
    cout << calTree(root);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
