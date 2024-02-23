#include <iostream>
#include <vector>
#include <map>
using namespace std;

void mergeSort(vector<int>& a, int l, int r);
void merge(vector<int>& a, int l, int m, int r);
void testCase();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    
    return 0;
}
void testCase() {
    int x;
    cin >> x;
    vector<int> a;
    map<int, int> mp;
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - '0']++;
        }
    }
    for (auto x : mp) {
        a.push_back(x.first);
    }
    int n = a.size();
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> tempArray(r - l + 1);
    int i = l;
    int j = m + 1;
    int k = 0;
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
    for (i = l, k = 0; i <= r; i++, k++) {
        a[i] = tempArray[k];
    }
}