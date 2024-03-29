//
// Created by wangyao on 2022/12/2.
//

#ifndef INC_02_HEAP_BASICS_ARRAY_H
#define INC_02_HEAP_BASICS_ARRAY_H

#include <iostream>
template<class T>
class Array{
private:
    T *data;
    int size;
    int capacity;

    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
    }
public:
    class Full{
    };
    class Range{
    };
    Array(int capacity){
        data = new T[capacity];
        size = 0;
        this->capacity = capacity;
    }

    Array() {
        data = new T[5];
        size = 0;
        capacity = 5;
    }
    Array(T arr[], int n){
        data = new T[n];
        size = n;
        for(int i = 0; i < n; i ++){
            data[i] = arr[i];
        }
        capacity = n;
    }
    int getCapacity() {
        return capacity;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void add(int index, T e){
        if(index < 0 || index > size){
            throw Range();
        }
        if(size == capacity){
            resize(2 * capacity);
        }
        for(int i = size; i > index; i --){
            data[i] = data[i-1];
        }
        data[index] = e;
        size ++;
    }
    void addFirst(T e){
        add(0, e);
    }
    void addLast(T e){
        add(size, e);
    }

    T get(int index){
        if(index < 0 || index >= size){
            throw Range();
        }
        return data[index];
    }

    void set(int index, T e){
        if(index < 0 || index >= size){
            throw Range();
        }
        data[index] = e;
    }

    bool contains(T e){
        for(int i = 0; i < size; i++){
            if(data[i] == e){
                return true;
            }
        }
        return false;
    }

    int find(T e){
        for (int i = 0; i < size; i++){
            if(data[i] == e){
                return i;
            }
        }
        return -1;
    }
    T remove(int index){
        if(index < 0 || index >= size){
            throw Range();
        }
        T ret = data[index];
        for(int i = index; i < size-1; i ++){
            data[i] = data[i+1];
        }
        size --;
        if(size == capacity / 4 && capacity / 2 != 0){
            resize(capacity/2);
        }
        return ret;
    }
    T removeFirst(){
        return remove(0);
    }
    T removeLast(){
        return remove(size-1);
    }

    void removeElement(T e){
        int index = find(e);
        if(index != -1){
            remove(index);
        }
    }

    /*
     * 辅助函数，打印数组中的所有元素
     */
    void print(){
        std::cout<<"Array size = " << size << ", capacity = " << capacity << std::endl;
        toPrint();
    }

    void swap(int i, int j){
        if(i < 0 || i >= size || j < 0 || j >= size)
            throw Range();

        T t = data[i];
        data[i] = data[j];
        data[j] = t;
    }

    void toPrint(){
        std::cout<< "[";
        for(int i = 0; i < size; ++i){
            std::cout<< data[i];
            if(i != size - 1){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

#endif //INC_02_HEAP_BASICS_ARRAY_H
