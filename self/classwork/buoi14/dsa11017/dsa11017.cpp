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
void NLR(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void testCase() {
    
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
