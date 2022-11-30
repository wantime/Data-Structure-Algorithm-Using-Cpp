//
// Created by lenovo on 2022/10/24.
//

#ifndef INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
#define INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
template<typename T>
class Node{
public:
    T e;
    Node<T> *left, *right;

    Node(T e){
        this->e = e;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST{
public:
    BST(){
        root = nullptr;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
private:
    Node<T> root;
    int size;
};

#endif //INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
