
#ifndef PLAY_DATA_STRUCT_BY_CPP_STUDENT_H
#define PLAY_DATA_STRUCT_BY_CPP_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student{

    string name;
    int score;

    bool operator<(const Student &otherStudent){

        if(score != otherStudent.score)
            return score < otherStudent.score;
        else
            return name < otherStudent.name;
    }

    friend ostream& operator<<(ostream &os, const Student &student){

        os<<"Student: " <<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //PLAY_DATA_STRUCT_BY_CPP_STUDENT_H

