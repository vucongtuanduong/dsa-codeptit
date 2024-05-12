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

Node *buildTree(Node *root, int u,  int v, char x) {
    if (root == NULL ) {
        root = new Node(u);
    }
    if (root->data == u) {
        Node *temp = new Node(v);
        if (x == 'L') {
            root->left = temp;
        } else {
            root->right = temp;
        }
    } else {
        buildTree(root->left, u, v, x);
        buildTree(root->right, u, v, x);
    }
    return root;

}
void LRN(Node *root, vector<int> &path) {
    if (root != NULL) {
        LRN(root->left, path);
        LRN(root->right, path);
        path.push_back(root->data);
    }
}
void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    Node *root1 = NULL;
    Node *root2 = NULL;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root1 = buildTree(root1, u, v, x);
        
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root2 = buildTree(root2, u, v, x);
        
    }

    vector<int> path1, path2;
    LRN(root1, path1);
    LRN(root2, path2);
    cout << (path1 == path2);
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