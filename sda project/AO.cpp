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
    AcademicOfficer()
    {
        name = "";
        username = "";
        password = "";
    }

    void takeUserInput()
    {
        string name = "";
        cout << "Please enter your full name: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        std::getline(cin, name, '\n');

    enterUniqueUsername:

        string username;
        cout << "Please enter a username: ";
        cin >> username;

    passwordsDontMatch:

        string password;
        cout << "Please enter a password: ";
        cin >> password;

        string confirmPassword;
        cout << "Please reenter your password: ";
        cin >> confirmPassword;

        if (password == confirmPassword)
        {
            if (checkDuplicate(username) == false)
            {
                this->name = name;
                this->username = username;
                this->password = password;

                writeToFile();
                cout << "User successfully created, you are now logged in.\n";
            }
            else
            {
                goto enterUniqueUsername;
            }
        }
        else
        {
            cout << "Error, passwords do not match. \n";
            goto passwordsDontMatch;
        }
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setUsername(string username)
    {
        this->username = username;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    string getName()
    {
        return name;
    }

    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    void takeInputFromString(string data)
    {
        string name = "";
        int i = 0;
        for (; i < data.length(); i++)
        {
            if (data[i] == '~')
            {
                break;
            }
            else
            {
                name += data[i];
            }
        }

        i++;

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

        i++;

        string password = "";
        for (; i < data.length(); i++)
        {
            if (data[i] == '\n')
            {
                break;
            }
            else
            {
                password += data[i];
            }
        }

        this->name = name;
        this->username = username;
        this->password = password;
    }

    void writeToFile()
    {
        ofstream fout;
        fout.open(fileName, ios::app);

        fout << name << "~" << username << '~' << password << endl;

        fout.close();
    }

    void login()
    {
        string username;
        string password;

    wrongCredentials:

        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        ifstream fin;
        fin.open(fileName, ios::in);

        string data;
        int i;
        while (!fin.eof())
        {
            i = 0;
            getline(fin, data, '\n');

            AcademicOfficer academicOfficer;
            academicOfficer.takeInputFromString(data);

            if (academicOfficer.getUsername() == username && academicOfficer.getPassword() == password)
            {
                this->name = academicOfficer.getName();
                this->username = academicOfficer.getUsername();
                this->password = academicOfficer.getPassword();

                cout << "User successfully logged in.\n";
                return;
            }
        }

        cout << "No account exists with those credentials, try again.\n";
        goto wrongCredentials;
    }

    bool checkDuplicate(string username)
    {
        ifstream fin;
        fin.open(fileName, ios::in);

        string data;
        string tempUsername;
        int i;
        while (!fin.eof())
        {
            i = 0;
            data = "";
            getline(fin, data, '\n');

            for (; i < data.length(); i++)
            {
                if (data[i] == '~')
                {
                    break;
                }
                else
                {
                    tempUsername += data[i];
                }
            }

            i++;

            tempUsername = "";
            for (; i < data.length(); i++)
            {
                if (data[i] == '~')
                {
                    break;
                }
                else
                {
                    tempUsername += data[i];
                }
            }

            // check if username is already used or not
            if (tempUsername == username)
            {
                cout << "An account already exists with that username, please try again.\n";
                fin.close();
                return true;
            }

            // traversing to next line
            for (; i < data.length(); i++)
            {
                if (data[i] == '\n')
                {
                    break;
                }
            }

            i++;
        }

        fin.close();
        return false;
    }
};