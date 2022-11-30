//
// Created by lenovo on 2022/10/20.
//

#ifndef INC_04_LINKED_LIST_STACK_H
#define INC_04_LINKED_LIST_STACK_H
template<typename T>
class Stack {
public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};
#endif //INC_04_LINKED_LIST_STACK_H
