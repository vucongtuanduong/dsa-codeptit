#include <bits/stdc++.h>
using namespace std;
int lastOcc(int *a, int n, int key) {
    //base case
    if (n == 0) {
        return -1;
    }
    //rec case
    int subIndex = lastOcc(a + 1, n - 1, key);
    if (subIndex == -1) {
        if (a[0] == key) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return subIndex + 1;
    }
}
int main() {
    // Write your code here
    int n, key;
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << lastOcc(a, n, key);
    return 0;
}
