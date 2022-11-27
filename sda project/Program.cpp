#include <iostream>
#include <vector>
using namespace std;

#include "PLO.cpp"
#include "Course.cpp"

#pragma once

class Program {

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
    Program() {
        // Take PLOs from user.

        string programName;
        cout << "Please enter new program name: ";
        cin >> programName;

        int temp;
        cout << "How many PLOs do you want to enter: ";
        cin >> temp;

        vector<PLO> plos;
        for (int i = 0; i < temp; i++) {
            plos.push_back(PLO());
        }

        // Take courses from user.
        temp = 0;
        cout << "How many Courses do you want to enter: ";
        cin >> temp;

        vector<Course> courses;
        for (int i = 0; i < temp; i++) {
            courses.push_back(Course());
        }

        this->programName = programName;
        this->plos = plos;
        this->courses = courses;
    }

    bool operator==(const Program &obj)
    {
        Program temp;
        bool flag1 = temp.plos == obj.plos;
        bool flag2 = temp.courses == obj.courses;
        return flag1 && flag2;
    }

    void listAllCourses() {}
};