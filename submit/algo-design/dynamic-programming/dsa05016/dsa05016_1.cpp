#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 1;
long long ugly[MAX] = {0};
void uglyNumber() {
    int i2 = 1, i3 = 1, i5 = 1;
    ugly[1] = 1;
    for (int i = 2; i < MAX; i++){ 
        ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
        if (ugly[i] == ugly[i2] * 2) {
            i2++;
        }
        if (ugly[i] == ugly[i3] * 3) {
            i3++;
        }
        if (ugly[i] == ugly[i5] * 5) {
            i5++;
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    cout << ugly[n];
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    uglyNumber();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
