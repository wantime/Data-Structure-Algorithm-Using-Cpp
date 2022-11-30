//
// Created by lenovo on 2022/10/27.
//

#ifndef INC_01_BSTSET_BSTSET_H
#define INC_01_BSTSET_BSTSET_H

#include "Set.h"
#include "BST.h"

template<typename T>
class BSTSet:public Set<T>{
public:
    BSTSet(){
        bst = new BST<T>();
    }
    int size(){
        return bst->getSize();
    }
    bool empty(){
        return bst->isEmpty();
    }
    bool contains(T e){
        return bst->contains(e);
    }
    void add(T e){
        bst->add(e);
    }
    void remove(T e){
        bst->remove(e);
    }
    ~BSTSet(){
        bst = nullptr;
        delete bst;
    }
private:
    BST<T> *bst;
};

#endif //INC_01_BSTSET_BSTSET_H
