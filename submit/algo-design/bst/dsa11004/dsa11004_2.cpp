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
void levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        } 
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
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
    levelOrder(root);
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
