#include "task2.h"

/*
Name + Surname: Serousov Vitaly
Group: 201(1) SE
Date: 24.01.2015
Task: Correct bracket sequence
IDE: Microsoft Visual Studio 2010
*/

// Input filename
const string filename = "Ent_1_2.txt";

// Entry point
// Test methods using input data from filename
int main() {
    // Read file using filestream 
    fstream fs;
    fs.open(filename, ios::in);
    string temp;
    getline(fs, temp);
    int tests = atoi(temp.c_str());
    for (int i = 0; i < tests; i++) {
        for (int j = 0; j < 2; j++) {
            getline(fs, temp);
        }
        string result = find_numbers(temp);
        cout << result << endl;
    }
    fs.close();
    system("pause");
    return 0;
}

string find_numbers(string str) {
    // Use stack to store numbers
    stack<long> s;

    // Loop through all symbols in string
    for (int i = 0; i < str.size(); i++) {

        // Parse first number and move position i
        int number1 = get_first_int(str, i);

        // At start there are no elements in stack for current 'number1'
        bool isElement = false;

        // Loop through all symbols that are at the right side of 'number1'
        for (int j = i + 1; j < str.size(); j++) {

            // Parse second number and move position j
            int number2 = get_first_int(str, j);    

            // If number2 is more than number1
            if (number2 > number1) {
                
                // If there are no element in stack
                if (!isElement) {

                    // Push it to stack
                    s.push(number2);

                    // And now there is element in stack for current 'number1'
                    isElement = true;
                } else {

                    // Read number from stack
                    int number_from_stack = s.top();

                    // If number2 is less than number from stack
                    if (number2 < number_from_stack) {

                        // Remove number from stack
                        s.pop();

                        // Add number2 to stack
                        s.push(number2);
                    }
                }
            }
        }

        // If there were no element found for 'number1'
        if (!isElement && i < str.size()) {

            // Add -1 (as was written in description)
            s.push(-1);
        }
    }

    // Result string
    string result = "";

    // Loop through all elements in stack
    while (!s.empty()) {

        // Concatenate number at the beginning of string
        // Because data is stored in stack in reversed order
        result = to_string((long long)s.top()) + " " + result;
        
        // Remove number from stack
        s.pop();
    }
    

    // Return result
    return result;
}

int get_first_int(string str, int & position) {
    // Flag for checking whether the digit was found
    bool foundDigit = false;

    // Temp string to concatenate digits
    string temp = "";

    // Loop through all symbols in string
    for (int i = position; i < str.size(); i++) {
        
        // Update current position 
        position = i;

        // If it is digit
        if (isdigit(str[i])) {
            
            // Than update flag
            foundDigit = true;

            // Concatenate digit with string
            temp += str[i];

        // If digit was found and current symbol is not digit
        } else if (foundDigit) {
            
            // Than stop loop
            break;
        }
    }

    // If there are no digit
    if (temp.size() == 0) {

        // Increment position to stop loop
        position++;
    }

    // Return number converted to int from string
    return atoi(temp.c_str());
}