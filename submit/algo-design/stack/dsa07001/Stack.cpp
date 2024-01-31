#include "Stack.h"
#include <vector>
#include <stack>
using namespace std;

Stack *StackNew() {
    Stack *s = new Stack;
    s->head = NULL;
    s->size = 0;
    return s;
}
void StackFree(Stack *s) {
    node *curr = s->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete s;
}
void StackPush(Stack *s, int item) {
    node *newNode = new node;
    newNode->item = item;
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
}
int StackPop(Stack *s) {
    if (s->size == 0) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    node *newHead = s->head->next;
    int item = s->head->item;
    delete s->head;
    s->head = newHead;
    s->size--;
    return item;
}
int StackSize(Stack *s) {
    return s->size;
}
int StackPeek(Stack *s) {
    if (s->size == 0) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return s->head->item;
}
void StackPrint(Stack *s) {
    if (s->size == 0) {
        cout << "empty" << endl;
        return;
    }
    vector<int> res;
    node *curr = s->head;
    while (curr != NULL) {
        res.push_back(curr->item);
        curr = curr->next;
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;
}