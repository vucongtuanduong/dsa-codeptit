#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
map<string,int> mp;
int x[101];
void testCase();
void init();
void Try(int i);
void display();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void Try(int i) {
    for (int j = x[i - 1] + 1; j <= (n - k + i); j++) {
        x[i] = j;
        if (i == k) {
            display();
        } else {
            Try(i + 1);
        }
    }
}
void display() {
    for (int i = 1; i <= k; i++) {
        cout << a[x[i] - 1] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n >> k;
    a.clear();
    mp.clear();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        x[i] = i;
        mp[s]++;
    }
    for (auto t : mp) {
        a.push_back(t.first);
    }
    n = a.size();
}
void testCase() {
    init();
    Try(1);
}