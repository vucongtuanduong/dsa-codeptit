#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
node *head = NULL;
void insert(int new_data) {
    node *ptr = new node();
    ptr->data = new_data;
    ptr->next = head;
    head = ptr;
}
void display() {
    node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main() {
    // Write your code here
    insert(3);
    insert(1);
    insert(9);
    display();
    return 0;
}
