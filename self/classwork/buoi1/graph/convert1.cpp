#include <bits/stdc++.h>
using namespace std;

typedef int Vertex; // Define Vertex as an alias for int

struct edge{
    Vertex v;
    Vertex w;
};

struct Graph_ArrayOfEdges{
    int nV;
    int nE;
    edge edges[1001];
    int adjMatrix[1001][1001]; // Add adjMatrix member
};

void toAdjacencyMatrix(Graph_ArrayOfEdges *g) {
    memset(g->adjMatrix, 0, sizeof(g->adjMatrix)); // Initialize adjMatrix with 0
    
    for (int i = 0; i < g->nE; i++) {
        g->adjMatrix[g->edges[i].v][g->edges[i].w] = 1;
        g->adjMatrix[g->edges[i].w][g->edges[i].v] = 1;
    }
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            cout << g->adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void toAdjacencyList(Graph_ArrayOfEdges *g) {
    vector<int> adjList[1001];
    for (int i = 0; i < g->nE; i++) {
        adjList[g->edges[i].v].push_back(g->edges[i].w);
        adjList[g->edges[i].w].push_back(g->edges[i].v);
    }
    for (int i = 0; i < g->nV; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] + 1 << " ";
        }
        cout << endl;
    }
}
int main () {
    
    Graph_ArrayOfEdges *g = new Graph_ArrayOfEdges();
    int nV, nE;
    cin >> nV >> nE;
    g->nV = nV;
    g->nE = nE;

    for (int i = 0; i < nE; i++) {
        int x, y;
        cin >> x >> y;
        g->edges[i].v = x - 1;
        g->edges[i].w = y - 1;
        // cin >> g->edges[i].v >> g->edges[i].w;
    }    
    // toAdjacencyMatrix(g);
    toAdjacencyList(g);

    return 0;
    
}