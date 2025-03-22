#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, cost;
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v, int cost) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    void uniformCostSearch(int start, int goal) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, start});
        dist[start] = 0;
        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == goal) {
                cout << "Shortest path cost from " << start << " to " << goal << " is: " << cost << endl;
                return;
            }
            for (auto &edge : adj[node]) {
                int new_cost = cost + edge.cost;
                if (new_cost < dist[edge.to]) {
                    dist[edge.to] = new_cost;
                    pq.push({new_cost, edge.to});
                }
            }
        }
        cout << "No path found from " << start << " to " << goal << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);
    int start = 0, goal = 5;
    g.uniformCostSearch(start, goal);
    return 0;
}
