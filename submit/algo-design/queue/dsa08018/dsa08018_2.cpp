#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    vector<string> res;
    q.push("6");
    q.push("8");
    while (!q.empty()) {
        string s = q.front();
        res.push_back(s);
        
        q.pop();
        if (s.size() < n) {
            q.push(s + "6");
            q.push(s + "8");
            
        }
    }
    cout << res.size() << endl;
    for (int i= 0 ; i < res.size(); i++) {
        cout << res[i] << " ";
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
