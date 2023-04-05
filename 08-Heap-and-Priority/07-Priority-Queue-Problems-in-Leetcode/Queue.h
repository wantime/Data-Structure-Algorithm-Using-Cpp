//
// Created by wangyao on 2023/1/7.
//

#ifndef INC_06_PRIORITY_QUEUE_QUEUE_H
#define INC_06_PRIORITY_QUEUE_QUEUE_H

template<typename T>
class Queue{
public:
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
};

#endif //INC_06_PRIORITY_QUEUE_QUEUE_H
