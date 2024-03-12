#include <iostream>
#include <map>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int x = mp.size() / 2;
    int max  = -1;
    for (auto temp : mp) {
        if (temp.second > max) {
            max = temp.second;
        }
    }
    for (auto temp : mp) {
        if (temp.second > x && temp.second == max) {
            cout << temp.first;
            return;
        }
    }
    cout << "NO";

}