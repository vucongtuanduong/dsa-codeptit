#include <iostream>
#include <queue>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void testCase() {
    queue<int> q;
    int n;
    cin >> n;
    while (n--) {
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << q.size() << endl;
                break;
            case 2:
                if (q.empty()) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";

                }
                break;
            case 3:
                int x;
                cin >> x;
                q.push(x);
                break;
            case 4:
                if (!q.empty()) {
                    q.pop();
                }
                break;
            case 5:
                if (!q.empty()) {
                    cout << q.front() << endl;
                } else {
                    cout << "-1\n";

                }
                break;
            case 6:
                if (!q.empty()) {
                    queue<int> temp;
                    temp = q;
                    int last = -1;
                    while (!temp.empty()) {
                        last = temp.front();
                        temp.pop();
                    }
                    cout << last << endl;
                } else {
                    cout << "-1\n";
                }
        }

    }
}