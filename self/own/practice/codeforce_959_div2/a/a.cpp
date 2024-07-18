#include <bits/stdc++.h>
using namespace std;
void testCase(){ 
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << "-1\n"; 
        return;
    }
    
    vector<int> x(n, 0);
    for (int i = 0; i < n; i++ ){
        x[i] = i + 1;
    }
    if (n == 1) {
        vector<int> temp(a[0], a[0] + m);
        bool ok = false;
        while (!ok && next_permutation(temp.begin(), temp.end())) {
            ok = true;
            for (int i = 0; i < m; i++) {
                if (a[0][i] == temp[i]) {
                    ok = false;
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    // for (int i = 0; i < x.size(); i++) {
    //     cout << x[i] << " ";
    // }
    int b[n][m];
    bool ok =false;
    while (!ok && next_permutation(x.begin(), x.end())) {
        ok = true;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[x[cnt] - 1][j];
                
            }
            cnt++;
        }
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < m; j++) {
                if (a[i][j] == b[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    // vector<vector<int>> res;
    // for (int i = 0; i < n; i++) {
    //     vector<int> x(a[i], a[i] + m);
    //     for (int i = 0; i < x.size(); i++) {
    //         cout << x[i] << " ";
    //  
    //    }
    // }
}
void testCase2() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int x = n * m;
    vector<int> b(x, 1);
    int cnt= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[cnt++] = a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << "-1\n"; 
        return;
    }
    if (x % 2 == 1) {
        int s = x / 2;
        vector<int> c(x, 0);
        c = b;
        int dem = 0;
        for (int i = s; i < x; i++ ){
            c[dem++] = b[i];
        }
        for (int i = 0; i < s; i++) {
            c[dem++] = b[i];
        }
        // for (int i = 0; i < x; i++) {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
        b = c;
        reverse(b.begin(), b.end());
    }
    int res[n][m];
    cnt--;
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < m; j++) {
            res[i][j] = b[cnt--];
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        // cout << endl;
    }
    return 0;
}
