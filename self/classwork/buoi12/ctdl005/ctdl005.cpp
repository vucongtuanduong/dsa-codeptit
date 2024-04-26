#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int new_data) { //insert at tail of the linked list
    Node *x = new Node;
    x->data = new_data;
    x->next = NULL;
    if (head == NULL) {
        head = x;
    } else {
        Node *curr = head;
        while (curr != NULL) {
            curr = curr->next;
        }
        curr->next = x;
    }
    
}
void deleteNode(int x) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == x) {
            current = current->next;
            
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >>> value;
        insert(value);
    }
    int x;
    cin >> x;
    deleteNode(x);
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
