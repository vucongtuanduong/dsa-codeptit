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
int main() {
    // Write your code here
    return 0;
}
