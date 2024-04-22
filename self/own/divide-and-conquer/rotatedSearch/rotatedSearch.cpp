#include <bits/stdc++.h>
using namespace std;
//takes input an sorted array of distinct int, which is rotated about a pivot point and find the index of any given element
int rotated_search(vector<int> a, int key) {
    int n = a.size();
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (a[mid] == key) {
            return mid;
        }
        if (a[s] <= a[mid]) {
            //left
            if (key >= a[s] && key <= a[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            //right
            if (key >= a[mid] && key <= a[e]) {
                s = mid + 1;
            } else {
                s = mid - 1;
            }
        }
    }
    return -1;
}
int main() {
    // Write your code here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << rotated_search(a, k);
    return 0;
}
