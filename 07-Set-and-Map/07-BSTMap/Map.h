//
// Created by wangyao on 2022/11/28.
//

#ifndef INC_07_BSTMAP_MAP_H
#define INC_07_BSTMAP_MAP_H


template<typename Key, typename Value>
class Map {
    void add(Key key, Value value);

    Value remove(Key key);

    bool contains(Key key);

    Value get(Key key);

    int getSize();

    bool isEmpty();
};



#endif //INC_07_BSTMAP_MAP_H
