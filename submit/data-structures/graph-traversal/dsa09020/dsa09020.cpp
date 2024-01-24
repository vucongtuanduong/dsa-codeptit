#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    bool **edges;
};
typedef int Vertex;
/**
 * Returns a new graph with nV vertices
 */
Graph *GraphNew(int nV);

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph *g);

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph *g);

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph *g);

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w);

/**
 * Adds an edge between v and w
 */
void GraphInsertEdge(Graph *g, Vertex v, Vertex w);

/**
 * Removes an edge between v and w
 */
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w);

/**
 * Returns the degree of a vertex
 */
int GraphDegree(Graph *g, Vertex v);

/**
 * Displays a graph
 */
void GraphShow(Graph *g);

void GraphInput(Graph *g);
void testCase();
int main () {
    testCase();
    return 0;
}
void testCase() {
    int nV;
    cin >> nV;
    Graph *g = GraphNew(nV);
    for (int i = 0; i < nV; i++) {
        int v, w;
        cin >> v >> w;
        GraphInsertEdge(g, v - 1, w - 1);
    }
    GraphShow(g);
}
Graph *GraphNew(int nV) {
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    g->edges = new bool*[nV];
    for (int i = 0; i < nV; i++) {
        g->edges[i] = new bool[nV];
        for (int j = 0; j < nV; j++) {
            g->edges[i][j] = false;
        }
    }
    return g;

}
void GraphFree(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        delete[] g->edges[i];
    }
    delete[] g->edges;
    delete g;
}
int GraphNumVertices(Graph *g) {
    return g->nV;
}
int GraphNumEdges(Graph *g) {
    return g->nE;
}
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w) {
    return g->edges[v][w];
}
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
    if (!g->edges[v][w]) {
        g->edges[v][w] = 1;
        g->edges[w][v] = 1;
        g->nE++;
    }
}
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
	if (g->edges[v][w]) {
		g->edges[v][w] = 0;
		g->edges[w][v] = 0;
		g->nE--;
	}
}
void GraphShow(Graph *g) {
	for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            cout << g->edges[i][j] << " ";
        }
        cout << endl;
    }
}
int GraphDegree(Graph *g, Vertex v) {


	int degree = 0;
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w]) {
			degree++;
		}
	}

	return degree;
}
// void GraphInput(Graph *g) {
//     for (Vertex i = 0 ; i < g->nV; i++) {
//         for (Vertex j = 0; j < g->nV; j++) {
//             cin >> g->edges[i][j];
//             g->nE += g->edges[i][j];
//         }
//     }
// }