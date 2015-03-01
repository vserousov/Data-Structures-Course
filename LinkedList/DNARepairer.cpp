#include <Windows.h>

#include <fstream>
#include <sstream>
#include <string>
#include "DNARepairer.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//  ����� �����!!
//  ���� ���� �������� ���� ��������-����������, �������
//  ���������� ��� ���������� �� ������� ���� ������ ����
//  � pPreHead.
//  �� ������ �������� �� ��� ����������� ���� ���������� �������.
//  �������� � ������ readFile �� ����������� ������ � ��
//  ������������ ����������, � repairDNA ������ ������
//  ���������� ���!!!
//  ����� ���� ���� ������ ����� �������� ������ ���� � ���
//  ��������� ���������� LinkedList.h

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



typedef LinkedList<DNAElement> DNA;
// ����� DNA ������������ ������ �����, ������� �������� DNAElement �������
// ���� �� �� �� �����, ��� ��������!

typedef Node<DNAElement> NodeDNA;
// ����� NodeDNA ������������ ���� ����, ������� �������� DNAElement
// ������ DNA ������� �� NodeDNA

void DNARepairer::repairDNA() {
    // DNA chains iterator
    Node<DNA>* p1 = DNAStorage.getPreHead();

    // Loop through all chains
    while (p1->next != 0) {

        // Move to next chain
        p1 = p1->next;

        // DNA elements iterator
        NodeDNA *dna = (&p1->value)->getPreHead();

        // Loop through all dna elements
        while (dna->next != 0) {

            // Save pointer to previous dna
            NodeDNA *previous = dna;

            // Move dna to next position
            dna = dna->next;
            
            // Get dna element value
            DNAElement *dnaElement = &(dna->value);
            
            // Get element id
            string id = dnaElement->id;

            // Get element number
            int number = dnaElement->number;

            // Calculate right row position for this dna element, if id consists only of 1 letter
            int rowPosition = (int)id[0] - (int)'a';
            
            int i = 0;
            // If id consists of more than 1 letter
            if (id.size() > 1) {
                rowPosition = 0;
                // the equivalent rows for letters: a - 0, b - 1, c - 2, ... z - 25
                // Position is the sum (letter - a) + (power_of_alphabet() + 1) * number_of_letters
                while (i < id.size()) {
                    rowPosition += ((int)id[i] - (int)'a') + ((int)'z' - (int)'a' + 1) * (i++);
                }
            }

            // Another dna chains iterator
            Node<DNA> *p2 = DNAStorage.getPreHead();
            i = 0;

            // Move iterator to right row (rowPosition)
            while (i++ <= rowPosition) {
                p2 = p2->next;
            }

            // DNA chain found
            DNA *foundDna = &p2->value;
            // Pointer for current DNA chain
            NodeDNA *dnaBefore = foundDna->getPreHead();
            i = 0;

            // Move pointer before number 
            while (++i < number) {
                dnaBefore = dnaBefore->next;
            }

            // If element is not last
            if (! (dnaBefore->next == 0)) {
                // Move after this dna
                foundDna->moveNodeAfter(dnaBefore, previous);
            } else {
                // Otherwise add to end
                foundDna->addNodeToEnd(previous);
            }
        }
    }
}

void DNARepairer::printDNAStorage() {
    Node<DNA> * it1 = DNAStorage.getPreHead();
    while (it1->next != 0) {
        it1 = it1->next;
        //�������� �� ������ ���������

        NodeDNA * it2 = it1->value.getPreHead();
        while (it2->next != 0) {
            it2 = it2->next;
            //�������� �� ������ ���

            cout << it2->value.id << "" << it2->value.number << ":";
            cout << it2->value.base << "  ";
        }
        cout << endl;
    }
}

void DNARepairer::readFile(string filename) {
    ifstream fin(filename);

    if (!fin)
    {
        cout << "File couldn't be opened :" << filename << endl;
        return;
    }

    string line;
    getline(fin,line); // ��� ������� ������ ������� � ������ �����

    Node<DNA> * it =  DNAStorage.getPreHead();
    while (getline(fin,line))
    {
        Node<DNA> * pNewNode = new Node<DNA>;
        // ������� ���� ��� �� ����

        istringstream istr(line);
        //������� ��������� ����� ��� �������

        string strTmp;

        while (istr >> strTmp) // ��������� ����� �� �����
        {
            DNAElement tmpDNAElement;

            tmpDNAElement.readString(strTmp); // ������ ����� ������ � DNAElement

            pNewNode->value.addElementToEnd(tmpDNAElement);
            // ��������� ���������� DNAElement � ���
        }
        it->next = pNewNode;
        it = it->next;
        //��������� ��� � ���������
    }
}
