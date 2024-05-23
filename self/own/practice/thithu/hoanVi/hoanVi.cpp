#include <bits/stdc++.h>
using namespace std;
bool isFinal(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != (n - i)) {
            return false;
        }
    }
    return true;
}
int calDiff(vector<int> a) {
    int n = a.size();
    int diff = 0;
    for (int i = 0; i < n - 1; i++) {
            diff += a[i] - a[i + 1];
    }
    return diff;
}
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void testCase() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    while (!isFinal(a)) {
        int diff = calDiff(a);
        if (diff > 0) {
            print(a);
        }
       next_permutation(a.begin(), a.end());
    }
    int diff = calDiff(a);
    if (diff > 0) {
        print(a);
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
