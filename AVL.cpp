//This C++ code implements an AVL tree, a self-balancing binary search tree
//The AVL tree maintains its height-balanced property by performing rotations
//during insertion and deletion operations to ensure that the difference in heights
//between the left and right subtrees of any node is at most one

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
};

int height(Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

Node* newNode(int newkey) {
    Node* newNode = new Node;
    newNode->key = newkey;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return(newNode);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *tmpNode = x->right;
    x->right = y;
    y->left = tmpNode;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *tmpNode = y->left;
    y->left = x;
    x->right = tmpNode;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* currNode, int key) {
    if (currNode == NULL)
        return(newNode(key));
    if (key < currNode->key)
        currNode->left = insert(currNode->left, key);
    else if (key > currNode->key)
        currNode->right = insert(currNode->right, key);
    else
        return currNode;

    currNode->height = 1 + max(height(currNode->left), height(currNode->right));

    int balance = getBalance(currNode);

    if (balance > 1 && key < currNode->left->key)
        return rightRotate(currNode);

    if (balance < -1 && key > currNode->right->key)
        return leftRotate(currNode);

    if (balance > 1 && key > currNode->left->key) {
        currNode->left = leftRotate(currNode->left);
        return rightRotate(currNode);
    }

    if (balance < -1 && key < currNode->right->key) {
        currNode->right = rightRotate(currNode->right);
        return leftRotate(currNode);
    }
    return currNode;
}

Node * minValueNode(Node* subtree) {
    Node* current = subtree;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int keyToDelete) {

    if (root == NULL)
        return root;

    if (keyToDelete < root->key )
        root->left = deleteNode(root->left, keyToDelete);
    else if(keyToDelete > root->key )
        root->right = deleteNode(root->right, keyToDelete);
    else {
        if( (root->left == NULL) || (root->right == NULL) ) {
            Node *temp = root->left ?
                         root->left :
                         root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            // διαγραφή διαδόχου
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the new AVL tree:\n";
    preOrder(root);
    return 0;
}