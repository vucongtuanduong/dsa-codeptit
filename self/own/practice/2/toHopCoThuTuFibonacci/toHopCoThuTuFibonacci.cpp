#include <bits/stdc++.h>
using namespace std;
int n, k;
long long fibo[93] = {0};
vector<int> a;
int cnt = 2;
int stt = 0;
void init() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 93; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
void result() {
    stt++;
    if (stt == fibo[cnt]) {
        cnt++;
        cout << stt << ": ";
        for (int i = 1; i <= k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    
}
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= (n - k + i); j++) {
        a[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
int main() {
    // Write your code here
    init();
    cin >> n >> k;
    a.resize(k + 1);
    a[0] = 0;
    Try(1);
    return 0;
}
