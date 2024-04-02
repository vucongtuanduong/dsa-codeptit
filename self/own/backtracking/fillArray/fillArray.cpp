#include <bits/stdc++.h>
using namespace std;
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void fillArray(int *a, int i, int n, int val) {
    //base case
    if (i == n) {
        //print the array
        printArray(a, n);
        return;
    }
    //rec case
    a[i] = val;
    fillArray(a, i + 1, n, val + 1);
    //backtracking case
    a[i] = -1 * a[i];
}
int main() {
    // Write your code here
    int a[100] = {0};
    int n;
    cin >> n;
    fillArray(a, 0, n, 1);
    printArray(a, n);
    return 0;
}
