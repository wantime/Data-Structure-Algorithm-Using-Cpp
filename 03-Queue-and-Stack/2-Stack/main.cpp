#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> * stack = new std::stack<char>();
        for(int i = 0; i < s.size(); i ++){
            char c = s.at(i);
            if(c == '(' || c == '[' || c == '{')
                stack->push(c);
            else {
                if(stack->empty()){
                    return false;
                }
                char topChar = stack->top();
                if(topChar == '(' && c != ')')
                    return false;
                else if(topChar == '[' && c != ']')
                    return false;
                else if(topChar == '{' && c != '}')
                    return false;
                stack->pop();
            }
        }
        return stack->empty();
    }

    int maxDepth(string s){
        stack<char> *stack = new std::stack<char>();
        int res = 0;
        for(char c : s){
            if ( c == '(')
                stack->push(c);
            else {
                if( c == ')'){
                    if (res < stack->size())
                        res = stack->size();
                    stack->pop();
                }
            }
        }
        return res;
    }
};

int main() {


    return 0;
}
