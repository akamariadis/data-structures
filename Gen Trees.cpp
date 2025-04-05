#include <iostream>
#include <queue>
using namespace std;

struct node {
    int key;
    vector<node *>children;
};

node *newnode(int newkey) {
    node *temp = new node;
    temp -> key = newkey;
    return temp;
}

int height(node *r){
    if (r == NULL) return -1;
    int h =- 1;
    for (node *child: r -> children) h = max(h, height(child));
    return h+1;
}

node * searchTree(node *r, const int &k) {
    if (r != nullptr) {
        if (r -> key == k) return r;
        for (node *child: r -> children) {
            node *s = searchTree(child, k);
            if (s != nullptr) return s;
        }
    }
    return nullptr;
}

void LevelOrderTraversal(node * root) {
    if (root == NULL) return;
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n > 0) {
            node * p = q.front();
            q.pop(); n--;
            cout << p -> key << " ";
            for (int i = 0; i < p -> children.size(); i++)
                q.push(p -> children[i]);
        }
        cout << endl;
    }
}

int main () {
    node *root = newnode(7);
    (root->children).push_back(newnode(5));
    (root->children).push_back(newnode(10));
    (root->children[0]->children).push_back(newnode(3));
    (root->children[0]->children).push_back(newnode(6));
    (root->children[0]->children).push_back(newnode(9));
    (root->children[0]->children[0]->children).push_back(newnode(2));
    (root->children[1]->children).push_back(newnode(11));
    (root->children[1]->children[0]->children).push_back(newnode(4));
    cout << "Level order traversal\n";
    LevelOrderTraversal(root);
    cout << "h=" << height(root) << endl;
    node *S = searchTree(root,99);
    if (S != NULL)
        cout << "found\n";
    else
        cout << "not found\n";
    return 0;
}
