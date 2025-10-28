//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
         if (size == 0) return -1;
        int small = data[0];
        size--;
        if (size>0) {
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return small;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1) / 2;
        while (pos > 0) {
            if (weightArr[pos] < weightArr[parent]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        while (true) {
            if (left >= size) break;
            int smallest = left;
            if (right < size and weightArr[data[right[]]] < weightArr[data[left]]) smallest = right;
            if (weightArr[data[smallest]] < weightArr[data[pos]]) {
                swap(data[smallest], data[pos]);
                pos = smallest;
            }
            else {
                break;
            }
        }
    }
};

#endif