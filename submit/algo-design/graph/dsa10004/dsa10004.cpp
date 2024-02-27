#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
int dfs(Graph *g, int v, bool *visited);
bool evenDeg(Graph *g, int v);
int hasEulerCircuit(Graph *g);
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
bool evenDeg(Graph *g, int v) {
    int deg = 0;
    for (int i = 0; i < g->edges[v].size(); i++) {
        deg++;
    }
    return deg % 2 == 0;
}
int hasEulerCircuit(Graph *g) {
    bool visited[g->nV];
    for (int i = 0; i < g->nV; i++){
        visited[i] = false;
    }
    int total = dfs(g, 0, visited);
    if (total != g->nV) {
        return false;
    }
    int numOddDeg = 0;
    bool isCircuit = true;
    for (int i = 0; i < g->nV; i++) {
        if (!evenDeg(g, i)) {
            isCircuit = false;
            numOddDeg++;
        }
    }
    if (isCircuit == true) {
        return 2;
    } else if (numOddDeg == 0 || numOddDeg == 2) {
        return 1;
    } else {
        return 0;
    }
    
}
int dfs(Graph *g, int v, bool *visited) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    vector<int> path;
    path.push_back(v);
    set<int> se;
    se.insert(v);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (se.count(u) == 0) {
            path.push_back(u);
            se.insert(u);
        }
        for (int i = 0; i < g->edges[u].size(); i++ ) {
            int x = g->edges[u][i];
            if (!visited[x]) {
                st.push(u);
                st.push(x);
                visited[x] = true;
                break;
            }
        }
    }
    return path.size();
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g->edges[u].push_back(v);
        g->edges[v].push_back(u);
    }
    cout << hasEulerCircuit(g);
}
