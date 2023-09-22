/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 26 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    int noOfPostalCodes;
    Population* canadaPop;


	void sort() {
        int i, j;
        Population temp;
        for (i = noOfPostalCodes - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (canadaPop[j].population > canadaPop[j + 1].population) {
                    temp = canadaPop[j];
                    canadaPop[j] = canadaPop[j + 1];
                    canadaPop[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& pop) {
        bool ok = false;
        char code[4];
        int number;

        if (read(code) && read(number)) {
            pop.postalCode = new char[strLen(code) + 1];
            strCpy(pop.postalCode, code);
            pop.population = number;
        }
        return ok;
    }

    bool load(const char filename[]) {
        bool ok = false;
        int i;
        if (openFile(filename)) {
            noOfPostalCodes = noOfRecords();

            if (noOfPostalCodes == 0) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!<ENDL>";
            }
            else {
                canadaPop = new Population[noOfPostalCodes];
                for (i = 0; i < noOfPostalCodes; i++) {
                     load(canadaPop[i]);
                }

                ok = true;
            }
          
        }
        else {
            cout << "Could not open data file: " << filename << "<ENDL>";
        }
        closeFile();
        return ok;
    }
    
    void display(Population& pop) {
        cout << pop.postalCode << ":  " << pop.population << endl;
    }

    void display() {
        int i;
        int total = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();
        for (i = 0; i < noOfPostalCodes; i++) {
            cout << i + 1 << "- ";
            display(canadaPop[i]);
            total += canadaPop[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }

    void deallocateMemory() {
        int i;
        if (canadaPop != nullptr)
        for (i = 0; i < noOfPostalCodes; i++) {
            delete[] canadaPop[i].postalCode;
        }
        delete[] canadaPop;
    }

}