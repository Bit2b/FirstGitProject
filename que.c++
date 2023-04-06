#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify_down(vector<int>& heap, int index, int size) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int largest = index;
    if (left_child < size && heap[left_child] > heap[largest]) {
        largest = left_child;
    }
    if (right_child < size && heap[right_child] > heap[largest]) {
        largest = right_child;
    }
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify_down(heap, largest, size);
    }
}

int main() {
    vector<int> heap = {4, 7, 2, 9, 3, 1, 5};
    vector<int> temp_heap(heap);
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify_down(temp_heap, i, size);
    }
    cout << "Max-heap traversal: ";
    auto it = temp_heap.begin();
    while (it != temp_heap.end()) {
        cout << *it << " ";
        ++it;
        if (it != temp_heap.end()) {
            swap(temp_heap.front(), temp_heap.back());
            --size;
            heapify_down(temp_heap, 0, size);
        }
    }
    cout << endl;
    for(auto x:heap)cout<<x<<" ";
    cout<<endl;
    return 0;
}
