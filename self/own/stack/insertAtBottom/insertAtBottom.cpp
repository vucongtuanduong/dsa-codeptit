#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s, int data) {
    if (s.empty()) {
        s.push(data);
        return;
    }
    //rec case
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}
int main() {
    // Write your code here
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    insertAtBottom(s, 5);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
