#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        string data;
        Node *left;
        Node *right;

        Node(string data) {
            this->data = data;
            this->left= this->right = NULL;
        }
};
void RNL(Node *root) {
    if (root != NULL) {
        RNL(root->right);
        if (root->data != "N") {
            cout << root->data << " ";
        }
        RNL(root->left);
    
    }   
}
void testCase() {
    string s;
    getline(cin, s);
    vector<string> v;
    string temp;
    stringstream ss(s);
    while (ss >> temp) {
        v.push_back(temp);
    }
    int i = 1;
    queue<string> q;
    q.push(v[0]);
    Node *root = new Node(v[0]);
    map<string, Node *> mp;
    mp[v[0]] = root;
    while (!q.empty()) {
        queue<string> tempQueue;
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            if (i < v.size()) {
                Node *node1 = new Node(v[i]);
                Node *node2 = new Node(v[i + 1]);
                mp[current]->left = node1;
                mp[current]->right = node2;
                if (v[i] != "N") {
                    mp[v[i]] = node1;
                    tempQueue.push(v[i]);
                }
                if (v[i + 1] != "N") {
                    mp[v[i + 1]] = node2;
                    tempQueue.push(v[i + 1]);
                }
                i += 2;
            }
        }
        if (i >= v.size()) {
            break;
        }
        q = tempQueue;
    }
    RNL(root);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
