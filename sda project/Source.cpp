#include <iostream>
#include <fstream>
#include "AO.cpp"
#include "teachers.cpp"
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
    string name = "";
    string username, password, confirmPassword;
    Users user;

    cout << "Press 1 for academic officer or 2 for teacher: ";

    // Academic Officer
    cin >> a;
    if (a == 1)
    {
        cout << "Press 1 to signup or 2 for login: ";
        cin >> b;
        if (b == 1)
        {
            cin.ignore();
            cout << "Please enter your full name: ";
            getline(cin, name, '\n');

            cout << "Please enter a username: ";
            cin >> username;

            passwordsDontMatch:

            cout << "Please enter a password: ";
            cin >> password;

            cout << "Please reenter your password: ";
            cin >> confirmPassword;

            if (password == confirmPassword) {
                user = AcademicOfficer(name, username, password);
                cout << "User successfully created, you are now logged in. \n";
            }
            else {
                cout << "Error, passwords do not match. \n";
            }

            goto passwordsDontMatch;
        }
        // Academic Officer Login
        else if (b == 2)
        {
            cout << "Enter your username \n";
            cin >> username;
            cout << "Enter your password \n";
            cin >> password;

            if (loginAO(username, password))
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
    // Teacher Admin Panel
    else if (a == 2)
    {
        cout << "Press 1 to signup or 2 to login \n";
        cin >> b;
        if (b == 1)
        {
            cout << "what's your name? \n";
            cin >> name;
            cout << "enter your username \n";
            cin >> username;
            cout << "enter your password \n";
            cin >> password;
            user = Teacher(name, username, password);
        }
        // Teacher Login
        else if (b == 2)
        {
            cout << "Enter your username \n";
            cin >> username;
            cout << "Enter your password \n";
            cin >> password;

            if (loginT(username, password))
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