#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    vector<int> prefix(26, 0);
    int prefix_sum = 0;
    int intersections = 0;
    for (char c : s) {
        int index = c - 'A';
        if (freq[index] == 1) {
            intersections += prefix_sum - prefix[index]; 
        } else {
            freq[index] = 1;
            prefix[index] = prefix_sum;
            prefix_sum++;
        }
    }
    cout << intersections << endl;
    return 0;
}