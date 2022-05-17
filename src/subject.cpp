#include "../include/subject.h"

void subject::setName(std::string Name)
{
    name = Name;
}

std::string subject::getName()
{
    return name;
}

void subject::setGradeNumber(int num)
{
    gradeNumber = num;
    if (num >= 90)
        gradeValue = "A+";
    else if (num >= 80)
        gradeValue = "A";
    else if (num >= 75)
        gradeValue = "A-";
    else if (num >= 70)
        gradeValue = "B+";
    else if (num >= 65)
        gradeValue = "B";
    else if (num >= 60)
        gradeValue = "B-";
    else if (num >= 55)
        gradeValue = "C+";
    else if (num >= 50)
        gradeValue = "C";
    else if (num >= 45)
        gradeValue = "C-";
    else
        gradeValue = "F";
}

int subject::getGradeNumber()
{
    return gradeNumber;
}

bool subject::setGradeValue(std::string value)
{

    if (value == "A+" || value == "A" || value == "A-" ||
        value == "B+" || value == "B" || value == "B-" ||
        value == "C+" || value == "C" || value == "C-" ||
        value == "F")
    {
        gradeValue = value;
        if (value == "A+")
            gradeNumber = 90;
        else if (value == "A")
            gradeNumber = 80;
        else if (value == "A-")
            gradeNumber = 75;
        else if (value == "B+")
            gradeNumber = 70;
        else if (value == "B")
            gradeNumber = 65;
        else if (value == "B-")
            gradeNumber = 60;
        else if (value == "C+")
            gradeNumber = 55;
        else if (value == "C")
            gradeNumber = 50;
        else if (value == "C-")
            gradeNumber = 45;
        else if (value == "F")
            gradeNumber = 0;
    }
    else
    {
        return false; // not a valid value
    }
    return true;
}

std::string subject::getGradeValue()
{
    return gradeValue;
}

// get subject inside the person.cpp and person.h same as the person gets and sets

/*
for (int subjectIndex =0; subjectIndex < sizeof(subjectList) / sizeof(subjectList[0]; subjectIndex++;)
{
    if (subjectList[subjectIndex].getName() != ""){
        // print out the info of the subject..
        // eg.. get name.. getGrade etc etc
    }
}


*/