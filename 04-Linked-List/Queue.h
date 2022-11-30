//
// Created by lenovo on 2022/10/20.
//

#ifndef INC_04_LINKED_LIST_QUEUE_H
#define INC_04_LINKED_LIST_QUEUE_H
template<typename T>
class Queue{
public:
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};
#endif //INC_04_LINKED_LIST_QUEUE_H
