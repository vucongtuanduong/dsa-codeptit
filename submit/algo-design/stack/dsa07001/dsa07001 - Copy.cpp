#include "Stack.cpp"
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    stack<int> s;
    string choice;
    while (cin >> choice) {
        if (choice == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (choice == "show") {
            if (s.empty()) {
                cout << "empty" << endl;
                continue;
            }
            stack<int> temp = s;
            vector<int> res;
            while (!temp.empty()) {
                res.push_back(temp.top());
                temp.pop();
            }
            for (int i = res.size() - 1; i >= 0; i--) {
                cout << res[i] << " ";
            }
            cout << endl;  
        } else if (choice == "pop") {
            s.pop();
        } 
    }
}