#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if any three distinct elements in the window can form a triangle
bool canFormTriangle(const vector<int>& window) {
    int n = window.size();
    if (n < 3) return false;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x = window[i], y = window[j], z = window[k];
                if (x + y > z && x + z > y && y + z > x) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxLength = 0;
    int left = 0;
    vector<int> window;

    for (int right = 0; right < n; ++right) {
        window.push_back(a[right]);
        while (!canFormTriangle(window) && left <= right) {
            window.erase(window.begin());
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
    return 0;
}