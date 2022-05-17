#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "../include/student.h"
#include "../include/teacher.h"

class personManager
{
private:
    person studentList[100];
    int currentStudent = 0;

    teacher teacherList[100];
    int currentTeacher = 0;

public:
    void addStudent();
    void showStudentList();
    void searchStudentList();
    void updateStudentList();
    void deleteStudentData();

    void addTeacher();
    void showTeacherList();
    void searchTeacherList();
    void updateTeacherList();
    void deleteTeacherData();

    int findIndexofStudent(int);
    int findIndexofTeacher(int);
};

#endif