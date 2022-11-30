//
// Created by lenovo on 2022/10/9.
//

#ifndef INC_01_ARRAY_STUDENT_H
#define INC_01_ARRAY_STUDENT_H
#include <string>
#include <ostream>
class Student{
public:
    Student(std::string studentName = "", int studentScore = 0){
        name = studentName;
        score = studentScore;
    }
    friend std::ostream & operator <<(std::ostream &out, Student &student){
        out << "name : " << student.name << ", " << "score : " << student.score;
        return out;
    }
private:
    std::string name;
    int score;
};
#endif //INC_01_ARRAY_STUDENT_H
