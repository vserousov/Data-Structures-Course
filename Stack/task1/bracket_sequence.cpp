#include "bracket_sequence.h"
#include "stack.h"

/*
Name + Surname: Serousov Vitaly
Group: 201(1) SE
Date: 24.01.2015
Task: Correct bracket sequence
IDE: Microsoft Visual Studio 2010
*/

/*
Finds correct bracket sequence, using three type of brackets: (), [], {}
Finds its length and fills the corresponding function parameter

Returns true if the current string is a complete correct bracket sequence, false otherwise
Precondition : str is not NULL and contains only three type of brackets, length = 0
Сomplexity : O(n)
Memory: O(n)
*/



bool find_sequence(const string & str, int & prefix_length) {

    // Write your code here
    stack s;

    // Bool flag to detect whether the iteration was stopped
    bool did_not_stop = true;

    for (int i = 0; i < str.size() && did_not_stop; i++) {

        // detect each symbol
        switch (str[i]) {

            // opening brackets
            case '(':
            case '[':
            case '{':
                // if stack is not full
                if (!s.isfull()) {

                    // add symbol to stack
                    s.push(str[i]);

                    // increase prefix length
                    prefix_length++;

                } else {
                    // otherwise break loop
                    // our stack has the limit of 50 symbols
                    did_not_stop = false;
                }
                break;

            // first type of closing brackets
            case ')':

                // if stack is not empty 
                // and the type of closing bracket is equal to type of opening bracket
                if (!s.isempty() && s.what_is_top() == '(') {

                    // delete symbol from stack
                    s.pop();

                    // increase prefix length
                    prefix_length++;

                } else {
                    // otherwise break loop
                    did_not_stop = false;
                }
                break;

            // Second type of closing brackets
            case ']':

                // If stack is not empty 
                // and the type of closing bracket is equal to type of opening bracket
                if (!s.isempty() && s.what_is_top() == '[') {

                    // Delete symbol from stack
                    s.pop();

                    // Increase prefix length
                    prefix_length++;

                } else {
                    // Otherwise break loop
                    did_not_stop = false;
                }
                break;

            // Third type of closing brackets
            case '}':

                // If stack is not empty 
                // and the type of closing bracket is equal to type of opening bracket
                if (!s.isempty() && s.what_is_top() == '{') {

                    // Delete symbol from stack
                    s.pop();

                    // Increase prefix length
                    prefix_length++;

                } else {
                    // Otherwise break loop
                    did_not_stop = false;
                }
                break;

            // If it is 'space' just skip it
            case ' ':
                break;

            // If it is illegal symbol stop the program
            default:
                did_not_stop = false;
                break;
        }
    }

    // If iteration through sequence has stopped, it means that sequence is illegal
    // If stack is not empty, it means that sequence is illegal too
    // That's why we need to check both both conditions
    bool result = did_not_stop && s.isempty();

    // If the result is True we don't return prefix length
    // So it set to default (0)
    if (result) {
        prefix_length = 0;
    }

    // Return result
    return result;
}
