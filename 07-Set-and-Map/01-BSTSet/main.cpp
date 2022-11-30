#include <iostream>
#include <vector>
#include <string>
#include "BSTSet.h"
#include "FileOperation.h"
#include "LinkedListSet.h"

template<typename T>
double testSet(T *set, string filename) {
    clock_t startTime = clock();
    srand(66);
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word: words) {
            set->add(word);
        }
        std::cout << "Total different words: " << set->size() << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
    double time1 = testSet(bstSet, filename);
    std::cout << "BST Set : " << time1 << " s " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    double time2 = testSet(linkedListSet, filename);
    std::cout << "LinkedList Set : " << time2 << " s " << endl;
    // 分别使用linkedList set 与 bst set 计算words
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words;
//    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        BSTSet<string> *bstSet = new BSTSet<string>();
//        for (string word: words) {
//            bstSet->add(word);
//        }
//        std::cout << "Total different words: " << bstSet->size() << std::endl;
//    }
//    std::cout << std::endl;
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words2;
//    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words2)) {
//        std::cout << "Total words: " << words2.size() << std::endl;
//        LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
//        for (string word: words2) {
//            linkedListSet->add(word);
//        }
//        std::cout << "Total different words: " << linkedListSet->size() << std::endl;
//    }
//
//    std::cout << std::endl;
//    std::cout << "pride and prejudice.txt" << std::endl;
//    vector<string> words1;
//    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
//        std::cout << "Total words: " << words1.size() << std::endl;
//        BSTSet<string> *bstSet1 = new BSTSet<string>();
//        for (string word: words1) {
//            bstSet1->add(word);
//        }
//        std::cout << "Total different words: " << bstSet1->size() << std::endl;
//    }
//
//
//    std::cout << std::endl;
//    std::cout << "pride and prejudice.txt" << std::endl;
//    vector<string> words3;
//    if (FileOps::readFile(".././pride-and-prejudice.txt", words3)) {
//        std::cout << "Total words: " << words3.size() << std::endl;
//        LinkedListSet<string> *linkedListSet1 = new LinkedListSet<string>();
//        for (string word: words3) {
//            linkedListSet1->add(word);
//        }
//        std::cout << "Total different words: " << linkedListSet1->size() << std::endl;
//    }
    return 0;
}
