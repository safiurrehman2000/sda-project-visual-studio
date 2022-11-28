#include <iostream>
using namespace std;

#pragma once

class Topic
{
private:
    string topic;
    bool isCovered;

public:
    Topic()
    {
        string topic;
        cout << "Enter topic name: ";
        cin >> topic;

        this->topic = topic;
        isCovered = 0;
    }

    void print()
    {
        cout << "Title: " << topic << endl;

        if (isCovered)
        {
            cout << "Topic covered.\n";
        }
        else
        {
            cout << "Topic not yet covered.\n";
        }
    }
};