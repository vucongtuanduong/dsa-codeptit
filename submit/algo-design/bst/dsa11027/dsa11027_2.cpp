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
Node *buildTree(vector<int> a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(a[mid]);
    root->left = buildTree(a, start, mid - 1);
    root->right = buildTree(a, mid + 1, end);
    return root;

}
void countLeaf(Node *root, int &cnt) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            cnt++;
        }
        countLeaf(root->left, cnt);
        countLeaf(root->right, cnt);
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node *root = buildTree(a, 0, n - 1);
    int cnt =0 ;
    countLeaf(root, cnt);
    cout << cnt;
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
