#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    int left = 0, right = 0, max_freq = 0, min_freq = INT_MAX, ans = 0;
    while (right < n) {
        freq[s[right] - 'a']++;
        max_freq = max(max_freq, freq[s[right] - 'a']);
        while (max_freq - min(freq[s[left] - 'a'], freq[s[right] - 'a']) > ans) {
            freq[s[left] - 'a']--;
            left++;
        }
        ans = max(ans, max_freq - min(freq[s[left] - 'a'], freq[s[right] - 'a']));
        right++;
    }
    cout << ans;
    return 0;
}