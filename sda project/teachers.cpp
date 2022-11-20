#include <iostream>
#include "users.cpp"
#include <fstream>
using namespace std;

class Teacher : public Users
{
public:
    Teacher(string n, string u, string p)
    {
        name = n;
        username = u;
        password = p;

        fstream fin("TeacherInfo.txt", ios::app);
        fin << name << " " << username << " " << password << endl;
    }
    // bool checkAllCloHasBeenTested(Courses)
    // {
    // }

};
