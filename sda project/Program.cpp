#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "PLO.cpp"
#include "Course.cpp"
using namespace std;

class Program {
private:
    string programName;
    //vector<PLO> plos;
    //vector<Course> courses;

protected:
    void setProgramName(string programName)
    {
        this->programName = programName;
    };

public:
    Program() {}

    void add() {
        // Take PLOs from user.

        string programName = "";
        cout << "Please enter new program name: ";
        cin >> programName;

        //std::getline(cin, programName, '\n');

        //cin.clear();
        //cin.ignore(INT_MAX, '\n');
        //int temp = 0;
        //cout << "How many PLOs do you want to enter: ";
        //cin >> temp;

        //vector<PLO> plos;
        //for (int i = 0; i < temp; i++) {
        //    plos.push_back(PLO());
        //}

        //// Take courses from user.
        //temp = 0;
        //cout << "How many Courses do you want to enter: ";
        //cin >> temp;

        //vector<Course> courses;
        //for (int i = 0; i < temp; i++) {
        //    courses.push_back(Course());
        //}

        this->programName = programName;
        //this->plos = plos;
        //this->courses = courses;

        // Write out the program object to a file
        ofstream file_obj;
        file_obj.open("Data.txt", ios::app);

        file_obj.write((char*)this, sizeof(this));

        file_obj.close();
    }

    void listAllCourses() {}
};