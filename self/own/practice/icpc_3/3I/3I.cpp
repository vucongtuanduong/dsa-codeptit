#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
vector<bool> prime(MAX + 1, 1);
void init() {
    prime[0] = 0;
    prime[1] = 1;
    for (int i = 2; i * i <= MAX; i++ ){
        if (prime[i] == 1) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
}
bool isPrime(int n) {
    if (n < 2) {
        return 0;
    } 
    for (int i = 2; i * i <= n; i++ ) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    // Write your code here
    init();
    int n;
    cin >> n;
    int count = 0;
    int count1 =0 ;
    for (int i = 1; i <= MAX; i++){ 
        if (isPrime(i)) {
            count++;
        }
        if (prime[i] == 1) {
            count1++;
        }
    }
    
    cout << count << endl;
    // cout << count1 << endl;
    cout << "105 ";
    for (int i = 1; i <= 105; i++) {
        cout << i << " ";
    }
    return 0;
}
