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
    return 0;
}
