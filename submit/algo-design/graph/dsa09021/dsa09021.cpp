#include <iostream>
using namespace std;
struct Graph{
    int nV;
    int nE;
    bool edges[1001][1001];
};
int main() {
    // Write your code here
    int nV;
    cin >> nV;
    Graph *g = new Graph;
    g->nV = nV;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> g->edges[i][j];
            g->nE += g->edges[i][j];
        }
    }   
    g->nE /= 2;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (g->edges[i][j]) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
