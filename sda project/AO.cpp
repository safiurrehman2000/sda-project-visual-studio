#include <iostream>
#include <string>
#include <fstream>
#include "Users.cpp"
#include "Program.cpp"
#include "Course.cpp"
using namespace std;

class AcademicOfficer : public Users, Program, Course
{
    public:
    AcademicOfficer(string n, string u, string p)
    {
        cout << "Academic Officer default constructor called.\n";
        name = n;
        username = u;
        password = p;

        ofstream fout; 

        fout.open("AO.txt", ios::app);
        fout << name << " " << username << " " << password << endl;
        fout.close();
    }
};