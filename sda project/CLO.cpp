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
            cout << "Input details for Topic-" << i + 1 << ": \n";
            topics.push_back(Topic());
        }

        string outcome = "";
        cout << "Enter CLO outome: ";
        cin.clear();
        cin.sync();
        std::getline(cin, outcome, '\n');

        this->topics = topics;
        this->outcome = outcome;
    }

    CLO(int& i, string data) {
        // constructing clo from string

        // our pointer is at size of topics
        int sizeOfTopics = data[i] - 48;
        i++;

        // giving to topics
        vector<Topic> topics;
        for (int j = 0; j < sizeOfTopics; j++)
        {
            topics.push_back(Topic(i, data));

            // skipping the - if more than 1 topic
            if (sizeOfTopics > 1) {
                i++;
            }
        }
        this->topics = topics;

        // our pointer is now at _ so skipping that 
        i++;

        // traverse till it finds _
        string outcome = "";
        for (; i < data.length(); i++) {
            if (data[i] == '\n' || data[i] == '$') {
                break;
            }
            else {
                outcome += data[i];
            }
        }
        this->outcome = outcome;
    }

    void writeToFile(std::ofstream& fout) {
        fout << "$";

        int topicsSize = topics.size();

        fout << topicsSize;

        for (int i = 0; i < topicsSize; i++) {
            topics[i].writeToFile(fout);
            if (topicsSize > 1) {
                fout << "-";
            }
        }

        fout << "_" << outcome;
    }

    void print()
    {
        for (int i = 0; i < topics.size(); i++)
        {
            cout << "Topic " << i + 1 << ": " << endl;
            topics[i].print();
        }

        cout << "Outcome: " << outcome << endl;
    }

    void getClO()
    {
    }
};