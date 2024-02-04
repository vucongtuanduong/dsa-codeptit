#include <iostream>
#include <deque>
using namespace std;
void testCase();

int main() {
    // Your code here
    int t;
    cin >> t;
    while (t--){ 
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> dq; //store index of the largest element in subset
    for (int i = 0; i < n; i++) {
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i + 1 >= k) {
            cout << a[dq.front()] << " ";
        }
    }
}
