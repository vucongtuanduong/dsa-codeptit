#include <bits/stdc++.h>
using namespace std;
int n, k;
bool ok;
int x[101];
vector<string> res;
void testCase();
void init();
void genNext();
void display();
bool check();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void genNext() {
    int i = n;
    while (i > 0 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i > 0) {
        x[i] = 1;
    } else {
        ok = false;
    }
}
bool check() {
    int countNumberSub = 0;
    int count0s = 0;
    bool is0 = false;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0 && is0 == false) {
            count0s = 1;
            is0 = true;
        } else if (x[i] == 0 && is0 == true) {
            count0s++;
            if (count0s > k) {
                return false;
            }
        } else if (x[i] == 1) {
            is0 = false;
            if (count0s == k) {
                countNumberSub++;
            }
            count0s = 0;

            
        }
    }
    if (count0s > k) {
        return false;
    } else if (count0s == k) {
        countNumberSub++;
    }
    return (countNumberSub == 1);
}
void display() {
    if (check()) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            if (x[i] == 0) {
                s += "A";
            } else {
                s += "B";
            }
        }
        res.push_back(s);
    }
}
void init() {
    res.clear();
    cin >> n >> k;
    ok = true;

}
void testCase() {
    init();
    while (ok) {
        display();
        genNext();
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}