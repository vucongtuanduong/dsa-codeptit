#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct node {
    int data;
    node *next;
};
void testCase();
node *newNode(int value, node *next);
void deleteItem(node *head, map<int>mp1, map<int>mp2);
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
    map<int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        mp1[value]++;
        mp2[value] = 0;
        head = newNode(value, head);
    }
    deleteItem(head);
    
    printList(head);
    
}
node *newNode(int value, node *next) {
    node *temp = new node;
    temp->data = value;
    temp->next = next;
    return temp;
}
void deleteItem(node *head, map<int>mp1, map<int>mp2) {
    node *curr = head;
    int count = 0;
    while (curr->next != NULL) {
        if (m1[curr]) {
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