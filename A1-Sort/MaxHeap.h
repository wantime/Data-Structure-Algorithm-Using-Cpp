

#ifndef PLAY_DATA_STRUCT_BY_CPP_MAXHEAP_H
#define PLAY_DATA_STRUCT_BY_CPP_MAXHEAP_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;

template<typename Item>
class MaxHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        Item v = data[k];
        while (k > 1 && data[k / 2] < v) {
            data[k] = data[k / 2];
            swap(data[k / 2], data[k]);
            k /= 2;
        }
        data[k] = v;
    }

    void shiftDown(int k) {
        Item v = data[k];
        while (2 * k <= count) {

            int j = 2 * k; // 在此轮循环中，data[k]和data[j]交换
            if (j + 1 <= count && data[j + 1] > data[j])
                j += 1;

            if (v > data[j])
                break;
            data[k] = data[j];
            k = j;
        }
        data[k] = v;
    }

    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

public:
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n + 1];
        capacity = n;
        for (int i = 0; i < n; i++)
            data[i + 1] = arr[i];
        count = n;
        //heapify, from capacity/2 to 1,every item in data should be shift down one time
        for (int i = count / 2; i >= 1; i--)
            shiftDown(i);
    }


    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {

        assert(count + 1 <= capacity);
        data[count + 1] = item;
        count++;
        shiftUp(count);
    }

    void testPrint() {

        if (size() >= 100) {
            cout << "Fancy print can only work for less than 100 int";
            return;
        }

        if (typeid(Item) != typeid(int)) {
            cout << "Fancy print can only work for int item";
        }
        cout << "The max heap size is: " << size() << endl;
        cout << "data in heap: ";
        for (int i = 1; i <= size(); i++) {
            // 要求所有的数据在[0,100)之间
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }

        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }

    }

    Item extractMax() {

        assert(count > 0);
        Item ret = data[1];

        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;

    }
};

template<typename Item>
class IndexMaxHeap {
private:
    Item *data;     // 最大索引堆中的数据
    int *indexes;   // 最大索引堆中的索引

    int count;
    int capacity;

    void shiftUp(int k) {

        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(data[indexes[k / 2]], data[indexes[k]]);
            k /= 2;
        }

    }

    void shiftDown(int k) {

        while (2 * k <= count) {

            int j = 2 * k; // 在此轮循环中，data[k]和data[j]交换
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j += 1;

            if (data[indexes[k]] > data[indexes[j]])
                break;

            indexes[k] = indexes[j];
            k = j;
        }
    }

    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

public:
    IndexMaxHeap(int capacity) {

        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
    }


    IndexMaxHeap(Item arr[], int n) {
        data = new Item[n + 1];
        indexes = new int[n + 1];
        capacity = n;
        for (int i = 0; i < n; i++) {
            data[i + 1] = arr[i];
            indexes[i] = i;
        }

        count = n;
        //heapify, from capacity/2 to 1,every item in data should be shift down one time
        for (int i = count / 2; i >= 1; i--)
            shiftDown(i);
    }


    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item, int i) {

        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        count++;

        shiftUp(count);
    }

    void testPrint() {

        if (size() >= 100) {
            cout << "Fancy print can only work for less than 100 int";
            return;
        }

        if (typeid(Item) != typeid(int)) {
            cout << "Fancy print can only work for int item";
        }
        cout << "The max heap size is: " << size() << endl;
        cout << "data in heap: ";
        for (int i = 1; i <= size(); i++) {
            // 要求所有的数据在[0,100)之间
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }

        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }

    }

    Item extractMax() {
        assert(count > 0);

        Item ret = data[1];

        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    Item extractMaxIndex() {
        assert(count > 0);

        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    // 获取最大索引堆中的堆顶元素
    Item getMax(){
        assert( count > 0);
        return data[indexes[1]];
    }

    int getMaxIndex(){
        assert( count >= 1);
        return indexes[1];
    }
    void change(int i, Item newItem){
        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        for (int j = 1; j <= count;j++){
            if(indexes[j] == i){
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
    }


};

#endif //PLAY_DATA_STRUCT_BY_CPP_MAXHEAP_H
