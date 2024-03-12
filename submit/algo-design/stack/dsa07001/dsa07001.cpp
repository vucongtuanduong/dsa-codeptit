#include "Stack.cpp"
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    Stack *s = StackNew();  
    string choice;
    while (cin >> choice) {
        if (choice == "push") {
            int x;
            cin >> x;
            StackPush(s, x);
        } else if (choice == "show") {
            StackPrint(s); 
        } else if (choice == "pop") {
            StackPop(s);
        } 
    }
}