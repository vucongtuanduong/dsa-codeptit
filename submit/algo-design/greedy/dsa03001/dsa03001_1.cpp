#include <bits/stdc++.h>
using namespace std;
int money[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 9; i >= 0; i--) {
        while (n >= money[i]) {
            n -= money[i];
            count++;
        }
    }
    cout << count;
}