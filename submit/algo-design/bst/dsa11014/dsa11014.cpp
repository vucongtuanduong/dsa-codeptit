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

unordered_map<int, Node*> mp;


void connect(Node* r, int u, int v, char c) {

	if (c == 'L') {

		mp[u]->left = new Node(v);

		mp[v] = mp[u]->left;

	}

	else {

		mp[u]->right = new Node(v);

		mp[v] = mp[u]->right;

	}

}

int sumRightLeaves(Node* root, bool isRight = false) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL && isRight == true) {
        return root->data;
    }
    return sumRightLeaves(root->left, false) + sumRightLeaves(root->right, true);
}

void testCase() {
    int n;
    cin >> n;
    int u, v;
    char x;
    Node *root = NULL;
    mp.clear();
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        if (root == NULL) {
            root = new Node(u);
            mp[u] = root;
        }
        connect(root, u, v, x);
    }
    cout << sumRightLeaves(root, false);
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