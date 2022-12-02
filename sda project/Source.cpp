#include <iostream>
#include <fstream>
#include "AO.cpp"
#include "Teacher.cpp"
#include <string>
#include "Program.cpp"
#include "Evaluations.cpp"
#include "Exams.cpp"
#include "Quizzes.cpp"
#include "Assignments.cpp"

using namespace std;

string programsFile = "Programs.txt";
vector<Program> programs;

bool loginT(string username, string password)
{
    fstream fin("TeacherInfo.txt");
    string word;
    string username1, password1;
    while (fin >> word)
    {
        fin >> username1;
        fin >> password1;

        if (username1 == username && password1 == password)
        {
            return true;
        }
    }
    return false;
}

void loadDataFromFile()
{
    // load programs
    ifstream fin;

    fin.open(programsFile, ios::in);

    while (!fin.eof())
    {
        string temp;
        getline(fin, temp);
        Program program;

        program.takeInputFromString(temp);
        program.print();
        programs.push_back(program);
    }

    fin.close();

    // load academic officers

    // load teachers
}

int main()
{
    loadDataFromFile();

    int chooseUserType = 0;
    int chooseLogin = 0;
    string name = "";
    string username, password, confirmPassword;
    User *user;

    cout << "Enter 1 for Academic Officer or 2 for Teacher: ";
    cin >> chooseUserType;
    if (chooseUserType == 1)
    {
        user = new AcademicOfficer();

        cout << "Enter 1 to Signup or 2 for Login: ";
        cin >> chooseLogin;
        if (chooseLogin == 1)
        {
            user->takeUserInput();
            goto aoAdminPanel;
        }
        else if (chooseLogin == 2)
        {
            user->login();
            cout << "You are now logged in. \n\n";

        aoAdminPanel:

            int chooseUserType = 0;
            cout << "Choose from the four options listed below: \n\n";
            cout << "Enter 1 to Manage Programs.\n"
                 << "Enter 2 to Manage PLOs.\n"
                 << "Enter 3 to Manage Courses.\n"
                 << "Enter 4 to CLOs.\n\n";

            cin >> chooseUserType;
            cout << "\n";
            if (chooseUserType == 1)
            {

            manageProgram:

                int chooseLogin = 0;
                cout << "You chose to Manage Programs.\n\n";
                cout << "Enter 1 t3e Program.\n\n";
                cin >> chooseLogin;
                cout << "\n";
                if (chooseLogin == 1)
                {
                    cout << "You chose to Add Program.\n\n";
                    Program program = Program();
                    program.takeInput();
                    program.writeToFile();

                    programs.push_back(program);

                    goto aoAdminPanel;
                }
                else if (chooseLogin == 2)
                {
                    int deleteLine;

                    cout << "You chose to Delete Program.\n\n";

                    cout << "Here are a list of all programs: \n\n";
                    for (int i = 0; i < programs.size(); i++)
                    {
                        cout << "Program " << i + 1 << endl;
                        programs[i].print();
                    }

                    cout << "Enter which program you want to delete (enter a number): ";
                    cin >> deleteLine;

                    deleteLine--;

                    programs.erase(programs.begin() + deleteLine);

                    fstream fout;
                    fout.open(programsFile, std::ios_base::trunc);

                    for (int i = 0; i < programs.size(); i++)
                    {
                        programs[i].writeToFile();
                    }

                    fout.close();

                    goto aoAdminPanel;
                }
                else if (chooseLogin == 3)
                {
                    int updateLine;

                    cout << "You chose to Update Program.\n\n";

                    cout << "Here are a list of all programs: \n\n";
                    for (int i = 0; i < programs.size(); i++)
                    {
                        cout << "Program " << i + 1 << endl;
                        programs[i].print();
                    }

                    cout << "Enter which program you want to update (enter a number): ";
                    cin >> updateLine;

                    programs[updateLine - 1].takeInput();

                    fstream fout;
                    fout.open(programsFile, std::ios_base::trunc);

                    for (int i = 0; i < programs.size(); i++)
                    {
                        programs[i].writeToFile();
                    }

                    fout.close();

                    goto aoAdminPanel;
                }
                else
                {
                    cout << "Incorrect Number Entered.\n";
                    goto manageProgram;
                }
            }
            else if (chooseUserType == 2)
            {
                // check satisfied PLO
            }
            else if (chooseUserType == 3)
            {
                int chooseLogin = 0;
                cout << "You selected Manage Courses \n \n"
                     << "Press 1 to Add Courses \n"
                     << "Press 2 to Delete Courses \n"
                     << "Press 3 to Update Courses \n"
                     << "Press 4 to List Courses for PLO \n";

                cin >> chooseLogin;
                if (chooseLogin == 1)
                {
                    cout << "You chose to Add Course.\n\n";

                    cout << "Here are a list of all programs: \n\n";
                    for (int i = 0; i < programs.size(); i++)
                    {
                        cout << "Program " << i + 1 << endl;
                        programs[i].print();
                    }

                    int updateLine;
                    cout << "Enter which program you want to add a course into (enter a number): ";
                    cin >> updateLine;

                    Course course;
                    course.takeInput();

                    programs[updateLine - 1].addCourse(course);

                    fstream fout;
                    fout.open(programsFile, std::ios_base::trunc);

                    for (int i = 0; i < programs.size(); i++)
                    {
                        programs[i].writeToFile();
                    }

                    fout.close();
                }
                else if (chooseLogin == 2)
                {
                    int deleteProgram;

                    cout << "You chose to Delete Course.\n\n";

                    cout << "Here are a list of all programs: \n\n";
                    for (int i = 0; i < programs.size(); i++)
                    {
                        cout << "Program " << i + 1 << endl;
                        programs[i].print();
                    }

                    cout << "Enter which program you want to delete a course from (enter a number): ";
                    cin >> deleteProgram;

                    deleteProgram--;

                    programs[deleteProgram].print();

                    int deleteCourse;
                    cout << "Enter which course you want to delete (enter a number): ";
                    cin >> deleteCourse;

                    deleteCourse--;

                    programs[deleteProgram].deleteCourse(deleteCourse);

                    fstream fout;
                    fout.open(programsFile, std::ios_base::trunc);

                    for (int i = 0; i < programs.size(); i++)
                    {
                        programs[i].writeToFile();
                    }

                    fout.close();

                    goto aoAdminPanel;
                }
                else if (chooseLogin == 3)
                {
                    int updateProgram;

                    cout << "You chose to Update Course.\n\n";

                    cout << "Here are a list of all programs: \n\n";
                    for (int i = 0; i < programs.size(); i++)
                    {
                        cout << "Program " << i + 1 << endl;
                        programs[i].print();
                    }

                    cout << "Enter which program you want to update a course from (enter a number): ";
                    cin >> updateProgram;

                    updateProgram--;

                    programs[updateProgram].print();

                    int updateCourse;
                    cout << "Enter which course you want to update (enter a number): ";
                    cin >> updateCourse;

                    updateCourse--;

                    programs[updateProgram].updateCourse(updateCourse);

                    fstream fout;
                    fout.open(programsFile, std::ios_base::trunc);

                    for (int i = 0; i < programs.size(); i++)
                    {
                        programs[i].writeToFile();
                    }

                    fout.close();

                    goto aoAdminPanel;
                }
                else if (chooseLogin == 4)
                {
                    // list courses for PLO
                }
                else
                {
                    cout << "incorrect option";
                }
            }
            else
            {
                cout << "No option exists for that input, try again.\n";
            }

            goto aoAdminPanel;
        }
    }
    // Teacher Admin Panel
    else if (chooseUserType == 2)
    {
        cout << "Press 1 to signup or 2 to login \n";
        cin >> chooseLogin;
        if (chooseLogin == 1)
        {
            cout << "what's your name? \n";
            cin >> name;
            cout << "enter your username \n";
            cin >> username;
            cout << "enter your password \n";
            cin >> password;
            // user = new Teacher(name, username, password);
        }
        // Teacher Login
        else if (chooseLogin == 2)
        {
            cout << "Enter your username \n";
            cin >> username;
            cout << "Enter your password \n";
            cin >> password;

            if (loginT(username, password))
            {
                int c = 0;
                cout << "You are now logged in \n \n";
                cout << "Choose from the four options listed \n \n";
                cout << "Press 1 to Add covered topics against CLOs\n"
                     << "Press 2 to Make Evaluations \n"
                     << "Press 3 to Check if CLO tested \n"
                     << "Press 4 to Check all CLOs are tested \n";
                cin >> c;
                if (c == 1)
                {
                    string inputCLO = "";
                    cout << "Enter the CLO you want to add topics to \n";
                    cin >> inputCLO;

                    cout << "CLO Found.\n";

                    cin.ignore();
                    cin.clear();
                    cin.sync();

                    string topic = "";
                    cout << "Enter the topic: ";
                    cin >> topic;

                    cout << "Topic added to the CLO.\n";
                }
                if (c == 2)
                {

                    string typeOfEvaluation;
                    cout << "Choose from either Quiz, Assignment or Exam to make an Evaluation \n";

                retry:
                    cin >> typeOfEvaluation;

                    if (typeOfEvaluation == "Quiz" || typeOfEvaluation == "quiz")
                    {
                        Evaluation *evaluation = new Quiz();
                    }
                    else if (typeOfEvaluation == "Assignment" || typeOfEvaluation == "assignment")
                    {
                        Evaluation *evaluation = new Assignment();
                    }
                    else if (typeOfEvaluation == "Exam" || typeOfEvaluation == "exam")
                    {
                        Evaluation *evaluation = new Exam();
                    }
                    else
                    {
                        cout << "You typed in the incorrect option. Retry again. \n";
                        goto retry;
                    }
                }
            }
            else
            {
                cout << "Incorrect Details \n";
            }
        }
    }
}