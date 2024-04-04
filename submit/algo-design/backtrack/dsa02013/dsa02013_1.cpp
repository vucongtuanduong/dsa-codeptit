#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
vector<vector<int>> res;
void testCase();
void init(int p, int s);
void findCombinations(int s, int n, vector<int> &combination, int start);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void testCase() {
    int n, p, s;
    cin >> n >> p >> s;
    vector<int> combination;
    primes.clear();
    res.clear();
    init(p, s);
    findCombinations(s, n, combination, 0);
    
    cout << res.size() << endl;
    for (auto x : res) {
        for (auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
    
}
void findCombinations(int s, int n, vector<int> &combination, int start) {
    if (s == 0 && combination.size() == n) {
        res.push_back(combination);
        return;
    }
    for (int i = start; i < primes.size(); i++) {
        if (primes[i] <= s) {
            combination.push_back(primes[i]);
            findCombinations(s - primes[i], n, combination, i + 1);
            combination.pop_back();
        }
    }
}
void init(int p, int s) {
    vector<bool> prime(s + 1, true);
    for (int i = 2; i * i <= s; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= s; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = p + 1; i <= s; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    } 
}