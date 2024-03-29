

#ifndef PLAY_DATA_STRUCT_BY_CPP_INDEXMAXHEAP_H
#define PLAY_DATA_STRUCT_BY_CPP_INDEXMAXHEAP_H

#include <iostream>
#include <cassert>
#include <math.h>
#include <algorithm>


using namespace std;

template<typename Item>
class IndexMaxHeap{
private:
    Item* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]]){
            swap(indexes[k], indexes[k/2]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k){

        while( 2*k <= count){

            int j = 2*k; //在此轮循环中,indexes[i]与indexes[j]交换位置
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]])
                j += 1;

            if( data[indexes[k]] >= data[j])
                break;
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];//reverse[i]表示i这个索引在堆中的位置
        for(int i = 0; i <= capacity; i ++){
            reverse[i] = 0;
        }
        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    //传入的i对用户而言是从0开始的，内部实现的堆的索引是从1开始的，需要处理
    void inset(int i, Item item){

        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity);

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        reverse[i] = count+1;

        count ++;
        shiftUp( count);
    }
    Item extractMax(){
        assert( count > 0 );

        Item ret = data[1];

        swap(data[1], data[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex(){

        assert( count > 0 );
        int ret = indexes[1] - 1;
        swap( indexes[1], indexes[count] );
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count --;
        shiftDown(1);
        return ret;
    }

    int getMaxIndex(){
        assert( count >= 1);
        return indexes[1];
    }

    bool contain( int i){
        assert( i + 1 >= 1 && i + 1 <= capacity );
        return reverse[i+1] != 0;
    }

    Item getItem( int i){

        assert( contain(i) );
        return data[i+1];
    }

    void change(int i, Item newItem){

        assert( contain(i) );
        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
//        for (int j = 1; j <= count; j++){
//            if(indexes[j] == i){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }


};


#endif //PLAY_DATA_STRUCT_BY_CPP_INDEXMAXHEAP_H
