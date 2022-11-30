//
// Created by wy on 2022/11/4.
//

#ifndef INC_06_LINKEDLISTMAP_BSTMAP_H
#define INC_06_LINKEDLISTMAP_BSTMAP_H

#include "Map.h"

template<typename Key, typename Value>
class BSTMap : public Map<Key, Value> {
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int size;
public:
    BSTMap(){
        root = nullptr;
        size = 0;
    }
    ~BSTMap(){
        destroy(root);
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void add(Key key, Value value){
        root = add(root, key, value);
    }
    bool contains(Key key){
        return getNode(root, key) != nullptr;
    }

    Value *get(Key key){
        Node *node = getNode(root, key);
        return node == nullptr ? nullptr : &(node->value);
    }
    void set(Key key, Value newValue){
        Node *node = getNode(root, key);
        if(node != nullptr){
            node->value = newValue;
        }
    }
    Value *remove(Key key){
        Node *node = getNode(root, key);
        if(node != nullptr){
            root = remove(root, key);
            return &(node->value);
        }
    }
private:
    Node *add(Node *node, Key key, Value value){
        if(node == nullptr){
            size ++;
            return new Node(key, value);
        }
        if(key == node->key){
            node->value = value;
        }
        else if (key > node->key){
            node->right = add(node->right, key, value);
        } else {//key < value->key
            node->left = add(node->left, key, value);
        }
        return node;
    }

    Node *getNode(Node *node, Key key){
        if(node == nullptr){
            return nullptr;
        }
        if(key == node->key ){
            return node;
        } else if(key > node->key){
            return getNode(node->right, key);
        } else { // key < node->key
            return getNode(node->left, key);
        }
    }

    void destroy(Node *node){
        if(node != nullptr){
            destroy(node->left);
            destroy(node->right);
            delete node;
            size--;
        }
    }

    Node *minimum(Node *node){
        if(node->left == nullptr)
            return node;
        return minimum(node->left);
    }
    Node *maximum(Node *node){
        if(node->right == nullptr)
            return node;
        return maximum(node->right);
    }

    Node *removeMin(Node *node){
        if(node->left == nullptr){
            Node *rightNode = node->right;
            delete node;
            size --;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node *removeMax(Node *node){
        if(node->right == nullptr){
            Node *leftNode = node->left;
            delete node;
            size --;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node *remove(Node *node, Key key){
        if(node == nullptr)
            return nullptr;

        if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        } else if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        } else { // key == node->key
            if(node->left == nullptr){
                Node *rightNode = node->right;
                delete node;
                size --;
                return rightNode;
            } else if(node->right == nullptr){
                Node *leftNode = node->left;
                delete node;
                size --;
                return leftNode;
            } else {// node->left != nullptr && node->right != nullptr

                Node *successor = new Node(minimum(node->right));
                size ++;

                successor->right = removeMin(node->right);
                successor->left = node->left;

                delete node;
                size --;

                return successor;
            }
        }
    }
};

#endif //INC_06_LINKEDLISTMAP_BSTMAP_H
