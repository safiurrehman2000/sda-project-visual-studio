#include <iostream>
#include "PLO.cpp"
#include "Course.cpp"
using namespace std;
class Program
{
private:
    PLO *plos;
    Course *courses;
    string programName;

protected:
    void setProgramName(string programName)
    {
        this->programName = programName;
    };

public:
    bool operator==(const Program &obj)
    {
        Program temp;
        bool flag1 = temp.plos == obj.plos;
        bool flag2 = temp.courses == obj.courses;
        return flag1 && flag2;
    }
    void listAllCourses() {}
};