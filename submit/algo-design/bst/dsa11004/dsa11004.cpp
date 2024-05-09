#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
Node *createNode(int data) {
    Node *new_node = new Node(data);
    return new_node;
}
void buildTree(Node *root, int u, int v, char x) {
    if (root != NULL) {
        if (root->data == u) {
            if (x == 'L') {
                root->left = createNode(v);
            } else {
                root->right = createNode(v);
            }
        }
        buildTree(root->left, u, v, x);
        buildTree(root->right, u, v, x);
    }
}
void levelOrder(Node *root) {
    queue<Node*>q;
    q.push(root);
    while (!q.empty()) {
        Node *curr= q.front();
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
    Node *root = createNode(u);
    buildTree(root, u, v, x);
    for (int i = 1; i < n; i++) {
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
