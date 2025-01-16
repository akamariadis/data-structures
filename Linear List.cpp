#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

typedef node *list;

void insertend (list &l, int data) {
    node *p, *q;
    p = new node;
    p -> info = data;
    p -> next = nullptr;
    if (l == nullptr) {
        l = p;
    }
    else {
        q = l;
        while (q -> next != nullptr) {
            q = q -> next;
        }
        q -> next = q;
    }
}

void insertafterp (node *p, int data) {
    if (p != nullptr) {
        node *q = new node;
        q -> info = data;
        q -> next = p -> next;
        p ->next = q;
    }
}

void deleteafterp (node *p) {
    if ((p != nullptr) && (p -> next != nullptr)) {
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }
}

node *search (list l, int data) {
    node *p;
    for (p = l; p != nullptr; p = p -> next) {
        if (p -> info == data) {
            return p;
        }
    }
    return nullptr;
}

void concat (list &l1, list l2) {
    node *p;
    if (l2 == nullptr) {
        return;
    }
    if (l1 == nullptr) {
        l1 = l2;
    }
    else {
        p = l1;
        while (p -> next != nullptr) {
            p = p -> next;
        }
        p -> next = l2;
    }
}

void reverse (list &l) {
    node *p, *q;
    q = nullptr;
    while (l != nullptr) {
        p = l;
        l = p -> next;
        p -> next = q;
        q = p;
    }
    l = q;
}
