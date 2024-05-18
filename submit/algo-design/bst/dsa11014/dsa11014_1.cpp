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
unordered_map <int, Node*> nodeMap;
void buildTree(Node *root, int u, int v, char x) {
    if (x == 'L') {
        nodeMap[u]->left = new Node(v);
        nodeMap[v] = nodeMap[u]->left;
    } else {
        nodeMap[u]->right = new Node(v);
        nodeMap[v] = nodeMap[u]->right;
    }
}
int sumRightLeaves(Node *root, bool isRight) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL && isRight == true) {
        return root->data;
    }
    return sumRightLeaves(root->left, false ) + sumRightLeaves(root->right, true);

}
void testCase() {
    int n;
    cin >> n;
    nodeMap.clear();
    int u, v;
    char x;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        if (root == NULL) {
            root = new Node(u);
            nodeMap[u] = root;
        }
        buildTree(root, u, v, x);
    }
    cout << sumRightLeaves(root, false);
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
