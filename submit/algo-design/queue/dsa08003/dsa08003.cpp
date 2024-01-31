#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Write your code here
    int t;
    cin >> t;
    deque<int> dq;
    while (t--) {
        string choice;
        cin >> choice;
        if (choice == "PUSHFRONT") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (choice == "PRINTFRONT") {
            if (!dq.empty()) {
                cout << dq.front() << endl;
            } else {
                cout << "NONE\n";
            }
        } else if (choice == "POPFRONT") {
            if (!dq.empty()) {
                dq.pop_front();
            }
        } else if (choice == "PUSHBACK") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (choice == "PRINTBACK") {
            if (!dq.empty()) {
                cout << dq.back() << endl;
            } else {
                cout << "NONE\n";
            }
            
        } else if (choice == "POPBACK") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
    }
    return 0;
}
