#include <iostream>
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
        cin >> description;

        string outcome = "";
        cout << "Enter PLO outcome: ";
        cin >> outcome;

        this->description = description;
        this->outcome = outcome;
    }

    PLO(string description, string outcome)
    {
        this->description = description;
        this->outcome = outcome;
    };

    void print()
    {
        cout << "Description: " << description << endl;
        cout << "Outcome: " << outcome << endl
             << endl;
    }

    void getCoursesByPlo(PLO) {}
};