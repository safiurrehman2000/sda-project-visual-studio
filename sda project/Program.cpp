#include <iostream>
#include <vector>
#include <fstream>
#include "PLO.cpp"
#include "Course.cpp"
using namespace std;
#pragma once

class Program
{
private:
    string programName;
    vector<PLO> plos;
    vector<Course> courses;

protected:
    void setProgramName(string programName)
    {
        this->programName = programName;
    };

public:
    Program() {}

    void add()
    {
        // Take PLOs from user.

        string programName = "";
        cout << "Please enter new program name: ";
        cin.ignore();
        std::getline(cin, programName, '\n');

        int temp = 0;
        cout << "How many PLOs do you want to enter: ";
        cin >> temp;

        vector<PLO> plos;
        for (int i = 0; i < temp; i++)
        {
            plos.push_back(PLO());
        }

        // Take courses from user.
        temp = 0;
        cout << "How many Courses do you want to enter: ";
        cin >> temp;

        vector<Course> courses;
        for (int i = 0; i < temp; i++)
        {
            courses.push_back(Course());
        }

        this->programName = programName;
        this->plos = plos;
        this->courses = courses;

        // Write out the program object to a file
        ofstream file_obj;
        file_obj.open("Data.txt", ios::app);

        file_obj.write((char *)this, sizeof(*this));

        file_obj.close();
    }

    void print()
    {
        cout << "Program Name: " << programName << endl;

        for (int i = 0; plos.size(); i++)
        {
            cout << "PLO " << i + 1 << ": " << endl;
            plos[i].print();
        }

        cout << endl;

        for (int i = 0; courses.size(); i++)
        {
            cout << "Course " << i + 1 << ": " << endl;
            courses[i].print();
        }
    }

    void listAllCourses() {}
};