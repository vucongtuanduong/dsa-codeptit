#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int count = 0;
    for (int a = 1; a <= n; ++a) {
        int max_b = (a + k - 1) / k * k; // Calculate the maximum b that satisfies a % b >= k
        if (max_b > n) {
            max_b = n;
        }
        count += (max_b - a) / k + 1; // Count the number of valid b's
    }

    cout << count << endl;

    return 0;
}