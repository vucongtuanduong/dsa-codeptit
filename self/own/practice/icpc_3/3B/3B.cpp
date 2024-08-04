#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
vector<int> primes;
vector<int> F(MAXN + 1, 0);

void sieve() {
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void calculateF() {
    F[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        int num = i;
        map<int, int> prime_factors;
        for (int p : primes) {
            if (p * p > num) break;
            while (num % p == 0) {
                prime_factors[p]++;
                num /= p;
            }
        }
        if (num > 1) prime_factors[num]++;
        
        int ways = 1;
        for (auto& pf : prime_factors) {
            ways *= (pf.second + 1);
        }
        F[i] = ways;
    }
}

int main() {
    sieve();
    calculateF();
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 2; i <= MAXN; ++i) {
            if (F[i] == N) {
                cout << N << " " << i << endl;
                break;
            }
        }
    }
    
    return 0;
}