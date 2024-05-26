#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> weights(12), corners(4);
    for (int i = 0; i < 12; i++) {
        cin >> weights[i];
    }
    sort(weights.rbegin(), weights.rend());
    for (int i = 0; i < 12; i++) {
        corners[i % 4] += weights[i];
    }
    int diff = *max_element(corners.begin(), corners.end()) - *min_element(corners.begin(), corners.end());
    cout << diff << "\n";
    return 0;
}