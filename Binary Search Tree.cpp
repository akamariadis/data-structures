#include <iostream>

using namespace std;

struct node {
    int info;
    node *left, *right;
};

class tree {
public:
    tree() {
        root = nullptr;
    }
    node *insert_aux (node *t, int data) {
        if (t == nullptr) {
            node *p = new node;
            p -> info = data;
            p -> left = nullptr;
            p -> right = nullptr;
            return p;
        }
        if (t -> info > data) t -> left = insert_aux(t -> left, data);
        else t -> right = insert_aux(t -> right, data);
        return t;
    }
    void insert(int data) {
        root = insert_aux (root, data);
    }
    void print_aux (node *t) {
        if (t != nullptr) {
            cout << t -> info << endl;
            print_aux(t -> left);
            print_aux(t -> right);
        }
    }
    void print () {
        print_aux (root);
    }
private:
    node *root;
};

int main () {
    tree t;
    for (int i = 1; i < 8; ++i) t.insert(i);
    t.print();
    return 0;
}
