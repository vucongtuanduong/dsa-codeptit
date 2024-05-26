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
Node *buildTree(int *a, int i, int n) {
    if (i < n) {
        Node *temp = new Node(a[i]);
        temp->left=  buildTree(a, 2 * i + 1, n);
        temp->right = buildTree(a, 2 *  i + 2, n);
        return temp;
    }
    return NULL;
}
void LNR(Node *root) {
    if (root != NULL) {
        
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    Node *root = buildTree(a, 0, n);
    LNR(root);
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
