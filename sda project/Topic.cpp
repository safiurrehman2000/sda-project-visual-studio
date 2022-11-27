#include <iostream>
using namespace std;

#pragma once

class Topic {
private:
    string topic;
    bool isCovered;

public:
    Topic() {
        string topic;
        cout << "Enter topic name: ";
        cin >> topic;

        this->topic = topic;
        isCovered = 0;
    }
};