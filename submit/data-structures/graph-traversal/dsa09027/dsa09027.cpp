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
void dfs(Graph *g, Vertex v);
void dfsRec(Graph *g, Vertex v, Vertex *predecessor, bool *visited);
void dfsNotRec(Graph *g, Vertex v, Vertex *predecessor);
bool hasPath(Graph *g, Vertex src, Vertex dest, Vertex *predecessor);
bool dfsHasPath(Graph *g, Vertex v, Vertex dest, bool *visited);
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    // testCase();
    return 0;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = GraphNew(nV);
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        GraphInsertEdge(g, v - 1, w - 1);
    }
    // GraphShow(g);
    Vertex *predecessor = new Vertex[g->nV];
    for (Vertex i = 0; i < g->nV; i++) {
        predecessor[i] = -1;
    }
    
    dfsNotRec(g, 0, predecessor);
    // for (Vertex i = 0; i < g->nV; i++) {
    //     cout << predecessor[i] << " ";
    // }
    int q;
    cin >> q;
    while (q--) {
        Vertex src, dest;
        cin >> src >> dest;
        if (hasPath(g, src - 1, dest - 1, predecessor)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
bool hasPath(Graph *g, Vertex src, Vertex dest, Vertex *predecessor) {
    if (predecessor[dest] == -1) {
        return false;
    } else {
        // cout << dest << " ";
        Vertex u = predecessor[dest];
        while (u != src && u != -1) {
            // cout << u << " ";
            u = predecessor[u];
            // cout << u << " ";
        }
        if (u == -1) {
            return false;
        } 
        return true;
    }
}
void dfsNotRec(Graph *g, Vertex v, Vertex *predecessor) {
    bool *visited = new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
    
    stack<Vertex> st;
    st.push(v);
    visited[v] = true;
    while (!st.empty()) {
        Vertex w = st.top();
        st.pop();
        adjNode *curr = g->edges[w];
        for (; curr != NULL; curr = curr->next) {
            if (!visited[curr->v]) {
                st.push(w);
                st.push(curr->v);
                visited[curr->v] = true;
                predecessor[curr->v] = w;
                break;
            }
        }
    }

}
void dfs(Graph *g, Vertex v) {
    Vertex *predecessor = new Vertex[g->nV];
    for (int i = 0; i < g->nV; i++) {
        predecessor[i] = -1;
    }
    bool *visited = new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
    for (Vertex v = 0; v < g->nV; v++) {
        if (predecessor[v] == -1) {
            dfsRec(g, v, predecessor, visited);
        }
    }
}
void dfsRec(Graph *g, Vertex v, Vertex *predecessor, bool *visited) {
    visited[v] = true;

    adjNode *curr = g->edges[v];
    for (; curr != NULL; curr = curr->next) {
        if (!visited[curr->v]) {
            predecessor[curr->v] = v;
            dfsRec(g, curr->v,predecessor, visited);
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
// void GraphInput(Graph *g) {
//     for (Vertex i = 0 ; i < g->nV; i++) {
//         for (Vertex j = 0; j < g->nV; j++) {
//             cin >> g->edges[i][j];
//             g->nE += g->edges[i][j];
//         }
//     }
// }