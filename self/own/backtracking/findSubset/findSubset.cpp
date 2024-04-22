#include <bits/stdc++.h>
using namespace std;
vector<string>res;
bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}
void findSubset(char *input, char *output, int i, int j) {
    //base case
    if (input[i] == '\0') { 
        output[j] = '\0';
        string temp(output);
        res.push_back(temp);
        return;
    }
    //rec case
    //include the ith letter
    output[j] = input[i];
    findSubset(input, output, i + 1, j + 1);
    //exclude the ith letter
    findSubset(input, output, i + 1, j);
}
int main() {
    // Write your code here
    char input[1000], output[1000];
    cin >> input;
    findSubset(input, output, 0, 0);
    sort(res.begin(), res.end(), cmp);
    for (auto x : res) {
        cout << x << endl;
    }
    return 0;
}
