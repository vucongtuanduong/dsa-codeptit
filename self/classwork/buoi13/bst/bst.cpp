#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

//tao node cho cay
Node *makeNode (int data) {
    Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void NLR(Node *root) { //duyet cay theo thu tu truoc
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node *root) {//duyet cay theo thu tu giua
    if (root != NULL) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(Node *root) { //duyet cay theo thu tu sau
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
int main() {
    // Write your code here
    root = makeNode(1);
    Node *node2 = makeNode(2);
    root->left = node2;
    Node *node3 = makeNode(3);
    root->right = node3;
    Node *node4 = makeNode(4);
    Node *node5 = makeNode(5);
    Node *node6 = makeNode(6);
    Node *node7 = makeNode(7);
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;
    cout << "Duyet cay theo thu tu truoc: ";
    NLR(root);
    cout << endl << "Duyet cay theo thu tu giua: ";
    LNR(root);
    cout << endl << "Duyet cay theo thu tu sau: ";
    LRN(root);
    return 0;
}
