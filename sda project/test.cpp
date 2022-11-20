#include <iostream>
#include <fstream>
//#include "AO.cpp"
//#include "teachers.cpp"
using namespace std;

//class PlO
//{
//public:
//    string program;
//
//    void getCoursesByPlo(PlO) {}
//};
//
//class Topics
//{
//    bool isCovered;
//};
//
//class Courses
//{
//    void isCovered() {}
//};
//
//class ClO
//{
//    void getClO() {}
//};
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

int main()
{
  /*  int a = 0;
    int b = 0;
    string n, u, p = NULL;
    Users user;*/

    cout << "Press 1 for academic officer or 2 for Teacher \n";
    cin >> a;
    if (a == 1)
    {
        cout << "Press 1 to signup or 2 to login \n";
        cin >> b;
        if (b == 1)
        {
            cout << "What's your name? \n";
            cin >> n;
            cout << "Enter your username \n";
            cin >> u;
            cout << "Enter your password \n";
            cin >> p;
           /* user = AcademicOfficer(n, u, p);*/
        }
    }
}