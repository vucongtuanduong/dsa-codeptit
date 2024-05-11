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
int countNodes(Node *root, int count) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            return count - 1;
        }
        count = countNodes(root->left, count);
        count = countNodes(root->right, count);
    }
    return count;
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

    cout << countNodes(root, n);
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
