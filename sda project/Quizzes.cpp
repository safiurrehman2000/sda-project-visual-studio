#include <iostream>
using namespace std;
#include "CLO.cpp"
#include "Evaluations.cpp"
#include "Questions.cpp"

class Quiz : public Evaluation
{
private:
    Questions questions;

public:
    Quiz()
    {
        string Qs = "";
        int a = 0;
        cout << "Enter how many Qs you want for the quiz \n";
        cin >> a;
        cout << "Enter your Qs \n";
        cin.ignore();
        for (int i = 0; i < a; i++)
        {
            cin.clear();
            cin.sync();
            std::getline(cin, Qs, '\n');
        }
        cout << "Quiz made with " << a << "questions \n";
    }
    int countQuestions(CLO id) {}
};