//
// Created by lenovo on 2022/10/20.
//

#ifndef INC_04_LINKED_LIST_LINKEDLISTQUEUE_H
#define INC_04_LINKED_LIST_LINKEDLISTQUEUE_H

#include "Queue.h"
#include <cassert>
#include <iostream>

template<typename T>
class QNode{
public:
    QNode(T e, QNode<T> *next) : e(e), next(next){}
    QNode(T e): e(e), next(nullptr){};
    QNode(): next(nullptr){};
    T e;
    QNode<T> *next;
};
template<typename T>
class LinkedListQueue : public Queue<T>{
private:
    QNode<T> *head;
    QNode<T> *tail;
    int size;
public:
    LinkedListQueue(){
        head = new QNode<T>();
        tail = head;
        size = 0;
    }
    ~LinkedListQueue(){
        head = nullptr;
        delete head;
        tail = nullptr;
        delete tail;
    }

    void enqueue(T e){
        if(tail == nullptr){
            tail = new QNode<T>(e);
            head = tail;
        } else{
            tail->next = new QNode<T>(e, tail);
            tail = tail->next;
        }
        size++;
    }
    T dequeue(){
        assert(!isEmpty());
        QNode<T> *retNode = head;
        head == head->next;
        retNode->next = nullptr;
        if(head == nullptr)
            tail = nullptr;
        size --;
        return retNode->e;
    }
    T getFront(){
        assert(!isEmpty());
        return head->e;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void print(){
        QNode<T> *cur = head;
        std::cout << "LinkListQueue: size = " << size << std::endl;
        std::cout << "front ";
        std::cout << "[";
        while (cur != nullptr){
            std::cout << cur->e;
            if(cur->next != nullptr){
                std::cout << ", ";
            }
            cur = cur->next;
        }
        std::cout << "] tail" << std::endl;
    }
};


#endif //INC_04_LINKED_LIST_LINKEDLISTQUEUE_H
