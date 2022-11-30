#include <iostream>
#include <vector>
#include "BST.h"

int main() {
    BST<int> *bst = new BST<int>();
//    int nums[] = {5, 3, 2, 4, 6, 8};
//    for (int i = 0; i < 6; ++i)
//        bst->add(nums[i]);
//    bst->levelOrder();
//    std::cout<<std::endl;
//    bst->removeMin();
//    bst->levelOrder();
//    std::cout<<std::endl;
//    bst->removeMax();
//    bst->levelOrder();
    int n = 1000;
    for(int i =0;i<n;++i){
        bst->add(rand()%10000);
    }
    std::vector<int> *v1 = new std::vector<int>();

    std::cout<< "Before deleting the minimum BST size : " << bst->getSize() << std::endl;
    while (!bst->isEmpty())
        v1->push_back(bst->removeMin());
    std::cout<<"After deleting the minimum BST size : " << bst->getSize() <<std::endl;
    for(int i = 1;i < v1->size(); i ++){
        if(v1->at(i-1) > v1->at(i)){
            std::cout<<"error";
            return -1;
        }
    }
    std::cout<<"Remove Min test completed." << std::endl;
    v1 = nullptr;
    delete v1;

    for(int i =0;i<n;++i){
        bst->add(rand()%10000);
    }
    std::vector<int> *v2 = new std::vector<int>();

    std::cout<< "Before deleting the maximum BST size : " << bst->getSize() << std::endl;
    while (!bst->isEmpty())
        v2->push_back(bst->removeMax());
    std::cout<<"After deleting the maximum BST size : " << bst->getSize() <<std::endl;
    for(int i = 1;i < v2->size(); i ++){
        if(v2->at(i-1) < v2->at(i)){
            std::cout<<"error";
            return -1;
        }
    }

    std::cout<<"Remove Max test completed." << std::endl;
    v2 = nullptr;
    delete v2;
    return 0;
}
