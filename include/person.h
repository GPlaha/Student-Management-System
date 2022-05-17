#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "subject.h"

class person
{
protected:
    std::string personName;
    int personAge = 0;
    std::string personDOB;
    char personGender;
    std::string personContactNum;
    std::string personAddress;
    int personID = 0;

public:
    subject subjectList[10];
    void setpersonName(std::string);
    void setpersonAge(int);
    void setpersonDOB(std::string);
    void setpersonGender(char);
    void setpersonContactNum(std::string);
    void setpersonAddress(std::string);
    void setpersonID(int);

    std::string getpersonName();
    int getpersonAge();
    std::string getpersonDOB();
    char getpersonGender();
    std::string getpersonContactNum();
    std::string getpersonAddress();
    int getpersonID();
    void addSubject();
    subject getSubject(int);
};

#endif