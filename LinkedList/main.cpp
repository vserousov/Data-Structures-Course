#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "DNARepairer.h"

using namespace std;

int main (int argc, char* argv[])
{
    try{
        DNARepairer dnarepairer;

        dnarepairer.readFile("test.in");

        cout << "Broken DNAs" << endl;
        dnarepairer.printDNAStorage();

        dnarepairer.repairDNA();

        cout << "Good as it is" << endl;
        dnarepairer.printDNAStorage();
    }
    catch(exception &e) {
        cout << e.what();
    }
    catch (...){
        cout << "Something wrong happend." << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

