//
// Created by wangyao on 2023/1/10.
//

#ifndef INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H
#define INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H

#include <cassert>

template<class T>
class SegmentTree {
private:
    T *tree;
    T *data;
    int size;

    int leftChild(int index) {
        return index * 2;
    }
    int rightChild(int index){
        return index * 2 + 1;
    }
public:
    SegmentTree(T arr[], int n){
        data = new T[n];
        for(int i = 0; i < n; i ++){
            data[i] = arr[i];
        }
        tree = new T[4 * n];
        size = n;
    }
    int getSize(){
        return size;
    }
    int get(int index){
        assert(index >= 0 && index < size);
        return data[index];
    }
};


#endif //INC_02_SEGMENT_TREE_BASICS_SEGMENTTREE_H
