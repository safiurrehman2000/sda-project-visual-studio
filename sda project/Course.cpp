#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CLO.cpp"
using namespace std;

class Course {
private:
    string title;
    string courseCode;
    vector<CLO> clos;

protected:
    void setTitle(string title) {
        this->title = title;
    }

    void setCourseCode(string courseCode) {
        this->courseCode = courseCode;
    }

public:
    Course() {
        string title = "";
        cout << "Enter course title: ";
        cin >> title;

        string courseCode = "";
        cout << "Enter course code: ";
        cin >> courseCode;

        int temp = 0;
        cout << "How many ClOs do you want to enter: ";
        cin >> temp;

        vector<CLO> clos;
        for (int i = 0; i < temp; i++) {
            clos.push_back(CLO());
        }

        this->title = title;
        this->courseCode = courseCode;
        this->clos = clos;
    }

    Course(string title, string courseCode, vector<CLO> clos) {
        this->title = title;
        this->courseCode = courseCode;
        this->clos = clos;
    }
};