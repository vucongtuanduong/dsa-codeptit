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

Node *root = NULL;

Node *makeNode(int new_data) {
    Node *n = new Node(new_data);
    return n;
}
int main() {
    // Write your code here
    return 0;
}
