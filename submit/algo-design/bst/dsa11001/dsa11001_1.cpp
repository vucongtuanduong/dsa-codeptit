#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        char key;
        Node *left;
        Node *right;


        Node (char key) {
            this->key = key;
            left = right = NULL;
        }
        
};
void printInOrder(Node *root) {
    if (root == NULL) {
        return;
    } 
    printInOrder(root->left);
    cout << root->key;
    printInOrder(root->right);
}
const string operations = "+-*/";
void testCase() {
    string s;
    cin >> s;
    stack<Node*> st;
    for (int i = 0; i < s.size(); i++) {
        if (operations.find(s[i]) != -1) {
            Node *temp = new Node(s[i]);
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
            st.push(temp);
        } else {
            Node *new_node = new Node(s[i]);
            st.push(new_node);
        }
    }
    printInOrder(st.top());
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
