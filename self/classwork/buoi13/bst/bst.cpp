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
Node *search(Node *root, int x) {
    if (root == NULL) {
        return root;
    }
    if (root->data == x) {
        return root;
    }
    Node *p = search(root->left, x);
    if (p == NULL) {
        p = search(root->right, x);
    }
    
}
void addLeft(Node *root, int x, int y) {
    Node *p = new Node;
    Node *q = new Node;
    p = search(root, x);
    if (p == NULL) {
        cout << "Khong the them duoc node la ben trai do khong tim thay node chua gia tri " << x << endl;
        return;
    }
    if (p->left != NULL) {
        cout << "Khong the them duoc node la ben trai do da co la \n";
        return;
    } else {
        q = makeNode(y);
        p->left = q;
    }
}
void removeLeft(Node *root, int x) {
    Node *p = search(root, x);
    if (p == NULL) {
        cout << "Khong tim thay node cha x\n";
        return;
    } else if (p->left->right != NULL || p->left->left != NULL) {
        cout << "Khong loai bo duoc do la node trung gian \n";
        return;
    } else {
        Node *q = p->left;
        p->left = NULL;
        delete q;
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
    cout << endl;
    addLeft(root, 3, 8);
    cout << "Duyet cay theo thu tu truoc: ";
    NLR(root);
    cout << endl << "Duyet cay theo thu tu giua: ";
    LNR(root);
    cout << endl << "Duyet cay theo thu tu sau: ";
    LRN(root);
    cout << endl;
    removeLeft(root, 6);
    cout << "Duyet cay theo thu tu truoc: ";
    NLR(root);
    cout << endl << "Duyet cay theo thu tu giua: ";
    LNR(root);
    cout << endl << "Duyet cay theo thu tu sau: ";
    LRN(root);
    cout << endl;
    return 0;
}
