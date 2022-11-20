#include <iostream>
#include <fstream>
#include "AO.cpp"
#include "teachers.cpp"
#include <string.h>
#include <string>
using namespace std;

//class PlO
//{
//public:
//    string program;
//
//    void getCoursesByPlo(PlO) {}
//};
//

//
//

//
//class Programs
//{
//    void listAllCourses() {}
//};
//
//class Quizzes
//{
//    int countQuestions(ClO id) {}
//};
//
//class Assigments
//{
//    int countQuestions(ClO id) {}
//};
//
//class Exams
//{
//    int countQuestions(ClO id) {}
//};
//
//class Questions
//{
//    ClO clo;
//};
//
//class Evaluation
//{
//public:
//    void checkClOhasTested(ClO id) {}
//};

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
                cout << "You are now logged in \n";
            }
            else cout << "Incorrect Details \n";
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
                cout << "You are now logged in \n";
            }
            else cout << "Incorrect Details \n";
        }
    }
    system("pause");
}