//
// Created by lenovo on 2022/10/10.
//

#ifndef INC_03_STACK_ARRAYSTACK_H
#define INC_03_STACK_ARRAYSTACK_H

#include "Array.h"
#include "Stack.h"

template<typename T>
class ArrayStack : public Stack<T>{
public:
    ArrayStack(int capacity){
        array = new Array<T>(capacity);
    }
    ArrayStack(){
        array = new Array<T>();
    }
    ~ArrayStack(){
        delete[] array;
        array = nullptr;
    }
    int getSize(){
        return array->getSize();
    }
    bool isEmpty(){
        return array->isEmpty();
    }
    void push(T e){
        array->addLast(e);
    }
    T pop(){
        return array->removeLast();
    }
    T peek(){
        return array->getLast();
    }
    /**
     * 打印数组的所有元素
     */
    void print() {
        std::cout << "ArrayStack: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
        std::cout << "bottom ";
        array->print();
        std::cout << " top" << std::endl;
    }

private:
    Array<T> *array;
};

#endif //INC_03_STACK_ARRAYSTACK_H
