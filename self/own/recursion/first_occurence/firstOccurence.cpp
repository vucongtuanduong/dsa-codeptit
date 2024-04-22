#include <bits/stdc++.h>
using namespace std;
int firstOcc(int *a, int n, int key) {
    if (n == 0) {
        return -1;

    } 
    if (a[0] == key) {
        return 0;
    }
    int subIndex  = firstOcc(a + 1, n - 1, key);
    if (subIndex != -1) {
        return subIndex + 1;
    }
    return -1;
}
int main () {
    int n, key;
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << firstOcc(a, n, key);
    return 0;
}