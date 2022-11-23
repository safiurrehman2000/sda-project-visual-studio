#include <iostream>
#include "Program.cpp"
#include <vector>
#include <fstream>
using namespace std;

class Programs: public Program
{
private:
    vector<Program> programs;

protected:
    void addProgram(Program program)
    {
        fstream fin;
        fin.open("programs.txt", ios::app);
        // fin >> program.courses;
        programs.push_back(program);
    }
    void deleteProgram(Program program)
    {
        for (int i = 0; i < programs.size(); i++)
        {
            if (program == programs[i])
            {
                programs.erase(programs.begin() + i);
            }
        }
    }
};