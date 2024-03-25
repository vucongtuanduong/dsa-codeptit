#include <bits/stdc++.h>
using namespace std;
void testCase();
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
}