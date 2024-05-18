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
void LRN(Node *root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
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
    LRN(root);
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
