#include <iostream>
#include <string>
#include "LinkedListMap.h"
#include "FileOperation.h"
#include <vector>
using namespace std;
int main() {
    std::cout<<"pride-and-prejudice.txt"<<std::endl;
    std::string filename = ".././pride-and-prejudice.txt";
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    vector<string> words;
    if(FileOps::readFile(filename, words)){
        std::cout<<"Total words: "<<words.size() << std::endl;
        for(string word:words){
            if(linkedListMap->contains(word)){
                linkedListMap->set(word, linkedListMap->get(word)+1);
            } else{
                linkedListMap->add(word, 1);
            }
        }
        std::cout<<"Total different words: "<<linkedListMap->getSize()<<std::endl;
        std::cout<<"Frequency of PRIDE: " << linkedListMap->get("pride") << std::endl;
        std::cout<<"Frequency of PREJUDICE: " << linkedListMap->get("prejudice") << std::endl;
    }

    return 0;
}
