#include <bits/stdc++.h>
using namespace std;
long long fibo[93];
void init(){ 
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2 ; i < 93; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
string fiboString(long long n, long long k) {
    if (n == 1) {
        return "A";
    }
    if (n == 2) {
        return "B";

    }
    if (k > fibo[n - 2]) {
        return fiboString(n - 1, k - fibo[n - 2]);
    } 
    return fiboString(n - 2, k);
}
void testCase(){
    long long n, k;
    cin >> n >> k;
    cout << fiboString(n, k);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
