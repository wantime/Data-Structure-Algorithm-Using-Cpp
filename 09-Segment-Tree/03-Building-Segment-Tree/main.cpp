#include <iostream>
#include "SegmentTree.h"
int main() {

    int nums[] = {1, 2, 3};
    SegmentTree<int> *segmentTree = new SegmentTree<int>(nums,3,
                                                         [](int a, int b) -> int {
        return a + b;
    });
    segmentTree->print();


    return 0;
}
