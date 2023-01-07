//
// Created by wangyao on 2023/1/7.
//

#ifndef INC_06_PRIORITY_QUEUE_PRIORITYQUEUE_H
#define INC_06_PRIORITY_QUEUE_PRIORITYQUEUE_H

#include "Queue.h"
#include "MaxHeap.h"

template<class T>
class PriorityQueue : public Queue<T>{
private:
    MaxHeap<T> *maxHeap;
public:
    PriorityQueue(){
        maxHeap = new MaxHeap<T>();
    }
    int getSize(){
        return maxHeap->size();
    }
    int getCapacity(){
        return maxHeap->getCapacity();
    }
    bool isEmpty(){
        return maxHeap->isEmpty();
    }
    T getFront(){
        return maxHeap->findMax();
    }
    void enqueue(T e){
        maxHeap->add(e);
    }
    T dequeue(){
        return maxHeap->extractMax();
    }
};


#endif //INC_06_PRIORITY_QUEUE_PRIORITYQUEUE_H
