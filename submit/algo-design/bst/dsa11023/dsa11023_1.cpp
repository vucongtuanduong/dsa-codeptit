#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};
Node *buildTree(Node *root, int x) {
    if (root == NULL) {
        return new Node(x);
    } 
    if (x > root->data) {
        root->right = buildTree(root->right, x);
    } else if (x < root->data) {
        root->left = buildTree(root->left, x);
    } 
    return root;
}
void heightTree(Node *root, int count, vector<int> &res) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            res.push_back(count);
        }
        heightTree(root->left, count + 1, res);
        heightTree(root->right, count + 1, res);

    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        root = buildTree(root, a[i]);
    }
    vector<int> res;
    int count = 0;
    heightTree(root, count, res);
    cout << *max_element(res.begin(), res.end());
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
