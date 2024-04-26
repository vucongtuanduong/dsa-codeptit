#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *head = NULL;
void display() {
    Node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    
}
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
int deleteNode(int x) {
    int count = 0;
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL) {
        Node *tmp = current;
        if (current->data == x) {
            current = current->next;
            if (prev != NULL) {
                prev->next = current;
            } else {
                head = current;
            }
            delete tmp;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}
void testCase() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(value);
    }
    int x;
    cin >> x;
    int res = deleteNode(x);
    display();
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
