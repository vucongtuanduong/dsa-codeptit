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
void NLR(Node *root) { //pre-order
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node *root) {//level-order
    if (root != NULL) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(Node *root) { //post-order
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
    NLR(root);
    
    
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