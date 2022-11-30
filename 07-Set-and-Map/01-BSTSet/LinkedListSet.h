//
// Created by lenovo on 2022/10/27.
//

#ifndef INC_01_BSTSET_LINKEDLISTSET_H
#define INC_01_BSTSET_LINKEDLISTSET_H


#include "Set.h"
#include "LinkedList.h"

template<typename T>
class LinkedListSet : public Set<T>{
public:
    LinkedListSet(){
        linkedList = new LinkedList<T>();
    }
    void add(T e){
        if(!linkedList->contains(e))
            linkedList->addLast(e);
    }
    int size(){
        return linkedList->getSize();
    }
    bool empty(){
        return linkedList->isEmpty();
    }
    bool contains(T e){
        return linkedList->contains(e);
    }
    void remove(T e){
        linkedList->remove(e);
    }
    ~LinkedListSet(){
        linkedList = nullptr;
        delete linkedList;
    }

private:
    LinkedList<T> *linkedList;
};

#endif //INC_01_BSTSET_LINKEDLISTSET_H
