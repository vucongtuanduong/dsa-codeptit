#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> a;
vector<int> x;
vector<string> res;
vector<string> res2;
bool unused[101];
void testCase();
void init();
void TryChar(int i);
void TryNum(int i);
int main() {
    testCase();
    return 0;
}
void TryChar(int i) {
    for (int j = 1; j <= n; j++)  {
        if (unused[j]) {
            unused[j] = false;
            a[i] = j;
            if (i == n - 1) {
                string s = "";
                for (int k = 0; k < n; k++) {
                    s += (char)(a[k] + 'A' - 1);
                }
                res.push_back(s);
            } else {
                TryChar(i + 1);
            }
            unused[j] = true; // Reset unused flag
        }
    }
}
void TryNum(int i) {
    for (int j = 1; j <= n; j++) { 
        x[i] = j;
        if (i == n - 1) {
            string s = "";
            for (int k = 0; k < n; k++) {
                s += to_string(x[k]); 
            }
            res2.push_back(s);
        } else {
            TryNum(i + 1);
        }
    }
}
void init() {
    res.clear();
    res2.clear();
    cin >> n;
    a.resize(n);
    x.resize(n);
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
}
void testCase() {
    init();
    TryChar(0);
    TryNum(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < res2.size(); j++) {
            cout << res[i] + res2[j] << endl;
        }
    }
}
