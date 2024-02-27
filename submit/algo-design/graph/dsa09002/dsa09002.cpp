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

void testCase();

int main () {
    // int t;
    // cin >> t;
    // while (t--) {
    //     testCase();
    //     cout << endl;
    // }
    testCase();
    return 0;
}
void testCase() {
    int nV;
    cin >> nV;
    cin.ignore();
    Graph *g = GraphNew(nV);
    for (int i = 0; i < nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> s) {
            int w = stoi(s);
            GraphInsertEdge(g, i, w - 1);
        }
        // GraphInsertEdge(g, v - 1, w - 1);
    }
    GraphShow(g);
    // dfsNotRec(g, v - 1);
}
void dfsNotRec(Graph *g, Vertex v) {
    bool *visited = new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
    stack<Vertex> st;
    st.push(v);
    visited[v] = true;
    set<Vertex> traversedVertex;
    cout << v + 1 << " ";
    while (!st.empty()) {
        Vertex x = st.top();
        st.pop();
        traversedVertex.insert(x);
        adjNode *curr = g->edges[x];
        for (; curr != NULL; curr = curr->next) {
            if (!visited[curr->v]) {
                if (traversedVertex.find(curr->v) != traversedVertex.end()) {
                    continue;
                } else {
                    cout << curr->v + 1 << " ";
                }
                st.push(x);
                st.push(curr->v);
                visited[curr->v] = true;
                break;
            }
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
        adjNode *curr2 = g->edges[w];
        adjNode *prev2 = NULL;
        while (curr2 != NULL && curr2->v < v) {
            prev2 = curr2;
            curr2 = curr2->next;
        }
        adjNode *newNode2 = new adjNode;
        newNode2->v = v;
        newNode2->next = curr2;
        if (prev2 == NULL) {
            g->edges[w] = newNode2;
        } else {
            prev2->next = newNode2;
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
        adjNode *curr2 = g->edges[w];
        adjNode *prev2 = NULL;
        while (curr2 != NULL && curr2->v < v) {
            prev2 = curr2;
            curr2 = curr2->next;
        }
        if (prev2 == NULL) {
            g->edges[w] = curr2->next;
        } else {
            prev2->next = curr2->next;
        }
        delete curr2;
        g->nE--;
    }
}
void GraphShow(Graph *g) {
    for (Vertex v = 0; v < g->nV; v++) {
        // cout << v + 1 << ": ";
        adjNode *curr = g->edges[v];
        while (curr != NULL) {
            if (curr->v > v) {
                cout << v + 1 << " " << curr->v + 1 << " ";
                cout << endl;
            }
            
            curr = curr->next;
        }
        // cout << endl;
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
