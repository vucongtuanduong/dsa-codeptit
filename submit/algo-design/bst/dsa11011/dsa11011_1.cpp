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
void buildTree(Node *root, int u, int v, int x) {
    if (root != NULL) {
        if (root->data == u) {
            Node *temp = new Node(v);
            if (x == 'L') {
                root->left = temp;
            } else {
                root->right = temp;
            }
        } else {
            buildTree(root->left, u, v ,x);
            buildTree(root->right, u, v, x);
        }
    }
}
void isPerfectBinaryTree(Node *root, bool &check) {
    if (root != NULL) {
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            check = false;
        }
        isPerfectBinaryTree(root->left, check);
        isPerfectBinaryTree(root->right, check);
    }
}
void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    cin >> u >> v >> x;
    Node *root = new Node(u);
    
    buildTree(root, u, v, x);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        buildTree(root, u, v, x);
    }   
    int leafDepth = 0;
    bool check = true;
    isPerfectBinaryTree(root, check);
    cout << check;

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
