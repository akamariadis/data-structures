#include <iostream>
#include <map>

using namespace std;

class weightedDirectedGraph {
public:
    weightedDirectedGraph(): adj({}) {}
    int size() {return adj.size(); }
    void addEdge(int f, int t, int c) {
        adj[f].push_back(make_pair(t,c));
    }
    void print() {
        for (auto const & vertex:adj) {
            cout << endl << "[" << vertex.first << "]";
            for (auto adjV:vertex.second)
                cout << " -> " << adjV.first << "(" <<adjV.second<<")";
        }
    }

    // neighbours
    vector<pair<int,int>> neighbours(const int & nn) {
        // αν το στοιχείο υπάρχει, έχει μέγεθος !=0, οπότε απλά το επιστρέφουμε
        if (adj[nn].size()) return adj[nn];

        // αν το στοιχείο δεν υπάρχει, θα δημιουργηθεί, αλλά αυτό δε μας χρειάζεται.
        adj.erase(nn);
        return {};
    }
private:
    // map (int) -> vector of pairs(int, int)
    // (node) ->  [ (node, cost), (node, cost), ...]
    map<int,vector<pair<int,int>>> adj;

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
    cout << endl << "n of vertices = " << nsg.size();

    cout << "\nNeighbours of 3\n";
    for (auto v:nsg.neighbours(3)) {
        cout << "-> " << v.first << "(" << v.second<<")" ;
    }
}

//
// NTUA ECE ProgTech 2022-2023
//
// Directed weighted graphs
//
// Δείτε τα Run configurations στο αρχείο CMakeLists.txt
// Προσοχή: σε κάθε αλλαγή που κάνετε στο CMakeLists.txt *πρέπει* να κάνετε "Reload changes" ή "Reload CMake project"
//
// Επιλέξτε: (menu)Run -> (option)Run... -> weightedDirected
//