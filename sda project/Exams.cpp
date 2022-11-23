#include <iostream>
#include "CLO.cpp"
#include "Evaluations.cpp"
#include "Questions.cpp"
using namespace std;

class Exams : public Evaluation
{
private:
   Questions questions;

public:
   int countQuestions(CLO id) {}
};