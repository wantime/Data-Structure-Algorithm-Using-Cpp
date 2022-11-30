//
// Created by lenovo on 2022/10/11.
//

#ifndef INC_03_2_QUEUE_ARRAYQUEUE_H
#define INC_03_2_QUEUE_ARRAYQUEUE_H

#include "Array.h"
#include "Queue.h"

template<typename T>
class ArrayQueue : public Queue<T> {
private:
    Array<T> *array;
public:
    ArrayQueue(int capacity) {
        array = new Array<T>(capacity);
    }

    ArrayQueue() {
        array = new Array<T>();
    }
    ~ArrayQueue(){
        delete[] array;
        array = nullptr;
    }
    void enqueue(T e) {
        array->addLast(e);
    }

    T dequeue() {
        return array->removeFirst();
    }

    T getFront() {
        return array->getFirst();
    }

    int getSize() {
        return array->getSize();
    }

    bool isEmpty() {
        return array->isEmpty();
    }

    /**
     * 打印数组的所有元素
     */
    void print() {
        //std::cout << "ArrayQueue: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
        std::cout << "Queue: front ";
        array->print();
        std::cout << " tail ";
        std::cout << std::endl;
    }
};

#endif //INC_03_2_QUEUE_ARRAYQUEUE_H
