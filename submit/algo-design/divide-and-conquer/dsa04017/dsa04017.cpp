#include <iostream>
using namespace std;
void testCase();
int findDiffer(int *a, int *b, int n);//normal approach
int dvcfindDiffer(int *a, int *b, int l, int r); //divide and conquer approach
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
int dvcfindDiffer(int *a, int *b, int l, int r) {
    if (l >= r) {
        return l + 1;
    }
    int mid = (l + r) / 2;
    if (a[mid] == b[mid]) {
        return dvcfindDiffer(a, b, mid + 1, r);
    } else {
        return dvcfindDiffer(a, b, l, mid);
    }
}
int findDiffer(int *a, int *b, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) /  2;
        if (a[mid] == b[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l + 1;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    int b[n - 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    // cout << findDiffer(a, b, n);
    cout << dvcfindDiffer(a, b, 0, n - 1);
}