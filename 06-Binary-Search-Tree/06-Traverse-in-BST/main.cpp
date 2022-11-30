#include <iostream>
#include <stack>

#include "BST.h"

int main() {
    BST<int> *bst = new BST<int>();
    int nums[] = {5, 3, 2, 4, 6, 8};
    for (int i = 0; i < 6; ++i)
        bst->add(nums[i]);
//    bst->preOrder();
//    std::cout << std::endl;
//    bst->preOrderNR();
    bst->levelOrder();

    return 0;
}
