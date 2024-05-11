#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

Node *buildTree(Node *root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value > root->data) {
        root->right = buildTree(root->right, value);
    }  else {
        root->left = buildTree(root->left, value);
    }
    return root;
}

int treeHeight(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftRes = treeHeight(root->left);
        int rightRes = treeHeight(root->right);
        return max(leftRes, rightRes) + 1;
    }
}

void testCase() {
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = buildTree(root, x);
    }

    cout << treeHeight(root) - 1; // Subtract 1 because the root node is not counted in the depth
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}