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
    void add(T e){
        root = add(root, e);
    }
    bool contains(T e){
        return contains(root, e);
    }
private:
    bool contains(Node<T> *node, T e){
        if(node == nullptr)
            return false;
        else if(node->e > e)
            return contains(node->left, e);
        else if(node->e < e)
            return contains(node->right, e);
        else // node->e == e
            return true;
    }
    Node<T> *add(Node<T> *node, T e){
        if(node == nullptr){
            size ++;
            return new Node<T>(e);
        }
        else if(node->e > e)
            node->left = add(node->left, e);
        else if(node->e < e)
            node->right = add(node->right, e);
        return node;
    }
    Node<T> root;
    int size;
};

#endif //INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
