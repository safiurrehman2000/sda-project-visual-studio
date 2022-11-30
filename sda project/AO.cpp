#include <iostream>
#include <string>
#include <fstream>
#include "User.cpp"
#include "Program.cpp"
#include "Course.cpp"
using namespace std;

class AcademicOfficer : public User, Program, Course
{
private:
    const string fileName = "AO.txt";
 
public:
    AcademicOfficer() {
        name = "";
        username = "";
        password = "";
    }

    void takeInput()
    {
        string name = "";
        cout << "Please enter your full name: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, name, '\n');

        string username = "";
        cout << "Please enter a username: ";
        cin.clear();
        cin.sync();
        std::getline(cin, username, '\n');

        passwordsDontMatch:

        string password = "";
        cout << "Please enter a password: ";
        cin.clear();
        cin.sync();
        std::getline(cin, username, '\n');

        string confirmPassword = "";
        cout << "Please reenter your password: ";
        cin.clear();
        cin.sync();
        std::getline(cin, confirmPassword, '\n');

        if (password == confirmPassword)
        {
            this->name = name;
            this->username = username;
            this->password = password;

            if (!checkDuplicate())
            writeToFile();
            cout << "User successfully created, you are now logged in. \n";
        }
        else
        {
            cout << "Error, passwords do not match. \n";
            goto passwordsDontMatch;
        }
    }

    void writeToFile() {

    }

    AcademicOfficer(string name, string username, string password)
    {
        ifstream fin;
        fin.open("AO.txt", ios::in);

        string data;
        getline(fin, data);


        // traversing the name
        int i = 0;
        for (; i < data.length(); i++)
        {
            if (data[i] == '~')
            {
                break;
            }
        }

        i++;

        // traversing and saving the username
        string username = "";
        for (; i < data.length(); i++)
        {
            if (data[i] == '~')
            {
                break;
            }
            else
            {
                username += data[i];
            }
        }

        if (!checkDuplicate(fin, username)) {
            ofstream fout;
            fin.open("AO.txt", ios::out);

            this->name = n;
            this->username = u;
            this->password = p;

            fout << name << "~" << username << "~" << password << endl;

            fout.close();
        }
    }

    bool checkDuplicate(std::ifstream &fin, string username)
    {

        fin.close();
    }
};