#ifndef __FURNITURE_H__
#define __FURNITURE_H__
#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Course
{
private:
    string title;
    string courseCode;
    string clo;

protected:
    void setTitle(string title)
    {
        this->title = title;
    }
    void setCourseCode(string courseCode)
    {
        this->courseCode = courseCode;
    }
    void setCLO(string clo)
    {
        this->clo = clo;
    }
};

#endif