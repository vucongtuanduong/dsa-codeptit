#include <iostream>
using namespace std;
struct Graph{
    int nR;//number of rows
    int nC;//number of columns
    int edges[501][501];
};
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};//remove (0,0) as initial 
int dy[] = {-1, 0, 1, -1, 1,-1, 0, 1};//remove (0,0) as initial
void testCase();
void dfs(Graph *g, int i, int j);
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
void dfs(Graph *g, int i, int j) {
    g->edges[i][j] = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < g->nR && y >= 0 && y < g->nC && g->edges[x][y] == 1) {
            dfs(g, x, y);
        }
    }
}
void testCase() {
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph;
    g->nR = n;
    g->nC = m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g->edges[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g->edges[i][j] == 1) {
                count++;
                dfs(g, i, j);
            }
        }
    }
    cout << count;

    delete g;

}