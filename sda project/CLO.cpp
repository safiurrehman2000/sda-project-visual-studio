#include <iostream>
#include "topics.cpp"
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

class CLO
{
public:
    Topics * topics;
    string courseName;
  
    CLO(string courseName, string topics[]) {
        
        this -> courseName = courseName;
        this -> topics = new Topics[sizeof(topics)];

        for (int i = 0; i < sizeof(topics); i++)
        {
            this->topics[i].topic = topics[i];
            this->topics[i].isCovered = false;
        }

        fstream fin("CLO.txt", ios::app);
        fin << this->courseName << "\n";

        for (int i = 0; i < sizeof(topics); i++)
        {
            fin << this->topics[i].topic << "\n";
        }
        cout << "----";
    }

    void getClO() 
    {

    }
};