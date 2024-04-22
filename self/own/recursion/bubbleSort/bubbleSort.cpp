#include <bits/stdc++.h>
using namespace std;


void bubble_sort_rec(int *a, int n) {
    if (n == 1) {
        return;
    }
    for (int j = 0; j < n - 1; j ++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    bubble_sort_rec(a, n -1);
}
void bubble_sort_rec2(int *a, int n, int j) {
    if (n == 1 || n == 0) {
        return;
    }
    if (j == n - 1) {
        bubble_sort_rec2(a, n - 1, 0);
        return;
    }
    if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
    }

    bubble_sort_rec2(a, n, j + 1);
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubble_sort_rec2(a, n, 0);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
