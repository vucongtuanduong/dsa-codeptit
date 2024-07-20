#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;
        bool canReach = true;
        int position = 0;

        while (position < n) {
            bool jumped = false;
            // Try to jump to the furthest possible log or bank within m distance
            for (int jump = min(m, n - position); jump > 0; --jump) {
                if (river[position + jump] != 'C') { // Can jump to a log or bank
                    position += jump;
                    jumped = true;
                    break;
                }
            }
            if (!jumped) { // If couldn't jump, check if swimming is necessary and possible
                if (position < n - 1 && river[position + 1] == 'W' && k > 0) {
                    // Swim to the next segment
                    position += 1;
                    k -= 1;
                } else {
                    // Can't jump or swim further
                    canReach = false;
                    break;
                }
            }
        }

        cout << (canReach ? "YES" : "NO") << endl;
    }
    return 0;
}