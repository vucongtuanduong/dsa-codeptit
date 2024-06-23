#include <bits/stdc++.h>
using namespace std;
int nV, nE;
vector<pair<int, int>> a;
class Graph {
    public:
        int nV, nE;
        vector<vector<int>> edges;
        Graph(int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            edges.resize(nE);
        }

};
void testCase() {
    cin >> nV >> nE;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
