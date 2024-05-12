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
Node *buildBalancedBST(int *a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(a[mid]);
    root->left = buildBalancedBST(a, start, mid - 1);
    root->right = buildBalancedBST(a, mid + 1, end);
    return root;
}
void countLeaf(Node *root, int &res) {
    if (root != NULL) {
        if (!(root->left == NULL && root->right == NULL)) {
            res--;
            countLeaf(root->left, res);
            countLeaf(root->right, res);
        }
    }
}
void testCase(){ 
    int n;
    cin >> n;
    int a[n];
    for (int i =0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    Node *root = buildBalancedBST(a, 0, n - 1);
    int res = n;
    countLeaf(root, res);
    cout << res;
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
