#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <stack>
#include <math.h>
#include "Queue.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"

#include <vector>
#include <map>

using namespace std;

int totalFruit(vector<int> &fruits) {
    map<int, int> *count = new map<int ,int>();

    int i = 0, j = -1;
    // 在[i...j]之间同时满足count.size() <= 2，此时的收获数量是j-i+1
    while(i < fruits.size()){
        if(count->size()<=2){
            j++;
        } else{
            int type = fruits[i];
            // if type in count count.add(type, count.get(type)-1)
            if(fruits[i])
            i++;
        }
    }
}

int main() {


    return 0;
}
