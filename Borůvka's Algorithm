#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

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
        if (rootX == rootY) return false;
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

void boruvkaAlgorithm(int n, vector<Edge>& edges) {
    UnionFind uf(n);
    vector<int> cheapest(n, -1);
    int totalWeight = 0;
    vector<Edge> mst;

    int components = n;

    while (components > 1) {
        fill(cheapest.begin(), cheapest.end(), -1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].weight;
            int setU = uf.find(u);
            int setV = uf.find(v);
            if (setU != setV) {
                if (cheapest[setU] == -1 || edges[cheapest[setU]].weight > w) {
                    cheapest[setU] = i;
                }
                if (cheapest[setV] == -1 || edges[cheapest[setV]].weight > w) {
                    cheapest[setV] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (cheapest[i] != -1) {
                int u = edges[cheapest[i]].u;
                int v = edges[cheapest[i]].v;
                int w = edges[cheapest[i]].weight;
                int setU = uf.find(u);
                int setV = uf.find(v);
                if (setU != setV) {
                    uf.unionSets(setU, setV);
                    mst.push_back(edges[cheapest[i]]);
                    totalWeight += w;
                    components--;
                }
            }
        }
    }
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
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
    boruvkaAlgorithm(n, edges);
    return 0;
}
