#include <bits/stdc++.h>
using namespace std;

struct Graph_AdjacencyMatrix{
    int nV;
    int nE;
    int edges[1001][1001];
};
void toAdjacencyList(Graph_AdjacencyMatrix *g) {
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}
void toArrayOfEdges(Graph_AdjacencyMatrix *g) {
    for (int i = 0; i < g->nV; i++) {
        for (int j = i + 1; j < g->nV; j++) {
            if (g->edges[i][j] == 1) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}
int main () {
    
    Graph_AdjacencyMatrix *g = new Graph_AdjacencyMatrix;
    int nV;
    cin >> nV;
    g->nV = nV;
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            cin >> g->edges[i][j];
        }
    }
    cout << "Adjacency List:" << endl;
    toAdjacencyList(g);
    cout << endl;
    cout << "Array of Edges:" << endl;
    toArrayOfEdges(g);
    cout << endl;
    return 0;
    
}