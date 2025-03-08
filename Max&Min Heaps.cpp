#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary Heap (Max-Heap)
class BinaryMaxHeap {
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int extractMax() {
        if (heap.empty()) {
            return -1;
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }
    bool isEmpty() const {
        return heap.empty();
    }
    void printHeap(){
        for(int i : heap){
            cout << i << " ";
        }
        cout << endl;
    }
private:
    vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] <= heap[parentIndex]) {
                break;
            }
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

};

// Binary Heap (Min-Heap)
class BinaryMinHeap {
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int extractMin() {
        if (heap.empty()) {
            return -1;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }

    bool isEmpty() const {
        return heap.empty();
    }
    void printHeap(){
        for(int i : heap){
            cout << i << " ";
        }
        cout << endl;
    }
private:
    vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] >= heap[parentIndex]) break;
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest == index) {
                break;
            }
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
};

int main() {
    BinaryMaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(3);
    maxHeap.printHeap();
    cout << "Max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();
    BinaryMinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(3);
    minHeap.printHeap();
    cout << "Min: " << minHeap.extractMin() << endl;
    minHeap.printHeap();
    return 0;
}
