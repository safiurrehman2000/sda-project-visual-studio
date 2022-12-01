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
    Program()
    {
        programName = "";
    }

    void takeInput()
    {
        string programName = "";
        cout << "Please enter new program name: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, programName, '\n');

        int temp = 0;
        cout << "How many PLOs do you want to enter: ";
        cin >> temp;

        vector<PLO> plos;
        for (int i = 0; i < temp; i++)
        {
            cout << "Input details for PLO-" << i + 1 << ": \n";
            plos.push_back(PLO());
        }

        // Take courses from user.
        temp = 0;
        cout << "How many Courses do you want to enter: ";
        cin >> temp;

        vector<Course> courses;
        for (int i = 0; i < temp; i++)
        {
            cout << "Input details for Course-" << i + 1 << ": \n";
            courses.push_back(Course());
        }

        this->programName = programName;
        this->plos = plos;
        this->courses = courses;
    }

    void takeInputFromString(string data)
    {
        // save program name from string
        int i = 0;

        // traverse till it finds plo length
        string programName = "";
        for (; i < data.length(); i++)
        {
            if (data[i] >= '0' && data[i] <= '9')
            {
                break;
            }
            else
            {
                programName += data[i];
            }
        }
        this->programName = programName;

        // now our i has the size of plos

        int sizeOfPlos = data[i] - 48;
        i++;

        // sending the remaining string to make a plo
        vector<PLO> plos;
        for (int j = 0; j < sizeOfPlos; j++)
        {
            plos.push_back(PLO(i, data));

            // skipping the - if more than 1 plo
            if (sizeOfPlos > 1)
            {
                i++;
            }
        }

        // now our i has size of courses

        int sizeOfCourses = data[i] - 48;
        i++;

        vector<Course> courses;
        for (int j = 0; j < sizeOfCourses; j++)
        {
            courses.push_back(Course(i, data));
        }

        this->programName = programName;
        this->plos = plos;
        this->courses = courses;
    }

    void updateCourse(int position)
    {
        courses[position].takeInput();
    }

    void addCourse(Course course)
    {
        courses.push_back(course);
    }

    void deleteCourse(int position)
    {
        courses.erase(courses.begin() + position);
    }

    void writeToFile()
    {

        // writing in this format
        // programName<number of plos>plo1-plo2...<number of courses>course1<number of clos>$<number of topics>topic1-topic2...clo1 outcome

        ofstream fout;

        fout.open("Programs.txt", ios::app);

        cout << endl;

        int plosSize = plos.size();

        fout << programName << plosSize;

        for (int i = 0; i < plosSize; i++)
        {
            plos[i].writeToFile(fout);
            if (plosSize > 1)
            {
                fout << "-";
            }
        }

        int coursesSize = courses.size();

        fout << coursesSize;

        for (int i = 0; i < plosSize; i++)
        {
            courses[i].writeToFile(fout);
            if (coursesSize > 1)
            {
                fout << "-";
            }
        }

        fout << endl;

        fout.close();
    }

    void print()
    {
        cout << "Program Name: " << programName << endl;

        for (int i = 0; i < plos.size(); i++)
        {
            cout << "PLO " << i + 1 << ": " << endl;
            plos[i].print();
        }

        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course " << i + 1 << ": " << endl;
            courses[i].print();
        }
    }

    void listAllCourses() {}

    string getProgramName()
    {
        return programName;
    }
};