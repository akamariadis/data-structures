#include <iostream>
#include <map>
#include <vector>
using namespace std;

class weightedDirectedGraph {
public:
    weightedDirectedGraph() = default;
    int size() const {
        return adj.size();
    }
    void addEdge(int f, int t, int c) {
        adj[f].push_back(make_pair(t, c));
    }
    void print() const {
        for (const auto& vertex : adj) {
            cout << "\n[" << vertex.first << "]";
            for (const auto& adjV : vertex.second)
                cout << " -> " << adjV.first << "(" << adjV.second << ")";
        }
    }
    vector<pair<int, int>> neighbours(const int& nn) const {
        auto it = adj.find(nn);
        if (it != adj.end()) return it->second;
        return {};
    }
private:
    map<int, vector<pair<int, int>>> adj;
};

int main() {
    weightedDirectedGraph nsg;
    nsg.addEdge(1, 3, 10);
    nsg.addEdge(2, 1, 0);
    nsg.addEdge(3, 2, 20);
    nsg.addEdge(3, 4, 5);
    nsg.addEdge(2, 4, 40);
    nsg.addEdge(4, 2, 30);
    nsg.addEdge(3, 5, 15);
    nsg.addEdge(5, 6, 25);
    nsg.addEdge(6, 3, 35);
    nsg.addEdge(4, 6, 45);
    nsg.print();
    cout << nsg.size();
    for (const auto& v : nsg.neighbours(3)) {
        cout << "-> " << v.first << "(" << v.second << ")";
    }
    cout << endl;
    return 0;
}
