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

Node *buildTree(Node *root, int u, int v, char x) {
    if (root == NULL) {
        root = new Node(u);
    }
    if (root->data == u) {
        Node *temp  = new Node(v);
        if (x == 'L') {
            root->left = temp;
        } else {
            root->right = temp;
        }
        
        
    } else {
        buildTree(root->left, u, v, x);
        buildTree(root->right, u, v,  x);
    }
        

    return root;
}
void isCompleteTree(Node *root, bool &check) {
    if (root != NULL) {
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            check = false;
            return;
        }
        isCompleteTree(root->left, check);
        isCompleteTree(root->right, check);
    }
}

void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root = buildTree(root, u, v, x);
        
    }
    bool check = true;
    isCompleteTree(root, check);
    cout << check;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}