#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string signs;
    cin >> signs;

    vector<int> transformed_sequence;
    int current_sum = 0;

    // Calculate the cumulative sum of signs
    for (char sign : signs) {
        if (sign == '+') {
            current_sum += 1;
        } else {
            current_sum -= 1;
        }
        transformed_sequence.push_back(current_sum);
    }

    // Use a set to track all possible sums we can achieve with the transformed sequence
    unordered_set<int> possible_sums;
    current_sum = 0;
    for (int value : transformed_sequence) {
        current_sum += value;
        possible_sums.insert(current_sum);
    }

    // Add the sums that can be achieved by just using `a` and `b` alone
    possible_sums.insert(0);

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Process each query
    for (const auto& query : queries) {
        int a = query.first;
        int b = query.second;

        // Check if we can achieve the sum `a` or `-a` or `b` or `-b` using the possible sums
        if (possible_sums.count(a) || possible_sums.count(-a) || possible_sums.count(b) || possible_sums.count(-b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}