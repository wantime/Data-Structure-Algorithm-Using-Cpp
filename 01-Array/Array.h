//
// Created by lenovo on 2022/10/9.
//

#ifndef INC_01_ARRAY_ARRAY_H
#define INC_01_ARRAY_ARRAY_H

#include <cassert>
#include <iostream>

template<typename T>
class Array{
private:
    //元素个数
    int size;
    //存储数据的数组（可更换为模板）
    T *data;
    //容量
    int capacity;
    // 当Array里的元素个数超过capacity时进行扩容
    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for(int i = 0; i < size; i ++){
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
        newData = nullptr;
        delete[] newData;
    }
public:
    // 有参构造函数
    Array(int capacity){
        data = new T[capacity];
        size = 0;
        this->capacity = capacity;
    }
    // 无参构造函数
    Array(){
        Array(10);
    }
    // 析构函数
    ~Array(){
        delete data;
    }
    // 返回数组的元素个数
    int getSize(){
        return size;
    }
    // 返回数组的容量
    int getCapacity(){
        return capacity;
    }
    // 返回数组是否为空
    bool isEmpty(){
        return size == 0;
    }
    // 在索引为index的位置插入一个元素
    void add(int index, T e){
        assert(index >= 0 && index <= size);

        if(size == capacity)
            resize(capacity*2);

        for (int i = size; i >= index; i--)
            data[i+1] = data[i];

        data[index] = e;
        size ++;
    }
    // 在最开始的位置插入一个元素
    void addFirst(T e){
        add(0, e);
    }
    // 在最末尾的位置插入一个元素
    void addLast(T e){
        add(size, e);
    }
    // 获取索引为index的元素
    T get(int index){
        return data[index];
    }
    // 修改索引index处的数值
    void set(int index, T e){
        data[index] = e;
    }
    // 查看数组中是否包含某个元素
    bool contains(T e){
        assert(size > 0);
        for (int i = 0; i < size; i ++)
            if (data[i] == e)
                return true;

        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(T e){
        assert(size > 0);
        for (int i = 0; i < size; i ++)
            if(data[i] == e)
                return i;

        return -1;
    }


    T remove(int index){
        assert(index >= 0 && index < size);

        T ret = data[index];
        for(int i = index+1;i<size;i++)
            data[i-1] = data[i];
        size --;

        if(size== capacity/4 && capacity/4 != 0){
            resize(capacity/4);
        }

        return ret;
    }

    T removeFirst(){
        return remove(0);
    }

    T removeLast(){
        return remove(size-1);
    }

    // 从数组中删除元素e
    void removeElement(T e){
        int index = find(e);
        if(index != -1)
            remove(index);

    }

    // 打印数组所有元素
    void print(){
        assert(size > 0);
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for(int i = 0; i < size; i ++){
            std::cout<<data[i];
            if(i != size-1){
                std::cout << ", ";
            }
        }
        std::cout << "]";
        std::cout<<std::endl;
    }
};
#endif //INC_01_ARRAY_ARRAY_H
