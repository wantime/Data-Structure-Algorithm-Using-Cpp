//
// Created by lenovo on 2022/10/27.
//

#ifndef INC_05_MAP_BASICS_MAP_H
#define INC_05_MAP_BASICS_MAP_H

template<typename Key, typename Value>
class Map{
    virtual void add(Key key, Value value) = 0;
    virtual Value remove(Key key) = 0;
    virtual bool contains(Key key) = 0;
    virtual Value get(Key key) = 0;
    virtual void set(Key key, Value value) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif //INC_05_MAP_BASICS_MAP_H
