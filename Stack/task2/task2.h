#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
#include <fstream>

using namespace std;

// Parse first integer in string and move position
int get_first_int(string str, int & position);

// Find minimum number at position j for all numbers at position i,
// where i < j and number[i] < number[j]
string find_numbers(string str);
