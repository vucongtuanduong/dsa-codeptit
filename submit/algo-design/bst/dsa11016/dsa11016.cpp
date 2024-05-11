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
Node *createNode(Node *root, int value) {
    Node *new_node = new Node(value);
    return new_node;
}
Node *buildTree(Node *root, int value ) {
    if (root == NULL)  {
        return createNode(root, value);
    }
    if (value > root->data) {
        root->right =buildTree(root->right, value);
    } else if (value < root->data) {
        root->left = buildTree(root->left, value);
    } else {
        return root;
    }
    return root;
}
void LNR(Node *root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void testCase() {
    int n;
    cin >> n;
    Node *root = NULL;
    int u, v;
    char x;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root = buildTree(root, u);
        root = buildTree(root, v);
    }
    LNR(root);
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
