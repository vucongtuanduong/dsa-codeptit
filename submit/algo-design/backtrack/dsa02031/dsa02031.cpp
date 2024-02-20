#include <iostream>
#include <cstring>
using namespace std;
void print(string res);
void testCase();
bool isConsonant(char c);
void Try(char i, char c, bool *visited, int n, string &res);
int main() {
    // Write your code here
    testCase();
    return 0;
}
bool isConsonant(char c) {
    return ((c != 'A') && (c != 'E'));
}
void print(string res) {
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 'A' || res[i] == 'E') {
            if (i > 0 && i < res.size() - 1 && isConsonant(res[i - 1]) && isConsonant(res[i + 1])) {
                return;
            }
        }
    }
    cout << res << endl;
}
void Try(char i, char c, bool *visited, int n, string &res) {
    for (char j = 'A'; j <= c; j++) {
        if (!visited[j]) {
            res.push_back(j);
            visited[j] = true;
            if (res.size() == n) {
                print(res);
            } else {
                Try(i + 1, c, visited, n, res);
            }
            res.pop_back();
            visited[j] = false;
        }
    }
}
void testCase() {
    char c;
    cin >> c;
    
    int n = c - 'A' + 1;
    bool visited[128];
    memset(visited, false, sizeof(visited));
    string res;
    Try('A', c, visited, n, res);
    // cout << c << endl;
}