#include <iostream>
#include <fstream>
#include <string>
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
        string topic = "";
        cout << "Enter topic name: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, topic, '\n');

        this->topic = topic;
        isCovered = 0;
    }

    Topic(int& i, string data)
    {
        // constructing topic from string

        // traverse till it finds _
        string topic = "";
        for (; i < data.length(); i++) {
            if (data[i] == '_') {
                break;
            }
            else {
                topic += data[i];
            }
        }
        this->topic = topic;

        // moving i to skip the _
        i++;

        // traverse till it finds - or integer
        string boolean = "";
        for (; i < data.length(); i++) {
            if ((data[i] == '-') || data[i] == '_') {
                break;
            }
            else {
                boolean += data[i];
            }
        }

        if (boolean == "true") {
            this->isCovered = 1;
        }
        else if (boolean == "false") {
            this->isCovered = 0;
        }
    }

    void writeToFile(std::ofstream& fout) {
        string boolean;

        if (isCovered) {
            boolean = "true";
        } else {
            boolean = "false";
        }

        fout << topic << "_" << boolean;
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