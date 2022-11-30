//
// Created by lenovo on 2022/10/20.
//

#ifndef INC_04_LINKED_LIST_LINKEDLISTSTACK_H
#define INC_04_LINKED_LIST_LINKEDLISTSTACK_H

#include "LinkedList.h"
#include "Stack.h"
#include <iostream>

template<typename T>
class LinkedListStack : public Stack<T>{
public:
    LinkedListStack(){
        linkedList = new LinkedList<T>();
    }
    ~LinkedListStack(){
        linkedList = nullptr;
        delete linkedList;
    }
    T pop(){
        return linkedList->removeFirst();
    }

    void push(T e){
        linkedList->addFirst(e);
    }

    T peek(){
        return linkedList->getFirst();
    }
    int getSize(){
        return linkedList->getSize();
    }
    bool isEmpty(){
        return linkedList->isEmpty();
    }

    void print(){
        std::cout << " Stack: size=" << linkedList->getSize() << std::endl;
        linkedList->print();

    }
private:
    LinkedList<T> *linkedList;
};


#endif //INC_04_LINKED_LIST_LINKEDLISTSTACK_H
