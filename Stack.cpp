//This C++ code defines and demonstrates the use of a simple stack class
//implemented using an array
#include <iostream>

using namespace std;

class stack {
public:
    stack() {
        top = 0;
    }
    bool empty() {
        return top == 0;
    }
    void insert(int info) {
        data[top++] = info;
    }
    int print_delete() {
        return data[--top];
    }
private:
    static const int size = 10;
    int data[size];
    int top;
};

int main () {
    stack s;
    for (int i = 0; i < 10; ++i) s.insert(i);
    for (int i = 0; i < 10; ++i) cout << s.print_delete() << endl;
    return 0;
}