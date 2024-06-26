#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};
Node *buildTree(Node *root, int x) {
    if (root == NULL) {
        return new Node(x);
    } 
    if (x > root->data) {
        root->right = buildTree(root->right, x);
    } else {
        root->left = buildTree(root->left, x);
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
    int u, v;
    char x;
    cin >> u >> v >> x;
    Node *root = new Node(u);
    root = buildTree(root, v);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        buildTree(root, v);
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
