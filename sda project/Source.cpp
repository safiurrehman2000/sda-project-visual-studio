#include <iostream>
#include <fstream>
#include "AO.cpp"
#include "teachers.cpp"
#include <string.h>
#include <string>
#include "Programs.cpp"
using namespace std;

bool loginAO(string username, string password)
{
    fstream fin("AOInfo.txt");
    string word;
    string username1, password1;
    while (fin >> word)
    {
        fin >> username1;
        fin >> password1;

        if (username1 == username && password1 == password)
        {
            return true;
        }
    }
    return false;
}

bool loginT(string username, string password)
{
    fstream fin("TeacherInfo.txt");
    string word;
    string username1, password1;
    while (fin >> word)
    {
        fin >> username1;
        fin >> password1;

        if (username1 == username && password1 == password)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a = 0;
    int b = 0;
    string n, u, p;
    Users user;

    cout << "press 1 for academic officer or 2 for teacher \n";
    cin >> a;
    if (a == 1)
    {
        cout << "press 1 to signup or 2 to login \n";
        cin >> b;
        if (b == 1)
        {
            cout << "what's your name? \n";
            cin >> n;
            cout << "enter your username \n";
            cin >> u;
            cout << "enter your password \n";
            cin >> p;
            user = AcademicOfficer(n, u, p);
        }
        else if (b == 2)
        {
            cout << "Enter your username \n";
            cin >> u;
            cout << "Enter your password \n";
            cin >> p;

            if (loginAO(u, p))
            {
                int a = 0;
                cout << "You are now logged in \n \n";
                cout << "Choose from the four options listed \n \n";
                cout << "Press 1 to Manage Programs \n"
                     << "Press 2 to Manage PLOs \n"
                     << "Press 3 to Manage Courses \n"
                     << "Press 4 to CLOs \n";
                cin >> a;
                if (a == 1)
                {
                    int b = 0;
                    cout << "You chose to Manage Programs \n \n";
                    cout << "Press 1 to Add Program \\n"
                         << "Press 2 to Delete Program \\n"
                         << "Press 3 to Update Program \\n";
                    cin >> b;
                    if (b == 1)
                    {
                        // add program
                    }
                    else if (b == 2)
                    {
                        // delete program
                    }
                    else if (b == 3)
                    {
                        // update program
                        // update PLO
                    }
                    else
                    {
                        cout << "Incorrect number entered";
                    }
                }
                else if (a == 2)
                {
                    // check satisfied PLO
                }
                else if (a == 3)
                {
                    int b = 0;
                    cout << "You selected Manage Courses \n \n"
                         << "Press 1 to Add Courses \n"
                         << "Press 2 to Delete Courses \n"
                         << "Press 3 to Update Courses \n"
                         << "Press 4 to List Courses for PLO \n";
                    cin >> b;
                    if (b == 1)
                    {
                        // add course
                    }
                    else if (b == 2)
                    {
                        // delete course
                    }
                    else if (b == 3)
                    {
                        // update courses
                        // update clos
                    }
                    else if (b == 4)
                    {
                        // list courses for PLO
                    }
                    else
                    {
                        cout << "incorrect option";
                    }
                }
            }
            else
                cout << "Incorrect Details \n";
        }
    }

    else if (a == 2)
    {
        cout << "Press 1 to signup or 2 to login \n";
        cin >> b;
        if (b == 1)
        {
            cout << "what's your name? \n";
            cin >> n;
            cout << "enter your username \n";
            cin >> u;
            cout << "enter your password \n";
            cin >> p;
            user = Teacher(n, u, p);
        }
        else if (b == 2)
        {
            cout << "Enter your username \n";
            cin >> u;
            cout << "Enter your password \n";
            cin >> p;

            if (loginT(u, p))
            {
                cout << "You are now logged in \n \n";
                cout << "Choose from the four options listed \n \n";
                cout << "Press 1 to Add covered topics against CLOs\n"
                     << "Press 2 to Make Evaluations \n"
                     << "Press 3 to Check if CLO tested \n"
                     << "Press 4 to Check all CLOs are tested \n";
            }
            else
            {
                cout << "Incorrect Details \n";
            }
        }
    }
}