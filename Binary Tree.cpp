#include <iostream>
using namespace std;

struct node {
    int info;
    node *left, *right;
};

class tree {
public:
    tree ();
    void insert (int key);
    void print ();
private:
    node *root;
};

tree::tree () {
    root = nullptr;
}

node *insert_aux (node *t, int key) {
    if (t == nullptr) {
        node *p = new node;
        p -> info = key;
        p -> left = p -> right = nullptr;
        return p;
    }
    if (t -> info > key) {
        t -> left = insert_aux (t -> left, key);
    }
    else {
        t -> right = insert_aux (t -> right, key);
    }
    return t;
}

void tree::insert (int key) {
    root = insert_aux (root, key);
}

void inorder_aux (node *t) {
    if (t != nullptr) {
        inorder_aux (t -> left);
        cout << t -> info << " ";
        inorder_aux (t -> right);
    }
}

void tree::print () {
    inorder_aux (root);
}

void preorder (node *t) {
    if (t != nullptr) {
        cout << t -> info << endl;
        preorder (t -> left);
        preorder (t -> right);
    }
}

void postorder (node *t) {
    if (t != nullptr) {
        postorder (t -> left);
        cout << t -> info << endl;
        postorder (t -> right);
    }
}

void inorder (node *t) {
    if (t != nullptr) {
        inorder (t -> left);
        inorder (t -> right);
        cout << t -> info << endl;
    }
}

node *insert2 (node *t, int key) {
    if (t == nullptr) {
        node *p = new node;
        p -> info = key;
        p -> left = p -> right = nullptr;
        return p;
    }
    else {
        if (t -> info > key) {
            t -> left = insert2 (t -> left, key);
        }
        else if (t -> info < key) {
            t -> right = insert2 (t -> right, key);
        }
        return t;
    }
}

node *search (node *t, int key) {
    if (t == nullptr) {
        return nullptr; //not found
    }
    else {
        if (t -> info = key) {
            return t; //found
        }
        if (t -> info > key) {
            return search (t -> left, key);
        }
        else {
            return search (t -> right, key);
        }
    }
}

int NumOfNodes (node *t) {
    if (t == nullptr) {
        return 0;
    }
    else {
        return 1 + NumOfNodes (t -> left) + NumOfNodes (t -> right);
    }
}

int height (node *t) {
    if (t == nullptr) {
        return 0;
    }
    else {
        return 1 + max (height(t -> left), height(t -> right));
    }
}

int main () {
    tree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.print();
    return 0;
}
