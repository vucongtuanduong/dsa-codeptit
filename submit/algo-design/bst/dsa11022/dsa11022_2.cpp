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
    } else {
        if (x > root->data) {
            root->right = buildTree(root->right, x);
        } else {
            root->left = buildTree(root->left, x);
        }
    }
    return root;
}
void parentNode(Node *root, int &count) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            count--;
        }
        parentNode(root->left, count);
        parentNode(root->right, count);
    }
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        root = buildTree(root, a[i]);
    }
    int count = n;
    parentNode(root, count);
    cout << count;


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
