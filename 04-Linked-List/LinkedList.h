//
// Created by lenovo on 2022/10/20.
//

#ifndef INC_04_LINKED_LIST_LINKEDLIST_H
#define INC_04_LINKED_LIST_LINKEDLIST_H


#include <cassert>
#include <iostream>
#include <string>

template<typename T>
class Node {
public:
    Node *next;
    T e;

    Node(T e, Node<T> *next) {
        this->e = e;
        this->next = next;
    }

    Node(T e) {
        this->e = e;
        next = nullptr;
    }

    Node() {
        next = nullptr;
    }
    ~Node(){
        next = nullptr;
        delete next;
    }
};

template<typename T>
class LinkedList {
private:
    //Node<T> *head;
    Node<T> *dummyHead;
    int size;
public:
    LinkedList() {
        dummyHead = new Node<T>();
        size = 0;
    }
    ~LinkedList(){
        dummyHead = nullptr;
        delete dummyHead;
    }
    void addElement(T e, int index) {
        assert(index >= 0 && index <= size);
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        prev->next = new Node<T>(e, prev->next);
        size++;
    }
//    void addElement(T e, int index) {
//        assert(index >= 0 && index <= size);
//        if (index == 0) {
//            addFirst(e);
//        } else {
//            Node<T> *prev = head;
//            for (int i = 1; i < index; i++) {
//                prev = prev->next;
//            }
////            Node<T> *newNode = new Node<T>(e);
////            newNode->next = prev->next;
////            prev->next = newNode;
//
//            prev->next = new Node<T>(e, prev->next);
//            size++;
//        }
//    }

    void addFirst(T e) {
        addElement(e, 0);
    }

    void addLast(T e) {
        addElement(e, size);
    }

    T getElement(int index) {
        assert(index >= 0 && index < size);
        Node<T> *cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->e;
    }

    T getFirst(){
        return getElement(0);
    }

    T getLast(){
        return getElement(size-1);
    }

    T removeElement(int index) {
        assert(index >= 0 && index < size);
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node<T> *delNode = prev->next;
        prev->next = delNode->next;
        size--;
        delNode->next = nullptr;
        return delNode->e;
    }

    T removeFirst() {
        return removeElement(0);
    }

    T removeLast() {
        return removeElement(size - 1);
    }

    void set(T e, int index){
        assert(index>= 0 && index < size);
        Node<T> *cur = dummyHead->next;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        cur->e = e;
    }

    void setFirst(T e){
        set(e, 0);
    }

    void setLast (T e){
        set(size-1, e);
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        std::cout << "head -> ";
        Node<T> *cur = dummyHead->next;
        while (cur != nullptr) {
            std::cout << cur->e << " -> ";
            cur = cur->next;
        }
        std::cout << "tail" << std::endl;
    }
//    std::string toString(){
//        Node<T> *cur =  dummyHead->next;
//        std::string res = "[ ";
//        while (cur != nullptr){
//            res = res + cur->e;
//            if(cur->next != nullptr)
//                res = res + " -> ";
//        }
//        return res + " ]"
//    }
};

#endif //INC_04_LINKED_LIST_LINKEDLIST_H
