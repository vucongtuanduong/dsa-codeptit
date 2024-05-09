#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};
void buildTree(Node *root, int u, int v, char x) {
    if (root != NULL) {
        if (root->data == u) {
            if (x == 'L') {
                root->left = new Node(v);
            } else {
                root->right = new Node(v);
            }
        }
        buildTree(root->left, u, v, x);
        buildTree(root->right, u, v, x);
    }
}
int countLeaf(Node *root) {
    if (root == NULL) {
        return 0;
    } 
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return (countLeaf(root->left) + countLeaf(root->right));
}
bool sameLevelLeaf(Node *root) {
    return (countLeaf(root->left) == countLeaf(root->right));
}
void testCase() {
    int n;
    cin >> n;
    int u, v;
    char d;
    cin >> u >> v >> d;
    Node *root = new Node(u);
    buildTree(root, u, v, d);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> d;
        buildTree(root, u, v, d);
    }
    cout << sameLevelLeaf(root);
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
