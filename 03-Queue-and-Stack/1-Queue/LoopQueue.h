//
// Created by lenovo on 2022/10/11.
//

#ifndef INC_03_2_QUEUE_LOOPQUEUE_H
#define INC_03_2_QUEUE_LOOPQUEUE_H

#include <iostream>

#include "Queue.h"

template<typename T>
class LoopQueue : public Queue<T>{
private:
    T *data;
    int front;
    int tail;
    int size;
    int capacity;
    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for(int i = 0; i < getSize(); i ++){
            newData[i] = data[(i+front)%capacity];
        }
        front = 0;
        tail = getSize();
        capacity = newCapacity;
        data = newData;
        newData = nullptr;
        delete []newData;
    }
public:
    LoopQueue(int capacity){

        data = new T[capacity+1];
        front = 0;
        tail = 0;
        size = 0;
        this->capacity = capacity+1;
    }
    LoopQueue(){
        data = new T[11];
        front = 0;
        tail = 0;
        size = 0;
        capacity = 10;
    }
    ~LoopQueue(){
        delete[] data;
        data = nullptr;
    }
    int getCapacity(){
        return capacity;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return front == tail;
    }
    T getFront(){
        return data[front];
    }
    void enqueue(T e){
        // todo
        if ((tail+1)%capacity == front)
            resize(capacity*2);

        data[tail] = e;
        tail = (tail + 1)%capacity;
        size ++;
    }
    T dequeue(){
        assert(front != tail);
        T res = data[front];
        front = (front+1) % capacity;
        size --;
        if(getSize() == capacity / 4 && capacity / 2 != 0){
            resize(capacity/2);
        }

        return res;
    }
    void print(){

        std::cout << "Queue: front [";
        for (int i = 0; i < getSize(); ++i) {
            std::cout << data[(i+front)%capacity];
            if(i < getSize()-1)
                std::cout << ", ";
        }
        std::cout << "] tail ";
        std::cout << std::endl;
    }
};
#endif //INC_03_2_QUEUE_LOOPQUEUE_H
