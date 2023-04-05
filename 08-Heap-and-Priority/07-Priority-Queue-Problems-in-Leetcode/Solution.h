//
// Created by wangyao on 2023/1/7.
//

#ifndef INC_07_PRIORITY_QUEUE_PROBLEMS_IN_LEETCODE_SOLUTION_H
#define INC_07_PRIORITY_QUEUE_PROBLEMS_IN_LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

template<typename T>
class Queue{
public:
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
};


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


template<class T>
class MaxHeap{
private:
    Array<T> *data;
    // 返回完全二叉树的数组表示中，一个索引所代表的左孩子节点的索引
    int leftChild(int index){
        return index*2+1;
    }
    // 返回完全二叉树的数组表示中，一个索引所代表的右孩子节点的索引
    int rightChild(int index){
        return index*2+2;
    }
    // 返回完全二叉树的数组表示中，一个索引代表的父亲节点的索引
    int parent(int index){
        return (index - 1) / 2;
    }
    void shiftUp(int k){
        while (k > 0 && data->get(parent(k)) < data->get(k)) {
            data->swap(k, parent(k));
            k = parent(k);
        }
    }
    void shiftDown(int k){
        while (leftChild(k) < data->getSize()) {

            int j = leftChild(k);
            if (j + 1 < data->getSize() && data->get(j) < data->get(j + 1))
                j = j + 1;

            if(data->get(k) > data->get(j))
                break;
            data->swap(k, j);
            k = j;
        }
    }
public:
    MaxHeap(int capacity) {
        data = new Array<T>(capacity);
    }
    MaxHeap(){
        data = new Array<T>();
    }

    MaxHeap(T arr[], int n){
        data = new Array<T>(arr, n);
        for(int i = parent(n-1); i >= 0; i--){
            shiftDown(i);
        }
    }
    int size(){
        return data->getSize();
    }
    int getCapacity(){
        return data->getCapacity();
    }
    bool isEmpty(){
        return data->isEmpty();
    }
    void add(T e){
        data->addLast(e);
        shiftUp(data->getSize() - 1);
    }
    T findMax() {
        return data->get(0);
    }
    T extractMax(){
        T ret = findMax();

        data->swap(0, data->getSize() - 1);
        data->removeLast();
        shiftDown(0);
        return ret;
    };

    T replace(T e){
        T ret = findMax();
        data->set(0, e);
        shiftDown(0);
        return ret;
    }
};

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


class Solution {

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.find(nums[i]) == record.end()) {
                record[nums[i]] = 1;
            } else {
                record[nums[i]] += 1;
            }
        }
        //遍历的方法
//        for (unordered_map<int, int>::iterator iterator2 = record.begin(); iterator2 != record.end(); ++iterator2) {
//            std::cout << iterator2->first << " " << iterator2->second << std::endl;
//        }
        PriorityQueue<Freq> *pq = new PriorityQueue<Freq>();
        for(unordered_map<int, int>::iterator iterator1 = record.begin();iterator1 != record.end(); iterator1++){
            if(pq->getSize() < k){
                pq->enqueue(Freq(iterator1->first, iterator1->second));
            } else if(iterator1->second > pq->getFront().freq){
                pq->dequeue();
                pq->enqueue(Freq(iterator1->first, iterator1->second));
            }
        }
        vector<int> res;
        while (!pq->isEmpty()){
            res.push_back(pq->dequeue().e);
        }
        return res;
    }

private:
    class Freq {
    public:
        int e, freq;

        Freq(int e = 0, int freq = 0) {
            this->e = e;
            this->freq = freq;
        }

        bool operator<(const Freq &another) {
            if (this->freq < another.freq) {
                return false;
            } else {
                return true;
            }
        }

        bool operator>(const Freq &another) {
            if (this->freq > another.freq) {
                return false;
            } else {
                return true;
            }
        }
    };
};


#endif //INC_07_PRIORITY_QUEUE_PROBLEMS_IN_LEETCODE_SOLUTION_H
