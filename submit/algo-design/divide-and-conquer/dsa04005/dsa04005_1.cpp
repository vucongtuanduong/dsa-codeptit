#include <bits/stdc++.h>
using namespace std;
vector<long long> fibo = {0, 1, 1};
void testCase();
char findCharacter(long long n, long long i);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
char findCharacter(long long n, long long i) {
    if (n == 1) {
        return 'A';
    }
    if (n == 2) {
        return 'B';
    }
    if (i <= fibo[n - 2]) { //means that in the (n-2)th side
        return findCharacter(n - 2, i);
    } else { //means that in the (n-1)ith side
        return findCharacter(n - 1, i - fibo[n - 2]);
    }
}
void testCase() {
    long long n, i;
    cin >> n >> i;
    while (fibo.size() <= n) {
        long long temp = fibo.back() + *(fibo.end() - 2);//f[i] = f[i - 1] + f[i - 2];
        fibo.push_back(temp);
    }
    cout << findCharacter(n, i);
}