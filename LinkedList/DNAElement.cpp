#include "DNAElement.h"

void DNAElement::readString(string description) throw(invalid_argument) {
    // Get position of first number
    int firstNumberPosition = description.find_first_of("123456789");

    // If there is no number
    if (firstNumberPosition < 0) {
        throw invalid_argument("no number");
    }
    
    // Get position of delimiter
    int delimiter = description.find(":");

    // If there is no description
    if (delimiter < 0) {
        throw invalid_argument("incorrect description");
    }

    // Parse id
    string id = description.substr(0, firstNumberPosition);
    
    // Parse number
    int number = stoi(description.substr(firstNumberPosition, delimiter - firstNumberPosition));

    // Parse base
    int basePosition = delimiter + 1;
    char base = description[basePosition];

    // If base is not valid
    if (! (base == 'A' || base == 'C' || base == 'G' || base == 'T')) {
        throw invalid_argument("incorrect base");
    }

    // Update fields
    this->id = id;
    this->number = number;
    this->base = base;
}