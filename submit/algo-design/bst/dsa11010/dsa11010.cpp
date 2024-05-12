#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left; 
        Node *right;
        int depth;
        Node (int data) {
            this->data = data;
            this->left = this->right = NULL;
            this->depth = -1;
        }
};

Node* buildTree(Node *root, int u, int v, char x, int depth) {
    if (root == NULL) {
        root = new Node(u);
        root->depth = depth;
    }
    if (root->data == u) {
        Node *temp = new Node(v);
        temp->depth = depth + 1;
        if (x == 'L') root->left = temp;
        else root->right = temp;
    } else {
        buildTree(root->left, u, v, x, depth + 1);
        buildTree(root->right, u, v, x, depth + 1);
    }
    return root;
}

void isPerfectTree(Node *root, int depth, int &leafDepth, bool &check) {
    if (root != NULL) {
        if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL)) {
            check = false;
        }
        isPerfectTree(root->left, depth + 1, leafDepth, check);
        isPerfectTree(root->right, depth + 1, leafDepth, check);

    } else {
        if (leafDepth == 0) {
            leafDepth = depth;
        } else if (leafDepth != depth) {
            check = false;
            return;
        }
    }
}

void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    cin >> u >> v >> x;
    Node *root = buildTree(NULL, u, v, x, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        root = buildTree(root, u, v ,x, 0);
    }
    int leafDepth = 0;
    bool check = true;
    isPerfectTree(root, 0, leafDepth, check);
    if (check) {
        cout <<"Yes";
    } else {
        cout << "No";
    }
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