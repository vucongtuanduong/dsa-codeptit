#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct node {
    int data;
    node *next;
};
void testCase();
node *newNode(int value);
void deleteItem(node *head);
void printList(node *head);
int main() {
    // Your code here
    testCase();
    return 0;
}
void printList(node *head) {
    node *curr = head;

    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
}
void testCase() {
    int n;
    cin >> n;
    node *head = nullptr;
    node *curr = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == nullptr) {
            head = newNode(value);
            curr = head;
        } else {
            curr->next = newNode(value);
            curr = curr->next;
        }
    }
    deleteItem(head);
    
    printList(head);
    
}
node *newNode(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    return temp;
}
void deleteItem(node *head) {
    map<int,bool> seen;
    node *curr = head;
    node *prev = nullptr;
    while (curr != nullptr) {
        if (seen[curr->data]) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}