#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
void testCase() {
    int n;
    cin >> n;
    int a[n];
    int fre[MAX + 1] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fre[a[i]]++;
    }

    int res = 1;
    for (int i = MAX; i >= 1; --i) {
        int count = 0;
        for (int j = i; j <= MAX; j += i) {
            count += fre[j];
            if (count > 1) {
                res = i;
                break;
            }
        }
        if (count > 1) {
            break;
        }
    }

    cout << res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    int T;
    cin >> T;
    while (T--) {
        
    }

    return 0;
}
