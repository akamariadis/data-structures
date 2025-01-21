#include <iostream>
using namespace std;

struct node {
    int key;
    Node *left, *right;
    int height;
};

int height(node *N) {
    if (N == NULL) return 0;
    return N -> height;
}

node* newnode(int newkey) {
    node* newnode = new node;
    newnode -> key = newkey;
    newnode -> left = newnode -> right = NULL;
    newnode -> height = 1;
    return(newnode);
}

node *rightRotate(node *y) {
    node *x = y -> left;
    node *tmpnode = x -> right;
    x -> right = y;
    y -> left = tmpnode;
    y -> height = max(height(y->left), height(y->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node *leftRotate(node *x) {
    node *y = x -> right;
    node *tmpnode = y -> left;
    y -> left = x;
    x -> right = tmpnode;
    x -> height = max(height(x->left), height(x->right)) + 1;
    y -> height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(node *N) {
    if (N == NULL) return 0;
    return height(N -> left) - height(N -> right);
}

node* insert(node* currnode, int key) {
    if (currnode == NULL)
        return(newnode(key));
    if (key < currnode->key)
        currnode -> left = insert(currnode -> left, key);
    else if (key > currnode->key)
        currnode -> right = insert(currnode -> right, key);
    else
        return currnode;
    currnode -> height = 1 + max(height(currnode->left), height(currnode->right));
    int balance = getBalance(currnode);
    if (balance > 1 && key < currnode -> left -> key)
        return rightRotate(currnode);
    if (balance < -1 && key > currnode -> right -> key)
        return leftRotate(currnode);
    if (balance > 1 && key > currnode -> left -> key) {
        currnode -> left = leftRotate(currnode -> left);
        return rightRotate(currnode);
    }
    if (balance < -1 && key < currnode -> right -> key) {
        currnode -> right = rightRotate(currnode -> right);
        return leftRotate(currnode);
    }
    return currnode;
}

node * minValueNode(node* subtree) {
    node* current = subtree;
    while (current -> left != NULL)
        current = current -> left;
    return current;
}

node* deleteNode(node* root, int keyToDelete) {
    if (root == NULL)
        return root;
    if (keyToDelete < root->key )
        root -> left = deleteNode(root -> left, keyToDelete);
    else if(keyToDelete > root -> key )
        root -> right = deleteNode(root -> right, keyToDelete);
    else {
        if( (root -> left == NULL) || (root -> right == NULL) ) {
            node *temp = root -> left ?
                         root -> left :
                         root -> right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            node* temp = minValueNode(root -> right);
            root -> key = temp -> key;
            root -> right = deleteNode(root -> right,
                                     temp -> key);
        }
    }
    if (root == NULL)
        return root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root -> left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root -> left) < 0) {
        root->left = leftRotate(root -> left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root -> right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root -> right) > 0) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(node *root) {
    if (root != NULL) {
        cout << root -> key << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

int main() {
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the new AVL tree:" << endl;
    preOrder(root);
    return 0;
}
