#ifndef SUBJECTS_H
#define SUBJECTS_H
#include <iostream>
#include <string>
class subject
{
protected:
    std::string name;
    int gradeNumber;
    std::string gradeValue;

public:
    std::string getName();
    int getGradeNumber();
    std::string getGradeValue();
    void setName(std::string);
    void setGradeNumber(int);
    bool setGradeValue(std::string);
};

#endif
