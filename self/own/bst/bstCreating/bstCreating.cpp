#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int key;
        Node *left;
        Node *right;

        Node (int key) {
            this->key = key;
            left = right = NULL;
        }
};
void printInOrder(Node *root) {
    if (root == NULL) {
        return ;
    }
    //left -> root -> right;
    printInOrder(root->left);
    cout << root->key << " , ";
    printInOrder(root->right);
}
Node *insert (Node *root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    //recursive case
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}
bool search(Node *root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
int main() {
    // Write your code here
    Node *root = NULL;
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    for (int x : a) {
        root = insert(root, x);
    }
    printInOrder(root);
    cout << endl;
    cout << search(root, x) << endl;
    return 0;
}
