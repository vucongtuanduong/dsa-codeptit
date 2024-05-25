#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node (int data) {
            this->left = this->right = NULL;
            this->data = data;
        }
};
Node *buildTree(Node *root, int x) {
    if (root == NULL) {
        return new Node(x);
    } else {
        if (x > root->data) {
            root->right = buildTree(root->right, x);
        }  else {
            root->left=  buildTree(root->left, x);
        }
    }
    return root;
}
void rightLevelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->right != NULL) {
            q.push(curr->right);
        }
        if (curr->left != NULL) {
            q.push(curr->left);
        }
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
    rightLevelOrder(root);
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
