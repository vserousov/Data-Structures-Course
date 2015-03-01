#include "stack.h"

bool stack::push(char ch) {
    // Write your code here
    if (top >= (int)size - 1) {
        return false;
    }

    top++;
    data[top] = ch;

    return true;
}

bool stack::pop() {
    // Write your code here
    if (top == -1) {
        return false;
    }

    top--;

    return true;
}

bool stack::isempty() const {
    // Write your code here
    return top == -1;
}

bool stack::isfull() const {
    // Write your code here
    return top == (int)size - 1;
}

char stack::what_is_top() const {
    // Write your code here
    return data[top];
}

