#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

class FibNode {
public:
    int key;
    int degree;
    FibNode* parent;
    FibNode* child;
    FibNode* left;
    FibNode* right;
    bool mark;
    FibNode(int k) : key(k), degree(0), parent(nullptr), child(nullptr), mark(false) {
        left = right = this;
    }
};

class FibonacciHeap {
private:
    FibNode* minNode;
    int n;
    void link(FibNode* y, FibNode* x) {
        y -> left -> right = y -> right;
        y -> right -> left = y -> left;
        y -> parent = x;
        if (!x -> child) {
            x -> child = y;
            y -> left = y -> right = y;
        }
        else {
            y -> left = x -> child;
            y -> right = x -> child -> right;
            x -> child -> right -> left = y;
            x -> child -> right = y;
        }
        x -> degree++;
        y -> mark = false;
    }
    void consolidate() {
        int D = (int)floor(log2(n)) + 1;
        vector<FibNode*> A(D, nullptr);
        if (!minNode) return;
        vector<FibNode*> rootList;
        FibNode* start = minNode;
        FibNode* w = start;
        do {
            rootList.push_back(w);
            w = w -> right;
        } while (w != start);
        for (FibNode* x : rootList) {
            int d = x -> degree;
            while (A[d]) {
                FibNode* y = A[d];
                if (x -> key > y -> key) swap(x, y);
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            if (d >= A.size()) A.resize(d + 1, nullptr);
            A[d] = x;
        }
        minNode = nullptr;
        for (FibNode* node : A) {
            if (node) {
                node -> left = node -> right = node;
                if (!minNode) minNode = node;
                else {
                    node -> left = minNode;
                    node -> right = minNode -> right;
                    minNode -> right -> left = node;
                    minNode -> right = node;
                    if (node -> key < minNode -> key) minNode = node;
                }
            }
        }
    }
    void cut(FibNode* x, FibNode* y) {
        if (x -> right == x) y -> child = nullptr;
        else {
            x -> right -> left = x -> left;
            x -> left -> right = x -> right;
            if (y -> child == x) y -> child = x -> right;
        }
        y -> degree--;
        x -> left = minNode;
        x -> right = minNode -> right;
        minNode -> right -> left = x;
        minNode -> right = x;
        x -> parent = nullptr;
        x -> mark = false;
    }
    void cascadingCut(FibNode* y) {
        FibNode* z = y -> parent;
        if (z) {
            if (!y -> mark) y -> mark = true;
            else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }
    void freeAllNodes(FibNode* start) {
        if (!start) return;
        FibNode* w = start;
        do {
            FibNode* next = w -> right;
            if (w -> child) freeAllNodes(w -> child);
            delete w;
            w = next;
        } while (w != start);
    }
public:
    FibonacciHeap() : minNode(nullptr), n(0) {}
    ~FibonacciHeap() {
      freeAllNodes(minNode);
    }
    FibNode* insert(int key) {
        FibNode* node = new FibNode(key);
        if (!minNode) minNode = node;
        else {
            node -> left = minNode;
            node -> right = minNode -> right;
            minNode -> right -> left = node;
            minNode -> right = node;
            if (key < minNode -> key) minNode = node;
        }
        n++;
        return node;
    }
    int getMin() {
        if (!minNode) throw runtime_error("Heap is empty");
        return minNode -> key;
    }
    int extractMin() {
        FibNode* z = minNode;
        if (!z) throw runtime_error("Heap is empty");
        if (z -> child) {
            vector<FibNode*> children;
            FibNode* start = z -> child;
            FibNode* x = start;
            do {
                children.push_back(x);
                x = x -> right;
            } while (x != start);
            for (FibNode* child : children) {
                child -> left = minNode;
                child -> right = minNode -> right;
                minNode -> right -> left = child;
                minNode -> right = child;
                child -> parent = nullptr;
            }
        }
        z -> left -> right = z -> right;
        z -> right -> left = z -> left;
        if (z == z -> right) minNode = nullptr;
        else {
            minNode = z -> right;
            consolidate();
        }
        n--;
        int minKey = z -> key;
        delete z;
        return minKey;
    }
    void decreaseKey(FibNode* x, int k) {
        if (k > x -> key) throw runtime_error("New key is greater than current key");
        x -> key = k;
        FibNode* y = x -> parent;
        if (y && x -> key < y -> key) {
            cut(x, y);
            cascadingCut(y);
        }
        if (x -> key < minNode -> key) minNode = x;
    }
    bool isEmpty() {
      return minNode == nullptr;
    }
};

int main() {
    FibonacciHeap heap;
    auto n1 = heap.insert(10);
    auto n2 = heap.insert(3);
    auto n3 = heap.insert(15);
    auto n4 = heap.insert(6);
      cout << "min: " << heap.getMin() << endl;
    heap.decreaseKey(n3, 2);
    cout << "min after decrease key: " << heap.getMin() << endl;
    cout << "extracted min: " << heap.extractMin() << endl;
    cout << "new min: " << heap.getMin() << endl;
    return 0;
}
