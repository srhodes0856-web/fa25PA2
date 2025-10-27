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
        int smallest = data[0];
        size--;
        if (size>0) {
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1) / 2;
        if (weightArr[parent] > weightArr[pos]) {
            swap(parent, pos);
        }
        else {
            cout << "Child is not smaller than parent." << endl;
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        if (weightArr[left] > weightArr[right]) {
            swap(left, right);
            if (weightArr[pos] > weightArr[left]) {
                swap(pos, left);
                if (weightArr[pos] > weightArr[right]) {
                    swap(pos, right);
                }
            }
        }
    }
};

#endif