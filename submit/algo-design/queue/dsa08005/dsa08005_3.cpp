#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    while(n--) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }

}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
