#include <iostream>
#include <cstdio>
using namespace std;

struct node {
    int info;
    node *next;
};

node* read () {
    node *head = nullptr;
    node *n;
    int data;
    while (scanf("%d", &data) == 1) {
        n = new node;
        n -> info = data;
        n -> next = head;
        head = n;
    }
    return head;
}

void print (node *p) {
    while (p != nullptr) {
        cout << p -> info;
        p = p -> next;
    }
}

int main () {
    node *list = read();
    print(list);
    return 0;
}
