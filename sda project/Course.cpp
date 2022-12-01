#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CLO.cpp"
using namespace std;

class Course
{
private:
    string title;
    string courseCode;
    vector<CLO> clos;

protected:
    void setTitle(string title)
    {
        this->title = title;
    }

    void setCourseCode(string courseCode)
    {
        this->courseCode = courseCode;
    }

public:
    Course()
    {
        title = "";
        courseCode = "";
    }

    void takeInput()
    {
        string title = "";
        cout << "Enter course title: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, title, '\n');

        string courseCode = "";
        cout << "Enter course code: ";
        cin >> courseCode;

        int temp = 0;
        cout << "How many CLOs do you want to enter: ";
        cin >> temp;

        vector<CLO> clos;
        for (int i = 0; i < temp; i++)
        {
            cout << "Input details for CLO-" << i + 1 << ": \n";
            clos.push_back(CLO());
        }

        this->title = title;
        this->courseCode = courseCode;
        this->clos = clos;
    }

    Course(string title, string courseCode, vector<CLO> clos)
    {
        this->title = title;
        this->courseCode = courseCode;
        this->clos = clos;
    }

    Course(int &i, string data)
    {
        // constructing course from string

        // traverse till it finds _
        string title = "";
        for (; i < data.length(); i++)
        {
            if (data[i] == '_')
            {
                break;
            }
            else
            {
                title += data[i];
            }
        }

        this->title = title;

        // moving i to skip the _
        i++;

        // traverse till it finds - or integer
        string courseCode = "";
        for (; i < data.length(); i++)
        {
            if ((data[i] == '-') || (data[i] == '#'))
            {
                break;
            }
            else
            {
                courseCode += data[i];
            }
        }
        this->courseCode = courseCode;

        i++;
        // now our i has size of clos
        int sizeOfClos = data[i] - 48;
        i++;

        // giving the remaining to clo
        i++;
        vector<CLO> clos;
        for (int j = 0; j < sizeOfClos; j++)
        {
            clos.push_back(CLO(i, data));

            // skipping the $ if more than 1 clo
            if (sizeOfClos > 1)
            {
                i++;
            }
        }
        this->clos = clos;
    }

    void writeToFile(std::ofstream &fout)
    {
        fout << title << "_" << courseCode << "#";

        int closSize = clos.size();

        fout << closSize;

        for (int i = 0; i < closSize; i++)
        {
            clos[i].writeToFile(fout);
            if (closSize > 1)
            {
                fout << "-";
            }
        }
    }

    void print()
    {
        cout << "Title: " << title << endl;
        cout << "Course Code: " << courseCode << endl;

        for (int i = 0; i < clos.size(); i++)
        {
            cout << "CLO " << i + 1 << ": " << endl;
            clos[i].print();
        }

        cout << endl;
    }
};