#include <iostream>
#include <fstream>
#include "User.cpp"
#include "Course.cpp"
using namespace std;

class Teacher : public User {
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
