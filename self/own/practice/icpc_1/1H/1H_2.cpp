#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    vector<int> a = {3, 2 ,1};
    vector<int> b = {6, 5, 4};
    vector<vector<int>> c;
    c.push_back(b);
    c.push_back(a);
    cout << c[0][0] << endl;
    if (a < b) {
        cout << "1"; 
    }else {
        cout << "0";
    }
    return 0;
}
