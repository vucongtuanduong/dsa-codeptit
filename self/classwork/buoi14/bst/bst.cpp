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



Node *makeNode(int new_data) {
    Node *n = new Node(new_data);
    return n;
}
Node *addNodeToTree(Node *root, int new_data) {
    if (root == NULL) {
        return makeNode(new_data);
    }
    if (new_data > root->data) {
        root->right = addNodeToTree(root->right, new_data);
    } else {
        root->left = addNodeToTree(root->left, new_data);
    }
    return root;
}
// int findMinValueNode(Node *root, int curr) {
//     if (root != NULL) {
//         curr = min(curr, findMinValueNode(root->left));
//     }
//     return curr;
// }
// Node* minValueNode(Node *root) {
//     return findMinValueNode(root, INT_MAX);
// }
// Node *deleteNode(Node *root, int value) {
//     if (root == NULL) {
//         return root;
//     }
//     if (value < root->data) {
//         root->left = deleteNode(root->left, value);
//     } else if (value > root->data) {
//         root->right = deleteNode(root->right, value);
//     } else {
//         if (root->left == NULL) {
//             Node *temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             Node *temp = root->left;
//             free(root);
//             return temp;
//         }
//         //truong hop node co ca hai cay con
//         Node *temp = minValueNode(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }
Node *rotateLeft(Node *root) {
    Node *p = root;
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        p = root->right;
        root->right = p->left;
        p->left = root;
    }
    return p;
}
void NLR(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
int main() {
    // Write your code here
    Node *root = NULL;
    root = addNodeToTree(root, 40);
    root = addNodeToTree(root, 30);
    root = addNodeToTree(root, 60);
    root = addNodeToTree(root, 25);
    root = addNodeToTree(root, 35);
    root = addNodeToTree(root, 50);
    root = addNodeToTree(root, 70);
    root = addNodeToTree(root, 20);
    root = addNodeToTree(root, 28);
    root = addNodeToTree(root, 32);
    root = addNodeToTree(root, 38);
    root = addNodeToTree(root, 55);
    root = addNodeToTree(root, 65);
    root = addNodeToTree(root, 90);
    root = addNodeToTree(root, 15);
    root = addNodeToTree(root, 22);
    root = addNodeToTree(root, 26);
    root = addNodeToTree(root, 29);
    root = addNodeToTree(root, 36);
    root = addNodeToTree(root, 62);
    root = addNodeToTree(root, 68);

    NLR(root);
    cout << endl;
    root = rotateLeft(root);
    NLR(root);
    return 0;
}
