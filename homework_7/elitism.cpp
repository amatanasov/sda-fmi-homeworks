#include <vector>
#include <array>
#include <iostream>
#include <iomanip>
#include <cassert>

#define HEAP_SIZE 250002

/**
 * Heap implementation with static initialization that uses std::array
 * @tparam T typename
 * @tparam Compare comparator typename - you can use std::less|std::greater here
 * @tparam heapSize size of the container
 */
template<typename T, typename Compare, int heapSize>
class Heap {
public:
    void push(int value) {
        assert(head < heapSize);
        int pos = head++;
        heap[pos] = value;
        bubbleUp(pos);
    }

    void pop() {
        assert(head > TOP);
        std::swap(heap[TOP], heap[--head]);
        bubbleDown(TOP);
    }

    int top() const {
        assert(head > TOP);
        return heap[TOP];
    }

    int size() const {
        return head - 1;
    }

private:
    static const int TOP = 1;
    std::array<T, heapSize> heap;
    Compare cmp;
    int head = 1;

    int parent(int index) {
        return index / 2;
    }

    int left(int index) {
        return index * 2;
    }

    int right(int index) {
        return index * 2 + 1;
    }

    void bubbleDown(int index) {
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if (l < head && !cmp(heap[l], heap[index])) {
            smallest = l;
        }

        if (r < head && !cmp(heap[r], heap[smallest])) {
            smallest = r;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            bubbleDown(smallest);
        }
    }

    void bubbleUp(int index) {
        while (parent(index) > 0 && cmp(heap[parent(index)], heap[index])) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
};

void heapSolution(const std::vector<int> &vec) {
    Heap<int, std::less<int>, HEAP_SIZE> maxheap;
    Heap<int, std::greater<int>, HEAP_SIZE> minheap;

    double median = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] <= median) {
            maxheap.push(vec[i]);
        } else {
            minheap.push(vec[i]);
        }

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }

        if (minheap.size() == maxheap.size()) {
            median = (minheap.top() + maxheap.top()) / 2.0;
        } else if (minheap.size() > maxheap.size()) {
            median = minheap.top();
        } else {
            median = maxheap.top();
        }

        std::cout << median << std::endl;
    }
}

void insertionSort(std::vector<int> &arr) {
    int n = arr.size();
    int i, key, j;
    std::cout << (float) arr[0];
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        if ((i % 2)) {
            std::cout << (arr[i / 2] + arr[i / 2 + 1]) / 2.0;
        } else {
            std::cout << (float) arr[i / 2];
        }

        std::cout << std::endl;
    }
}

int main() {
    int N;
    std::vector<int> vec;
    std::cin >> N;
    std::cout << std::fixed << std::setprecision(1);
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }

    // insertionSort(vec) is also a solution
    heapSolution(vec);
    return 0;
}
