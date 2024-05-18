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
    } else if (x < root->data) {
        root->left = buildTree(root->left, x);
    } 
    return root;
}
void leafBST(Node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
        } else {
            leafBST(root->left);
            leafBST(root->right);
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        root = buildTree(root, a[i]);
    }
    leafBST(root);
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
