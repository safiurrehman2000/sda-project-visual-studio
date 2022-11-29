#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma once

class PLO
{
private:
    string description;
    string outcome;

public:
    PLO()
    {
        string description = "";
        cout << "Enter PLO description: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, description, '\n');

        string outcome = "";
        cout << "Enter PLO outcome: ";
        cin.clear();
        cin.sync();
        std::getline(cin, outcome, '\n');

        this->description = description;
        this->outcome = outcome;
    }

    PLO(string description, string outcome)
    {
        this->description = description;
        this->outcome = outcome;
    }

    PLO(int& i, string data)
    {
        // constructing plo from string
        
        // traverse till it finds _
        string description = "";
        for (; i < data.length(); i++) {
            if (data[i] == '_') {
                break;
            }
            else {
                description += data[i];
            }
        }
        this->description = description;

        // moving i to skip the _
        i++;

        // traverse till it finds - or integer
        string outcome = "";
        for (; i < data.length(); i++) {
            if ((data[i] == '-') || (data[i] >= '0' && data[i] <= '9')) {
                break;
            }
            else {
                outcome += data[i];
            }
        }
        this->outcome = outcome;
    }

    void writeToFile(std::ofstream& fout) {
        fout << description << "_" << outcome;
    }

    void print()
    {
        cout << "Description: " << description << endl;
        cout << "Outcome: " << outcome << endl
             << endl;
    }

    void getCoursesByPlo(PLO) {}
};