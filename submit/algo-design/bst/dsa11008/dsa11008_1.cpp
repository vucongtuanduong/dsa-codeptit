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
//recursion result in large memory and slower time
Node * buildTree(Node *root, int u, int v, char x) {
    if (root == NULL) {
        root = new Node(u);
    }
    if (root != NULL) {
        if (root->data == u) {
            if (x == 'L') {
                root->left = new Node(v);
            } else {
                root->right = new Node(v);
            }
        } else {
            buildTree(root->left, u, v, x);
            buildTree(root->right, u, v, x);
        }
    }
    return root;
}
//build tree without recursion
void buildTree1(Node *root, int u, int v, char x) {
    if (root != NULL) {
        if (root->data == u) {
            if (x == 'L') {
                root->left = new Node(v);
            } else {
                root->right = new Node(v);
            }
        } else {
            buildTree1(root->left, u, v, x);
            buildTree1(root->right, u, v, x);
        }
    }
}
int countLeafs(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL ) {
        return 1;
    }
    return countLeafs(root->left) + countLeafs(root->right);
}
bool sameLevelLeafs(Node *root) {
    return (countLeafs(root->left) == countLeafs(root->right));
}

//testCase2 function not using recursion to buildTree
void testCase2() {
    int n;
    cin >> n;
    int u, v;
    char x;
    cin >> u >> v >> x;
    Node *root = new Node(u);
    buildTree(root, u, v, x);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        buildTree(root, u, v, x);
    }
    cout << sameLevelLeafs(root);
}
void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root = buildTree(root, u, v, x);
    }
    cout << sameLevelLeafs(root);
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
