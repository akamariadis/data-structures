#include <iostream>
#include <map>
#include <vector>
using namespace std;

class nonDirected {
public:
    nonDirected() = default;
    int size() const {
        return adj.size();
    }
    void addEdge(int f, int t) {
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    void print() const {
        for (const auto& vertex : adj) {
            cout << "\n[" << vertex.first << "]";
            for (int neighbor : vertex.second)
                cout << " -> " << neighbor;
        }
    }
    vector<int> neighbours(const int& n) const {
        auto it = adj.find(n);
        if (it != adj.end()) return it->second;
        return {};
    }
private:
    map<int, vector<int>> adj;
};

int main() {
    nonDirected sg;
    sg.addEdge(1, 2);
    sg.addEdge(1, 3);
    sg.addEdge(2, 3);
    sg.addEdge(3, 4);
    sg.addEdge(3, 5);
    sg.addEdge(4, 6);
    sg.print();
    cout << sg.size();
    for (int nn : sg.neighbours(1))
        cout << nn << " -> ";
    cout << "null\n";
    for (int nn : sg.neighbours(7))
        cout << nn << " -> ";
    cout << "null\n";
    return 0;
}
