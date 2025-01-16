#include <iostream>
#include <map>

using namespace std;

class nonDirected {
public:
    nonDirected(): adj({}) {}

    int size() {
        return adj.size();
    }

    void addEdge(int f, int t) {
        // symmetrical
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    void print() {
        for (auto const & vertex:adj) {
            cout << endl << "[" << vertex.first << "]";
            for (auto adjV:vertex.second)
                cout << " -> " << adjV;
        }
    }

    // return the neighbours
    vector<int> neighbours(const int & n) {
        // αν το στοιχείο υπάρχει, έχει μέγεθος !=0, οπότε απλά το επιστρέφουμε
        if (adj[n].size()) return adj[n];

        // αν το στοιχείο δεν υπάρχει, θα δημιουργηθεί, αλλά αυτό δε μας χρειάζεται.
        adj.erase(n);
        return {};
    }

private:
    map<int,vector<int>> adj;
};

int main() {
    nonDirected sg;
    sg.addEdge(1,2);
    sg.addEdge(1, 3);
    sg.addEdge(2, 3);
    sg.addEdge(3, 4);
    sg.addEdge(3, 5);
    sg.addEdge(4, 6);
    sg.print();
    cout<<endl<<"n of vertices = "<<sg.size();

    cout << "\nNeighbours of 1\n";
    for (auto nn:sg.neighbours(1))
        cout << nn << "->";
    cout << endl;

    cout << "\nNeighbours of 7\n";
    for (auto nn:sg.neighbours(7))
        cout << nn << "->";
    cout << endl;

    return 0;
}

//
// NTUA ECE ProgTech 2022-2023
//
// Non-directed graphs
//
// Δείτε τα Run configurations στο αρχείο CMakeLists.txt
// Προσοχή: σε κάθε αλλαγή που κάνετε στο CMakeLists.txt *πρέπει* να κάνετε "Reload changes" ή "Reload CMake project"
//
// Επιλέξτε: (menu)Run -> (option)Run... -> nonDirected
//