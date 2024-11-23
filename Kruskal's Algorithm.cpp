#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
private:
    vector<int> parent, rank;
};

void kruskalAlgorithm(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    UnionFind uf(n);
    vector<Edge> mst;
    int totalWeight = 0;
    for (const auto& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
        if (mst.size() == n - 1) {
            break;
        }
    }
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")" << endl;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    kruskalAlgorithm(n, edges);

    return 0;
}
