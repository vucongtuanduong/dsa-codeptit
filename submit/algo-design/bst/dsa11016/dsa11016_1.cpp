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
void buildTree(Node *root, int x) {
    if (root == NULL) {
        root = new Node(x);
    } else {
        if (x > root->data) {
            buildTree(root->right, x);
        } else {
            buildTree(root->left, x);
        }
    }
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
    buildTree(root, v);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        buildTree(root, v);

    }
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
