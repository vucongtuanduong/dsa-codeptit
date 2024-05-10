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



Node *makeNode(int new_data) {
    Node *n = new Node(new_data);
    return n;
}
Node *addNodeToTree(Node *root, int new_data) {
    if (root == NULL) {
        return makeNode(new_data);
    }
    if (new_data > root->data) {
        root->right = addNodeToTree(root->right, new_data);
    } else {
        root->left = addNodeToTree(root->left, new_data);
    }
    return root;
}
Node *rotateLeft(Node *root) {
    Node *p = root;
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        p = root->right;
        root->right = p->left;
        p->left = root;
    }
    return p;
}
void NLR(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LRN(Node *root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    Node *root = NULL;
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        root = addNodeToTree(root, a[i]);
    }
    LRN(root);
    
    
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
