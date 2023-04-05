#include <iostream>
#include "Array.h"
#include "Student.h"
int main() {
    Array<int> *array = new Array<int>(20);
    for (int i = 0;i < 30; i++){
        array->addLast(i);
    }
    array->print();
    array->add(1, 100);
    array->addFirst(-1);
    array->print();
    array->remove(2);
    array->print();
    array->removeElement(4);
    array->print();
    array->removeFirst();
    array->print();
    array->removeLast();
    array->print();

    array = nullptr;
    delete array;

//    Array<Student> *array1 = new Array<Student>(20);
//    array1->addLast(Student("Alice",100));
//    array1->addLast(Student("Bob",66));
//    array1->addLast(Student("Charlie",88));
//    array1->print();
//    array1 = nullptr;
//    delete array1;
//    return 0;

    return 0;
}
