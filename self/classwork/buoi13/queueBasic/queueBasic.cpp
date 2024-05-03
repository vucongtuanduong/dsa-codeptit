#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
