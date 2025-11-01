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
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            int cNode  = data[pos];
            int pNode = data[parent];

            if (weightArr[cNode] < weightArr[pNode]) {
                int tmp = data[pos];
                data[pos] = data[parent];
                data[parent] = tmp;

                pos = parent;
            } else {
                break;
            }
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            if (left >= size) break; // no children
            int small = left;
            if (right < size) {
                int leftNode  = data[left];
                int rightNode = data[right];
                if (weightArr[rightNode] < weightArr[leftNode]) {
                    small = right;
                }
            }
            int smallest = data[small];
            int curNode = data[pos];

            if (weightArr[smallest] < weightArr[curNode]) {
                int tmp = data[small];
                data[small] = data[pos];
                data[pos] = tmp;

                pos = small;
            } else {
                break;
            }
        }
    }
};

#endif