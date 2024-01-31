#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data;
    node *next;
};
void testCase();
node *newNode(int value, node *next);
int deleteItem(node *head, int x);
void printList(node *head);
int main() {
    // Your code here
    testCase();
    return 0;
}
void printList(node *head) {
    node *curr = head;
    vector<int> res;
    while (curr->next != NULL) {
        res.push_back(curr->data);
        curr = curr->next;
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    
    }
}
void testCase() {
    int n;
    cin >> n;
    node *head = new node;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        head = newNode(value, head);
    }
    int x;
    cin >> x;
    int res = deleteItem(head, x);
    
    printList(head);
    
}
node *newNode(int value, node *next) {
    node *temp = new node;
    temp->data = value;
    temp->next = next;
    return temp;
}
int deleteItem(node *head, int x) {
    node *curr = head;
    int count = 0;
    while (curr->next != NULL) {
        if (curr->next->data == x) {
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}