#include <iostream>
#include <vector>
#include <limits>
#include <set>
using namespace std;

struct Edge {
    int u, v, cost;
};

void dijkstra(int n, int source, const vector<Edge>& edges) {
    const int INF = numeric_limits<int>::max();
    vector<int> D(n, INF);
    vector<int> P(n, -1);
    set<int> S;

    D[source] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (S.find(v) == S.end() && (u == -1 || D[v] < D[u])) {
                u = v;
            }
        }

        if (D[u] == INF) break;

        S.insert(u);
        for (const Edge& edge : edges) {
            if (edge.u == u) {
                int v = edge.v;
                int cost = edge.cost;
                if (S.find(v) == S.end() && D[u] + cost < D[v]) {
                    D[v] = D[u] + cost;
                    P[v] = u;
                }
            }
        }
    }

    cout << "Vertex\tDistance from Source\tPredecessor\n";
    for (int v = 0; v < n; ++v) {
        cout << v << "\t" << (D[v] == INF ? "INF" : to_string(D[v])) << "\t\t" << (P[v] == -1 ? "NIL" : to_string(P[v])) << "\n";
    }
}

int main() {
    int n = 5;
    int source = 0;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 3, 5},
        {1, 2, 1}, {1, 3, 2},
        {2, 4, 4},
        {3, 1, 3}, {3, 2, 9}, {3, 4, 2},
        {4, 2, 6}, {4, 0, 7}
    };
    dijkstra(n, source, edges);
    return 0;
}
