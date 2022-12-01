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
    int countQuestions(CLO id) {}
};