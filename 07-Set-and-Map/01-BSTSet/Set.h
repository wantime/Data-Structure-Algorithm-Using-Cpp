//
// Created by lenovo on 2022/10/27.
//

#ifndef INC_01_BSTSET_SET_H
#define INC_01_BSTSET_SET_H

template<typename T>
class Set {
    virtual void add(T e) = 0;

    virtual int size() = 0;

    virtual void remove(T e) = 0;

    virtual bool contains(T e) = 0;

    virtual bool empty() = 0;

};

#endif //INC_01_BSTSET_SET_H
