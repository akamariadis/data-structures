#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    vector<Node *>children;
};

Node *newNode(int newKey) {
    Node *temp = new Node;
    temp->key = newKey;
    return temp;
}

int height(Node *r){
    if (r==NULL) return -1;
    int h=-1;
    for (Node *child: r->children) h = max(h, height(child));
    return h+1;
}

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

void LevelOrderTraversal(Node * root) {
    if (root==NULL) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n > 0) {
            Node * p = q.front();
            q.pop(); n--;
            cout << p->key << " ";
            for (int i=0; i<p->children.size(); i++)
                q.push(p->children[i]);
        }
        cout << endl;
    }
}

int main () {
    Node *root = newNode(7);
    (root->children).push_back(newNode(5));
    (root->children).push_back(newNode(10));
    (root->children[0]->children).push_back(newNode(3));
    (root->children[0]->children).push_back(newNode(6));
    (root->children[0]->children).push_back(newNode(9));
    (root->children[0]->children[0]->children).push_back(newNode(2));
    (root->children[1]->children).push_back(newNode(11));
    (root->children[1]->children[0]->children).push_back(newNode(4));
    cout << "Level order traversal\n";
    LevelOrderTraversal(root);
    cout << "h=" << height(root) << endl;
    Node *S = searchTree(root,99);
    if (S != NULL)
        cout << "found\n";
    else
        cout << "not found\n";
    return 0;
}
