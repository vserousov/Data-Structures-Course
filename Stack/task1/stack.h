#ifndef STACK_ALGO_H
#define STACK_ALGO_H
#include <stddef.h>

using namespace std;

const size_t size = 50;

struct stack {

    // Write your code here
    char* data;
    int top;

    // Constructor
    stack() {
        data = new char[size];
        top = -1;
    }

    // Destructor
    ~stack() {
        delete[] data;
    }

    bool push(char ch);
    bool pop();
    bool isempty() const;
    bool isfull() const;
    char what_is_top() const;

    // Write your code here

};

#endif
