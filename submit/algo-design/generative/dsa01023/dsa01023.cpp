#include <iostream>
using namespace std;
void testCase();
void init(int *a, int k);
bool isFinal(int *a, int n, int k);
bool isSame(int *a, int *x, int k);
void genNext(int *a, int n, int k);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int *x = new int[k + 1];
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    int *a = new int[k + 1];
    int count = 0;

    init(a, k);
    while (!isFinal(a, n, k)) {
        count++;
        if (isSame(a, x, k)) {
            cout << count << endl;
            return;
        }
        genNext(a, n, k);
    }
    cout << count + 1 << endl;
}
void init(int *a, int k) {
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}
bool isFinal(int *a, int n, int k) {
    for (int i = 1; i <= k; i++) {
        if (a[i] != n - k + i) {
            return false;
        }
    }
    return true;
}
bool isSame(int *a, int *x, int k) {
    for (int i = 1; i <= k; i++) {
        if (a[i] != x[i]) {
            return false;
        }
    }
    return true;
}
void genNext(int *a, int n, int k) {
    int t = k;
    while (a[t] == n - k + t) {
        t--;
    }
    a[t]++;
    for (int i = t + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }
}