//
// Created by lenovo on 2022/10/24.
//

#ifndef INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
#define INC_02_BINARY_SEARCH_TREE_BASICS_BST_H

#include <iostream>
#include <stack>
#include <queue>
#include <cassert>

template<typename T>
class Node {
public:
    T e;
    Node<T> *left, *right;

    Node(T e) {
        this->e = e;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST {
public:
    BST() {
        root = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add(T e) {
        root = add(root, e);
    }

    bool contains(T e) {
        return contains(root, e);
    }

    void preOrder() {
        preOrder(root);
    }

    void preOrderNR() {
        std::stack<Node<T> *> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node<T> *curNode = stack.top();
            std::cout << curNode->e << std::endl;
            stack.pop();
            if (curNode->right != nullptr)
                stack.push(curNode->right);
            if (curNode->left != nullptr)
                stack.push(curNode->left);
        };
        std::cout << std::endl;
    }

    void levelOrder() {
        std::queue<Node<T> *> *q = new std::queue<Node<T> *>();
        q->push(root);
        while (!q->empty()) {
            Node<T> *cur = q->front();
            std::cout << cur->e << " ";
            q->pop();
            if (cur->left != nullptr) {
                q->push(cur->left);
            }
            if (cur->right != nullptr) {
                q->push(cur->right);
            }
        }
        q = nullptr;
        delete q;
    }
//    void inOrderNR(){
//        std::stack<Node<T> *> stack;
//        Node<T> *cur = root;
//        while (cur != nullptr || !stack.empty()){
//
//        }
//    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    T minimum() {
        assert(size > 0);

        return minimum(root)->e;
    }

    T maximum() {
        assert(size > 0);

        return maximum(root)->e;
    }

    T removeMin() {
        T ret = minimum();
        root = removeMin(root);
        return ret;
    }

    T removeMax() {
        T ret = maximum();
        root = removeMax(root);
        return ret;
    }

    void remove(T e){
        root = remove(root, e);
    }

    void generateBSTString(Node<T> *node, int depth) {
        if (node == nullptr) {
            generateDepthString(depth);
            std::cout << "NULL" << std::endl;
            return;
        }
        generateDepthString(depth);
        std::cout << node->e << std::endl;
        generateBSTString(node->left, depth + 1);
        generateBSTString(node->right, depth + 1);
    }

    void print() {
        generateBSTString(root, 0);
    }

private:
    Node<T> *root;
    int size;

    void preOrder(Node<T> *node) {
        if (node == nullptr)
            return;
        std::cout << node->e << std::endl;
        preOrder(node->left);
        preOrder(node->right);
    }


    void inOrder(Node<T> *node) {
        if (node == nullptr)
            return;

        inOrder(node->left);
        std::cout << node->e << std::endl;
        inOrder(node->right);
    }

    void postOrder(Node<T> *node) {
        if (node == nullptr)
            return;

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->e << std::endl;
    }

    bool contains(Node<T> *node, T e) {
        if (node == nullptr)
            return false;
        else if (node->e > e)
            return contains(node->left, e);
        else if (node->e < e)
            return contains(node->right, e);
        else // node->e == e
            return true;
    }

    Node<T> *add(Node<T> *node, T e) {
        if (node == nullptr) {
            size++;
            return new Node<T>(e);
        } else if (node->e > e)
            node->left = add(node->left, e);
        else if (node->e < e)
            node->right = add(node->right, e);
        return node;
    }

    Node<T> *minimum(Node<T> *node) {
        if (node->left == nullptr)
            return node;
        else
            return minimum(node->left);
    }

    Node<T> *removeMin(Node<T> *node) {
        if (node->left == nullptr) {
            Node<T> *rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node<T> *removeMax(Node<T> *node) {
        if (node->right == nullptr) {
            Node<T> *leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

    Node<T> *maximum(Node<T> *node) {
        if (node->right == nullptr)
            return node;
        else
            return maximum(node->right);
    }

    Node<T> * remove(Node<T> *node, T e){
        if(node == nullptr)
            return nullptr;

        if(node->e < e){
            node->left = remove(node->left, e);
            return node;
        } else if(node->e > e){
            node->right = remove(node->right, e);
            return node;
        } else{ //node->e == e
            if(node->left == nullptr){
                Node<T> *rightNode = node->right;
                node = nullptr;
                delete node;
                size--;
                return rightNode;
            } else if(node->right = nullptr){
                Node<T> *leftNode = node->left;
                node = nullptr;
                delete node;
                size--;
                return leftNode;
            }
            //else if(node->left != nullptr && node->right != nullptr)
            // 先找到前驱
            // 再删去前驱原来的位置
            // 处理左子树
                Node<T> *successor = minimum(node->right);
                successor->right = removeMin(node->right);
                successor->left = node->left;

                node = nullptr;
                delete node;

                return successor;
        }


    }

    void generateDepthString(int depth) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "--";
        }
    }
};

#endif //INC_02_BINARY_SEARCH_TREE_BASICS_BST_H
