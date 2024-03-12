#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void testCase();
void swap(string &s, int j, int k);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void swap(string &s, int j, int k) {
    char temp = s[j];
    s[j] = s[k];
    s[k] = temp;
}
void testCase() {
    int n;
    string s;
    cin >> n >> s;
    int x = s.size();
    int j = x - 2;
    while (j >= 0 && s[j] >= s[j + 1]) {
        j--;
    }
    if (j == -1) {
        cout << n << " BIGGEST";
        return;
    }
    int k = x - 1;
    while (s[j] >= s[k]) {
        k--;
    }
    swap(s, j, k);
    reverse(s.begin() + j + 1, s.end());
    cout << n << " " << s;
}