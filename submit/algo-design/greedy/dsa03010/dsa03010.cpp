#include <iostream>
#include <queue>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    // cout << t << endl;
    while (t--) {
        // cout << "t : " << t << endl;
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;
    priority_queue<int, vector<int>, greater<int> > pq(a, a + n);
    long long res = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    cout << res;
}