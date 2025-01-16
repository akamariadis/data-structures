#include <iostream>
using namespace std;

class list {
public:
    list ();
    bool empty ();
    void push (int x);
    int pop ();
private:
    struct node {
        int info;
        node *next;
    };
    node *head;
};

list::list () {
    head = nullptr;
}

bool list::empty () {
    return head == nullptr;
}

void list::push (int x) {
    node *p = new node;
    p -> info = x;
    p -> next = nullptr;
    head = p;
}

int list::pop () {
    node *p = new node;
    int result = head -> info;
    head = head -> next;
    delete p;
    return result;
}

int main () {
    list s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << s.pop() << endl;
    }
    return 0;
}
