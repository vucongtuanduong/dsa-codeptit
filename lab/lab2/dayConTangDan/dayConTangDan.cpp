#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> x;
vector<string> res;
string temp ;
void result() {
    if (count(x.begin(), x.end(), 1) >= 2) {
        for (int i = 0; i < n; i++){ 
            if (x[i] == 1) {
                temp += to_string(a[i]) + " ";
            }
        }
        temp.pop_back();
        res.push_back(temp);
        temp = "";
    }
    
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n - 1) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    temp = "";
    cin >> n;
    a.resize(n);  
    x.resize(n);  
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort(a.begin(), a.end());
    Try(0);
    sort(res.begin(), res.end());
    for (auto x : res) {
        cout << x << endl;
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
