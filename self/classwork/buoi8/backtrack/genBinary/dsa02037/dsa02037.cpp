
#include <bits/stdc++.h>
using namespace std;
int n;
int x[101];
int a[101];
void init();
void Try(int i);
void result();
bool isPrime(int sum);

int main () {
    int t;
    cin >> t;
    while (t--) {
        init();
        Try(1);
    
    }
    return 0;
}
bool isPrime(int sum) {
    if (sum < 2) {
        return false;
    }
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            return false;
        }
    }
    return true;
}

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
}
void Try(int i) {
    for (int j = 0;  j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            result();
            
        } else {
            Try(i + 1);
        }
        
        
    }
}
void result() {
    int sum = 0;
    for (int i =1; i<= n; i++) {
        if (x[i]) {
            sum += a[i];
        }
    }
    if (isPrime(sum)) {
        for (int i = 1; i <= n; i++) {
            if (x[i]) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}