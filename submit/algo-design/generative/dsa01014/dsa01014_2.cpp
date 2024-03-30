#include <bits/stdc++.h>
using namespace std;
int n, k, s, res;
bool ok;
vector<int> x;
vector<int> a;
void testCase();
void init();
void genNext();
bool check();
int main() {
    // Write your code here
    while (true) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        
        testCase();
        cout << endl;
    }
    return 0;
}
void genNext() {
    int i = k;
    while (i > 0 && x[i] == (n - k + i)) {
        i--;
    }
    if (i > 0) {
        x[i]++;
        for (int j = i + 1; j <= k; j++) {
            x[j] = x[j - 1] + 1;
        }
    } else {
        ok = false;
    }
}
bool check() {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        // cout << x[i] << " ";
        sum += x[i];
    }
    // cout << endl;
    return (sum == s);
}
void init() {
    x.resize(k + 1);
    ok = true;
    res = 0;
    for (int i = 1; i <= k; i++)  {
        x[i] = i;
    }
}
void testCase() {
    init();
    while (ok) {
        if (check()) {
            res++;
        }
        genNext();
    }
    cout << res;
}