#include <iostream>
using namespace std;
void testCase();
void init(int *a, int n);
bool isFinal(int *a, int n);
void genNext(int *a, int n);
bool isSame(int *a, int *x, int n);
int main() {
    // Your code here
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
    int *x = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    int *a = new int[n + 1];
    int count = 0;
    init(a, n);
    while (!isFinal(a, n)) {
        count++;
        if (isSame(a, x, n)) {
            cout << count;
            return;
        }
        genNext(a, n);
        
    }
}
void init(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}
bool isFinal(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != n - i + 1) {
            return false;
        }
    }
    return true;
}
void genNext(int *a, int n) {
    int i = n - 1;
    while (a[i] > a[i + 1]) {
        i--;
    }
    int j = n;
    while (a[j] < a[i]) {
        j--;
    }
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    int l = i + 1;
    int r = n;
    while (l < r) {
        tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++;
        r--;
    }
}
bool isSame(int *a, int *x, int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != x[i]) {
            return false;
        }
    }
    return true;
}
