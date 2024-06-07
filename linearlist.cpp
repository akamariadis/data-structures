//This C++ code implements several fundamental operations for singly linked lists
//including insertion, deletion, searching, concatenation, and reversal
#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

typedef node *list;

//insert in the end of the linear list

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

//insert after a given point of the linear list

void insertafterp (node *p, int data) {
    if (p != nullptr) {
        node *q = new node;
        q -> info = data;
        q -> next = p -> next;
        p ->next = q;
    }
}

//delete after a given point of the linear list

void deleteafterp (node *p) {
    if ((p != nullptr) && (p -> next != nullptr)) {
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }
}

//search algorithm

node *search (list l, int data) {
    node *p;

    for (p = l; p != nullptr; p = p -> next) {
        if (p -> info == data) {
            return p;
        }
    }
    return nullptr;
}

//mix 2 linear lists

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

//reverse a linear list

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

int main () {
    //only insert in the end of the linear ist
    node *list = insertend ();
    return 0;
}