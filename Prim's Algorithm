#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int v, weight;
};

void primsAlgorithm(int n, vector<vector<Edge>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    int src = 0;
    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (const auto& edge : graph[u]) {
            int v = edge.v;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    cout << "Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
            totalWeight += key[i];
        }
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    primsAlgorithm(n, graph);
    return 0;
}
