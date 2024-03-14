#include <bits/stdc++.h>
using namespace std;
void testCase();
long long merge(vector<long long> &a, vector<long long> &temp, long long left, long long mid, long long right);
long long mergeSort(vector<long long> &a, vector<long long> &temp, long long left, long long right);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
long long mergeSort(vector<long long> &a, vector<long long> &temp, long long left, long long right) {
    long long mid, count = 0;
    if (left < right) {
        mid = (left + right) / 2;
        count += mergeSort(a, temp, left, mid);
        count += mergeSort(a, temp, mid + 1, right);
        count += merge(a, temp, left, mid + 1, right);
    }
    return count;
}
long long merge(vector<long long> &a, vector<long long> &temp, long long left, long long mid, long long right) {
    long long i = left, j = mid, k = left;
    long long count = 0;
    while ( (i <= mid - 1) && (j <= right)) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = temp[i];
    return count;
}
void testCase() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> temp(n);
    cout << mergeSort(a, temp, 0, n - 1);
}