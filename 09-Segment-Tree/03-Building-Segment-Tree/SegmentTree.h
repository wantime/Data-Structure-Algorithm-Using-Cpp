//
// Created by wangyao on 2023/1/10.
//

#ifndef INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H
#define INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H

#include <cassert>
#include <functional>
#include <iostream>

template<class T>
class SegmentTree {
private:
    T *tree;
    T *data;
    int size;
    bool *notNull;
    std::function<T(T, T)> merge;
    int num = 0;
    int leftChild(int index) {
        return index * 2 + 1;
    }

    int rightChild(int index) {
        return index * 2 + 2;
    }

    void buildSegmentTree(int treeIndex, int l, int r) {

        if (l == r) {
            tree[treeIndex] = data[l];
            notNull[treeIndex] = 1;
            return;
        }
        int leftIndex = leftChild(treeIndex);
        int rightIndex = rightChild(treeIndex);

        int mid = l + (r - l) / 2;

        buildSegmentTree(leftIndex, l, mid);
        buildSegmentTree(rightIndex, mid + 1, r);
        tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
        notNull[treeIndex] = 1;
        //tree[treeIndex] = tree[leftIndex] + tree[rightIndex];
    }

public:
    SegmentTree(T arr[], int n, std::function<T(T, T)> merge) {
        this->merge = merge;
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = arr[i];
        }
        tree = new T[n * 4];
        notNull = new bool[n*4];
        for(int i = 0 ; i < n*4;i++)
            notNull[i] = 0;
        size = n;
        buildSegmentTree(0, 0, size - 1);
    }

    int getSize() {
        return size;
    }

    int get(int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }

    void print() {
        std::cout<<"[";
        for(int i = 0; i < size ; i ++){
            std::cout<<data[i];
            if(i != size - 1)
                std::cout<<", ";
        }
        std::cout<<"]"<<std::endl;
        std::cout << "[";

        for (int i = 0; i < size * 4; i++) {
            if (notNull[i]) {
                std::cout << tree[i];
            } else {
                std::cout << "NULL";
            }
            if (i != size * 4 - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};


#endif //INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H
