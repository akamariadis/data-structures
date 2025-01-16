//
// NTUA ECE ProgTech 2022-2023
//
// Generic trees
//
// Δείτε τα Run configurations στο αρχείο CMakeLists.txt
// Προσοχή: σε κάθε αλλαγή που κάνετε στο CMakeLists.txt *πρέπει* να κάνετε "Reload changes" ή "Reload CMake project"
//
// Επιλέξτε: (menu)Run -> (option)Run... -> gen_Trees
//

#include <iostream>
#include <queue>

using namespace std;

// κόμβος
struct Node {
    int key;
    vector<Node *>children;
};

// Δημιουργία κόμβου
Node *newNode(int newKey) {
    Node *temp = new Node;
    temp->key = newKey;
    return temp;
}

// Υψος
int height(Node *r){
    if (r==NULL) return -1;
    int h=-1;
    for (Node *child: r->children) h = max(h, height(child));
    return h+1;
}

// Αναζήτηση
Node * searchTree(Node *r, const int &k) {
    if (r != nullptr) {
        if (r->key == k) return r;
        for (Node *child: r->children) {
            Node *s = searchTree(child, k);
            if (s != nullptr) return s;
        }
    }
    return nullptr;
}

// Διάσχιση κατά πλάτος
void LevelOrderTraversal(Node * root)
{
    if (root==NULL) return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();   // μέγεθος του vector
        while (n > 0) {
            Node * p = q.front();  // αφαίρεση του πρώτου στοιχείου της ουράς και εκτύπωση
            q.pop(); n--;
            cout << p->key << " ";

            // Αν έχει παιδιά, βάλε τα στην ουρά
            for (int i=0; i<p->children.size(); i++)
                q.push(p->children[i]);
        }
        cout << endl; // επόμενο επίπεδο
    }
}

int main() {
    // Δένδρο Γ, διαφάνεια 4
    Node *root = newNode(7);
    (root->children).push_back(newNode(5));
    (root->children).push_back(newNode(10));
    (root->children[0]->children).push_back(newNode(3));          // root->children[0] περιέχει το 5
    (root->children[0]->children).push_back(newNode(6));
    (root->children[0]->children).push_back(newNode(9));
    (root->children[0]->children[0]->children).push_back(newNode(2));
    (root->children[1]->children).push_back(newNode(11));          // root->children[0] περιέχει 10
    (root->children[1]->children[0]->children).push_back(newNode(4));

    cout << "Level order traversal\n";
    LevelOrderTraversal(root);
    cout << "h=" << height(root) << endl;

    Node *S = searchTree(root,99);
    if (S !=NULL)
        cout << "found\n";
    else
        cout << "not found\n";

    return 0;
}