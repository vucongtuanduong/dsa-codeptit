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
void buildTree(Node *root, int u, int v, char x) {
    if (root != NULL) {
        if (root->data == u) {
            if (x == 'L') {
                root->left = new Node(v);

            } else {
                root->right = new Node(v);
            }
        } else {
            buildTree(root->left, u, v, x);
            buildTree(root->right, u, v , x);
        }
    }
}
int countLeaves(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}
bool sameLeafsLevel(Node *root) {
    return (countLeaves(root->left) == countLeaves(root->right));
}
void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    cin >> u >> v >> x;
    Node *root = new Node(u);
    buildTree(root, u, v, x);
    for (int i = 1;i < n; i++) {
        cin >> u >> v >> x;
        buildTree(root, u, v, x);

    }
    cout << sameLeafsLevel(root);
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
