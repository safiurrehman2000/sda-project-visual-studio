#include <iostream>
#include <fstream>
#include "AO.cpp"
#include "Teacher.cpp"
#include <string>
#include "Program.cpp"
using namespace std;

string programsFile = "Programs.txt";
vector<Program> programs;


bool loginAO(string username, string password)
{
    fstream fin("AO.txt");
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

void loadDataFromFile()
{
    // load programs
    ifstream fin;

    fin.open(programsFile, ios::in);

    while (!fin.eof()) {
        string temp;
        getline(fin, temp);
        Program program;

        program.takeInputFromString(temp);
        program.print();
        programs.push_back(program);
    }

    fin.close();

    // load academic officers
    

    // load teachers
}

int main()
{
    loadDataFromFile();

    int a = 0;
    int b = 0;
    string name = "";
    string username, password, confirmPassword;
    User user;

    cout << "Enter 1 for academic officer or 2 for teacher: ";

    // Academic Officer
    cin >> a;
    if (a == 1)
    {
        cout << "Enter 1 to signup or 2 for login: ";
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

            if (password == confirmPassword)
            {
                user = AcademicOfficer(name, username, password);
                cout << "User successfully created, you are now logged in. \n";
            }
            else
            {
                cout << "Error, passwords do not match. \n";
            }

            goto passwordsDontMatch;
        }
        // Academic Officer Login
        else if (b == 2)
        {
        wrongCredentials:

            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (loginAO(username, password))
            {
                int a = 0;
                cout << "You are now logged in. \n\n";
                aoAdminPanel:
                cout << "Choose from the four options listed below: \n\n";
                cout << "Enter 1 to Manage Programs.\n"
                     << "Enter 2 to Manage PLOs.\n"
                     << "Enter 3 to Manage Courses.\n"
                     << "Enter 4 to CLOs.\n\n";
                cin >> a;
                cout << "\n";
                if (a == 1)
                {
                    int b = 0;
                    cout << "You chose to Manage Programs.\n\n";
                    cout << "Enter 1 to Add Program.\n"
                         << "Enter 2 to Delete Program.\n"
                         << "Enter 3 to Update Program.\n\n";
                    cin >> b;
                    cout << "\n";
                    if (b == 1)
                    {
                        cout << "You chose to Add Program.\n\n";
                        Program program = Program();
                        program.takeInput();
                        program.writeToFile();

                        programs.push_back(program);

                        goto aoAdminPanel;
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
                else {
                    cout << "No option exists for that input, try again.\n";
                }
                goto aoAdminPanel;
            }
            else {
                cout << "No account exists with those credentials, try again.\n";
                goto wrongCredentials;
            }
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