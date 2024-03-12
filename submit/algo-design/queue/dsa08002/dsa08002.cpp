#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Write your code here
    int n;
    cin >> n;
    queue<int> q;
    while (n--) {
        string choice;
        cin >> choice;
        if (choice == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        } else if (choice == "POP") {
            if (!q.empty()) {
                q.pop();
            }
        } else if (choice == "PRINTFRONT") {
            if (!q.empty()) {
                cout << q.front() << endl;
            } else {
                cout << "NONE\n";
            }
        }
    }
    return 0;
}
