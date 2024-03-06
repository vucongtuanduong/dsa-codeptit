#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n, s;
    cin >> n >> s;
    string max = "", min = "";
    if (s == 0 && n == 1) {
        cout << "0 0";
        return;
    } else if (s < 1 || s > (9 * n)) {
        cout << "-1 -1";
        return;
    } else {    
        int sum = s;
        while (n > 0) {
            if (sum >= 9) {
                max += "9";
                sum -= 9;
            } else {
                max += to_string(sum);
                sum = 0;
            }
            n--;
        }
        min = max;
        reverse(min.begin(), min.end());
        if (min[0] == '0') {
            min[0] = '1';
            int i = 1;
            while (min[i] == '0') {
                i++;
            }
            min[i] --;
        }

    }
    cout << min << " " << max;
}