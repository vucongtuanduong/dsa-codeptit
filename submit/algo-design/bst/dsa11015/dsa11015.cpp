#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

unordered_map<int, Node*> nodeMap;
int maxPathSum;

int calcMaxPathSum(Node* node) {
    if (node == NULL) return 0;
    int left = calcMaxPathSum(node->left);
    int right = calcMaxPathSum(node->right);
    int max_single = max(max(left, right) + node->data, node->data);
    int max_top = max(max_single, left + right + node->data);
    maxPathSum = max(maxPathSum, max_top);
    return max_single;
}

Node* buildTree(int u, int v, char x) {
    Node* parentNode;
    if (nodeMap.find(u) == nodeMap.end()) {
        parentNode = new Node(u);
        nodeMap[u] = parentNode;
    } else {
        parentNode = nodeMap[u];
    }

    Node* childNode = new Node(v);
    if (x == 'L') parentNode->left = childNode;
    else parentNode->right = childNode;

    nodeMap[v] = childNode;

    return parentNode;
}

void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    Node* root = NULL;
    nodeMap.clear();
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        root = buildTree(u, v, x);
    }
    maxPathSum = INT_MIN;
    calcMaxPathSum(root);
    cout << maxPathSum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}