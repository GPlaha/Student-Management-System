#include <iostream>
#include "../include/person.h"
#include "../include/subject.h"
#include "../include/utilities.h"

void person::setpersonName(std::string pName) { personName = pName; };
void person::setpersonAge(int age) { personAge = age; };
void person::setpersonDOB(std::string pDOB) { personDOB = pDOB; };
void person::setpersonGender(char Gen)
{
    personGender = Gen;
};
void person::setpersonContactNum(std::string cNum)
{
    personContactNum = cNum;
};
void person::setpersonAddress(std::string pAdd)
{
    personAddress = pAdd;
};
void person::setpersonID(int id)
{
    personID = id;
}

std::string person::getpersonName()
{
    return personName;
}
int person::getpersonAge()
{
    return personAge;
}
std::string person::getpersonDOB()
{
    return personDOB;
}
char person::getpersonGender()
{
    return personGender;
}
std::string person::getpersonContactNum()
{
    return personContactNum;
}
std::string person::getpersonAddress()
{
    return personAddress;
}
int person::getpersonID()
{
    return personID;
}

void person::addSubject()
{
    std::string input;

    subject studentSubject;

    studentSubject.setName(utilities::getStringFunction("Subject Name: "));

    bool gotGrade = false;
    while (!gotGrade)
    {
        input = utilities::getStringFunction("Grade:");
        try
        {
            int value = stoi(input);
            studentSubject.setGradeNumber(value);
            gotGrade = true;
        }
        catch (...)
        {
            gotGrade = studentSubject.setGradeValue(input);
            if (!gotGrade)
            {
                std::cout << "Please enter a valid grade (A+, A etc)";
            }
        }
    }

    for (int subjectIndex = 0; subjectIndex < sizeof(subjectList) / sizeof(subjectList[0]); subjectIndex++)
    {
        if (subjectList[subjectIndex].getName() == "")
        {
            subjectList[subjectIndex] = studentSubject;

            return;
        }
    }
}
