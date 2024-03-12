#pragma once
#include <iostream>
struct node {
    int item;
    node *next;
};
struct Stack{
    node *head;
    int size;
};
Stack *StackNew();
void StackFree(Stack *s);
void StackPush(Stack *s, int item);
int StackPop(Stack *s);
int StackSize(Stack *s);
int StackPeek(Stack *s);
void StackPrint(Stack *s);