#include <iostream>
#include "CLO.cpp"
#include "Evaluations.cpp"
#include "Questions.cpp"
using namespace std;

class Exam : public Evaluation
{
private:
   Questions questions;

public:
   Exam()
   {
      string Qs = "";
      int a = 0;
      cout << "Enter how many Q's you want for the Exam \n";
      cin >> a;
      cin.ignore();
      for (int i = 0; i < a; i++)
      {
         cin.clear();
         cin.sync();
         std::getline(cin, Qs, '\n');
      }
      cout << "Exam made with " << a << "questions \n";
   }
   int countQuestions(CLO id) {}
};