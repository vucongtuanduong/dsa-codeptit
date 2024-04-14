#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<string> s;
vector<int> v;
void testCase();
int main() {
    // Write your code here
    testCase();

    return 0;
}
void testCase() {
    cin >> n >> k;
    for (int i = 0 ; i < n; i++) {
        string x;
        cin >> x;
        v.push_back(x.size());
    }
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j <= i + k; j++) {
            if (j < n) {
                if (v[i] == v[j]) {
                    res++;
                }
            }
            
        }   
    }
    cout << res << endl;
}