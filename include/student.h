#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "../include/person.h"
#include "../include/subject.h"

class student : public person
{
protected:
    int avggrade;

public:
    student();
    subject getSubject(int);
    int getSubjectsSize();
};

#endif