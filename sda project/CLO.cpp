#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "Topic.cpp"
#pragma once

class CLO
{
private:
    vector<Topic> topics;
    string outcome;

public:
    CLO()
    {
        int temp = 0;
        cout << "How many Topics do you want to enter: ";
        cin >> temp;

        vector<Topic> topics;
        for (int i = 0; i < temp; i++)
        {
            topics.push_back(Topic());
        }

        string outcome;
        cout << "Enter CLO outome: ";
        cin >> outcome;

        this->topics = topics;
        this->outcome = outcome;
    }

    void print()
    {
        cout << "Outcome: " << outcome << outcome;

        for (int i = 0; i < topics.size(); i++)
        {
            cout << "Topic " << i + 1 << ": " << endl;
            topics[i].print();
        }
    }

    void getClO()
    {
    }
};