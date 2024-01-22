#include <iostream>
#include <vector>
using namespace std;
void testCase();
void init();
vector<string> target;
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    cout << target[n - 1][k - 1] ;
}
void init() {
    target.push_back("0");
    target.push_back("1");
    // string temp = target[0] + target[1];
    // target.push_back(temp);
    // for (auto x : target) {
    //     cout << x << endl;
    // }
    for (int i = 2; i < 92; i++) {
        string s = target[i - 2];
        string s2 = target[i - 1];
        string s3 = s + s2;
        // cout << s3 << endl;
        target.push_back(s3);
    }
}