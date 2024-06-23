#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ind(m);
    for (int i = 0; i < m; ++i) {
        cin >> ind[i];
        --ind[i]; // Adjusting indices to be 0-based
    }
    string c;
    cin >> c;

    // Pair each index with its corresponding character and sort this pair list
    vector<pair<int, char>> updates;
    for (int i = 0; i < m; ++i) {
        updates.emplace_back(ind[i], c[i]);
    }
    // Sort updates by index, and in case of equal indices, by character to ensure lexicographical order
    sort(updates.begin(), updates.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });

    // Apply updates in sorted order
    for (auto& update : updates) {
        s[update.first] = update.second;
    }

    cout << s << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}