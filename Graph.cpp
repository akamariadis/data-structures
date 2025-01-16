#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void DFS(int s) {
        vector<bool> visited(V, false);
        stack<int> stack;
        stack.push(s);
        while (!stack.empty()) {
            s = stack.top();
            stack.pop();
            if (!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
                if (!visited[*i]) stack.push(*i);
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    cout << "Depth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    return 0;
}
