#include <bits/stdc++.h>
using namespace std;
typedef int Vertex;
struct adjNode {
    Vertex v;
    adjNode *next;
};
struct Graph{
    int nV;
    int nE;
    adjNode **edges;
};

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
void testCase2();
void bfs(int a[1001][1001], Vertex v, Vertex src, Vertex dest) ;
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    
    return 0;
}
void testCase() {
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    Graph *g = GraphNew(nV);
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        GraphInsertEdge(g, v - 1, w - 1);
    }
    // GraphShow(g);
    bfs(g, 0, src - 1, dest - 1);
}
void testCase2() {
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    int g[1001][1001];
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            g[i][j] = 0;
        }
    }
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        g[v - 1][w - 1] = 1;
        // GraphInsertEdge(g, v - 1, w - 1);
    }
    // GraphShow(g);
    bfs(g, 0, src - 1, dest - 1);

}
void bfs(int g[1001][1001], Vertex v, Vertex src, Vertex dest) {
    bool *visited = new bool[1001];
    Vertex *predecessor = new Vertex[1001];
    for (int i = 0; i < 1001; i++) {
        visited[i] = false;
        predecessor[i] = -1;
    }
    queue<Vertex> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        Vertex x = q.front();
        q.pop();
        for (int i = 0; i < 1001; i++) {
            if (g[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                predecessor[i] = x;
            }
        }
        // cout << x + 1 << " ";
    }
    if (predecessor[dest] == -1) {
        cout << "-1";
        return;
    } else {
        vector<Vertex> path;
        Vertex curr = dest;
        while (curr != src) {
            path.push_back(curr);
            curr = predecessor[curr];
        }
        path.push_back(src);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] + 1 << " ";
        }
    }
}

Graph *GraphNew(int nV) {
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    g->edges = new adjNode*[nV];
    for (int i = 0; i < nV; i++) {
        // g->edges[i] = new adjNode;
        // g->edges[i]->v = 0;
        // g->edges[i]->next = NULL;
        g->edges[i] = NULL;
    }
    return g;

}
void GraphFree(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        adjNode *curr = g->edges[i];
        while (curr != NULL) {
            adjNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete g;
}
int GraphNumVertices(Graph *g) {
    return g->nV;
}
int GraphNumEdges(Graph *g) {
    return g->nE;
}
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w) {
    adjNode *curr = g->edges[v];
    for (; curr != NULL && curr->v <= w; curr = curr->next) {
        if (curr->v == w) {
            return true;
        }
    }
    return false;
}
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
    if (!GraphIsAdjacent(g, v, w)) {
        adjNode *curr = g->edges[v];
        adjNode *prev = NULL;
        while (curr != NULL && curr->v < w) {
            prev = curr;
            curr = curr->next;
        }
        adjNode *newNode = new adjNode;
        newNode->v = w;
        newNode->next = curr;
        if (prev == NULL) {
            g->edges[v] = newNode;
        } else {
            prev->next = newNode;
        }
        

        g->nE++;

    }
    

}
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
    if (GraphIsAdjacent(g, v, w)) {
        adjNode *curr = g->edges[v];
        adjNode *prev = NULL;
        while (curr != NULL && curr->v < w) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            g->edges[v] = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        
        g->nE--;
    }
}
void GraphShow(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        cout << i + 1 << ": ";
        adjNode *curr = g->edges[i];
        while (curr != NULL) {
            cout << curr->v + 1 << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}
int GraphDegree(Graph *g, Vertex v) {


	int degree = 0;
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		degree++;
	}
	return degree;
}