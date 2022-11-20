#include <iostream>
#include "users.cpp"
using namespace std;

class AcademicOfficer : public Users
{
public:
    AcademicOfficer(string n, string u, string p)
    {
        name = n;
        username = u;
        password = p;

        fstream fin("AOInfo.txt", ios::app);
        fin << name << " " << username << " " << password << endl;
    }
};