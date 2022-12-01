#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class User
{
protected:
    string name;
    string username;
    string password;

public:
    virtual void takeUserInput() = 0;
    virtual void writeToFile() = 0;
    virtual void login() = 0;
    virtual bool checkDuplicate(string username) = 0;
};