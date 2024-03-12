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
bool sameDeg(Graph *g, int v);
bool hasEulerCircuit(Graph *g);
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
bool sameDeg(Graph *g, int v) {
    int in = 0, out = 0;
    for (int i = 0; i < g->nV; i++) {
        if (i == v) {
            for (int j = 0; j < g->edges[i].size(); j++) {
                out++; 
            }
        } else {
            for (int j = 0; j < g->edges[i].size(); j++) {
                if (g->edges[i][j] == v) {
                    in++;
                }
            }
        }
        
        
    }
    // cout << "in: " << in << ", out : " << out << endl;
    return in == out;
}
bool hasEulerCircuit(Graph *g) {
    bool visited[g->nV];
    for (int i = 0; i < g->nV; i++){
        visited[i] = false;
    }
    int total = dfs(g, 0, visited);
    if (total != g->nV) {
        return false;
    }
    for (int i = 0; i < g->nV; i++) {
        if (!sameDeg(g, i)) {
            return false;
        }
    }
    return true;
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
    // for (auto x : path) {
    //     cout << x << " ";
    // }
    // cout<< endl;
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
    }
    cout << hasEulerCircuit(g);
}