#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int nV;
    int nE;
    vector<vector<int>> edges;

    Graph(int nV, int nE) {
        this->nV = nV;
        this->nE = nE;
        this->edges.resize(nV);
    }
};

int isEuler(Graph *g) {
    int res = 0;
    for (int i = 0; i < g->nV; i++) {
        int cnt = 0;
        for (int u : g->edges[i]) {
            cnt++;
        }
        if (cnt % 2 == 1) {
            res++;
        }
        if (res > 2) {
            return 0;
        }
    }
    if (res == 0) {
        return 2;
    } else {
        return 1;
    }
}

void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph* g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    cout << isEuler(g);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}