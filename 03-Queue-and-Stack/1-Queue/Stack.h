//
// Created by lenovo on 2022/10/10.
//

#ifndef INC_03_STACK_STACK_H
#define INC_03_STACK_STACK_H

template<typename T>
class Stack {
public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};

#endif //INC_03_STACK_STACK_H
