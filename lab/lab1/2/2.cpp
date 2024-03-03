#include <iostream>
using namespace std;
void testCase();
void mergeSort(int *a, int l, int r);
void merge(int *a, int l, int m, int r);
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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n -1);
    for (int i = 0; i < n; i++) {
        cout <<  a[i] << " ";
    }
}

void mergeSort(int *a, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
void merge(int *a, int l, int m, int r) {
    int tempArray[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) {
            tempArray[k++] = a[i++];
        } else {
            tempArray[k++] = a[j++];
        }
    }
    while (i <= m) {
        tempArray[k++] = a[i++];
    }
    while (j <= r) {
        tempArray[k++] = a[j++];
    }
    for (int i = l, k = 0; i <= r; i++, k++) {
        a[i] = tempArray[k];
    }
}
