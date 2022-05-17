#include "../include/personManager.h"
#include "../include/subject.h"
#include "../include/utilities.h"
#include <iostream>
#include <stdexcept>

void personManager::addStudent()
{
    student newStudent = student();

    std::string userInput;

    std::cout << "Enter The Details of the new student: " << std::endl;
    newStudent.setpersonName(utilities::getStringFunction("Name: "));
    newStudent.setpersonAge(utilities::getNumberFunction("Age: "));
    newStudent.setpersonDOB(utilities::getStringFunction("DOB in format DD/MM/YYYY: "));
    newStudent.setpersonGender(utilities::getStringFunction("Gender: ")[0]);
    newStudent.setpersonContactNum(utilities::getStringFunction("Contact Number: "));
    newStudent.setpersonAddress(utilities::getStringFunction("Address: "));
    newStudent.setpersonID(currentStudent + 1);
    int subs = utilities::getNumberFunction("Number of subjects: ");

    for (int currentSub = 0; currentSub < subs; currentSub++)
    {
        newStudent.addSubject();
    }

    for (int studentIndex = 0; studentIndex < sizeof(studentList) / sizeof(studentList[0]); studentIndex++) //
    {
        if (studentList[studentIndex].getpersonID() == 0)
        {
            studentList[studentIndex] = newStudent;
            currentStudent++;
            return;
        }
    }

    std::cout << "The school is at max capacity." << std::endl;
};

void personManager::deleteStudentData()
{
    int studentID = utilities::getNumberFunction("Enter Student ID of the student you wish to remove: ");
    int studentIndex = findIndexofStudent(studentID);
    if (studentIndex >= 0)
    {
        char press;
        std::cout << "Are you sure you want to delete this students data?" << std::endl;
        std::cout << studentList[studentIndex].getpersonName() << std::endl;
        std::cout << "press C to confirm or anything else to cancel." << std::endl;
        std::cin >> press;
        if (press == 'c' || press == 'C')
        {
            for (studentIndex; studentIndex < sizeof(studentList) / sizeof(studentList[0]) - 1; studentIndex++)
            {
                studentList[studentIndex] = studentList[studentIndex + 1];
            }
            studentList[sizeof(studentList) / sizeof(studentList[0]) - 1] = student();
        }
    }
    else
    {
        std::cout << "Entered ID does not exist" << std::endl;
    }
};
/**
 * @brief prints out all the students and all of their data
 *
 */
void personManager::showStudentList()
{
    system("cls");
    if (currentStudent == 0)
    {
        std::cout << "There are no currently enrolled." << std::endl;
        return;
    }
    for (int student = 0; student < sizeof(studentList) / sizeof(studentList[0]); student++)
    {
        // std::cout << student << std::endl;
        if (studentList[student].getpersonID() != 0)
        {
            std::cout << "\n\n";
            std::cout << "Student Name: " << studentList[student].getpersonName() << std::endl;
            std::cout << "Student Age: " << studentList[student].getpersonAge() << std::endl;
            std::cout << "Student Date of Birth " << studentList[student].getpersonDOB() << std::endl;
            std::cout << "Student Gender: " << studentList[student].getpersonGender() << std::endl;
            std::cout << "Student Contact Number: " << studentList[student].getpersonContactNum() << std::endl;
            std::cout << "Student Address: " << studentList[student].getpersonAddress() << std::endl;
            std::cout << "Student ID: " << studentList[student].getpersonID() << std::endl;

            for (int subjectIndex = 0; subjectIndex < sizeof(studentList[student].subjectList) / sizeof(studentList[student].subjectList[0]); subjectIndex++)
            {
                if (studentList[student].subjectList[subjectIndex].getName() != "")
                {
                    std::cout << studentList[student].subjectList[subjectIndex].getName() << " with Grade : " << studentList[student].subjectList[subjectIndex].getGradeValue() << " - " << studentList[student].subjectList[subjectIndex].getGradeNumber() << "%" << std::endl;
                    // print out the info of the subject..
                    // eg.. get name.. getGrade etc etc
                }
            }
            std::cout << "\n\n";
        }
    }
};

void personManager::searchStudentList()
{
    int studentID = utilities::getNumberFunction("Enter Student ID of the student you want to search: ");
    int studentIndex = findIndexofStudent(studentID);
    if (studentIndex >= 0)
    {
        std::cout << "\n\n";
        std::cout << "Student Name: " << studentList[studentIndex].getpersonName() << std::endl;
        std::cout << "Student Age: " << studentList[studentIndex].getpersonAge() << std::endl;
        std::cout << "Student Date of Birth " << studentList[studentIndex].getpersonDOB() << std::endl;
        std::cout << "Student Gender: " << studentList[studentIndex].getpersonGender() << std::endl;
        std::cout << "Student Contact Number: " << studentList[studentIndex].getpersonContactNum() << std::endl;
        std::cout << "Student Address: " << studentList[studentIndex].getpersonAddress() << std::endl;
        std::cout << "Student ID: " << studentList[studentIndex].getpersonID() << std::endl;

        for (int subjectIndex = 0; subjectIndex < sizeof(studentList[studentIndex].subjectList) / sizeof(studentList[studentIndex].subjectList[0]); subjectIndex++)
        {
            if (studentList[studentIndex].subjectList[subjectIndex].getName() != "")
            {
                std::cout << studentList[studentIndex].subjectList[subjectIndex].getName() << " with Grade : " << studentList[studentIndex].subjectList[subjectIndex].getGradeValue() << " - " << studentList[studentIndex].subjectList[subjectIndex].getGradeNumber() << "%" << std::endl;
                // print out the info of the subject..
                // eg.. get name.. getGrade etc etc
            }
        }
        std::cout << "\n\n";
    }
    else
    {
        std::cout << "Student with ID does not exist" << std::endl;
    }
};

void personManager::updateStudentList()
{
    int studentID = utilities::getNumberFunction("Enter Student ID of the student you wish to update: ");
    int studentIndex = findIndexofStudent(studentID);
    if (studentIndex >= 0)
    {
        std::cout << "1. Update Name" << std::endl;
        std::cout << "2. Update Age" << std::endl;
        std::cout << "3. Update DOB" << std::endl;
        std::cout << "4. Update Gender" << std::endl;
        std::cout << "5. Update Contact Number" << std::endl;
        std::cout << "6. Update Address" << std::endl;
        std::cout << "7. Update subjects" << std::endl;
        int option = utilities::getNumberFunction("Option: ");
        system("cls");
        switch (option)
        {
        case 1:
            studentList[studentIndex].setpersonName(utilities::getStringFunction("Name: "));
            break;
        case 2:
            studentList[studentIndex].setpersonAge(utilities::getNumberFunction("Age: "));
            break;
        case 3:
            studentList[studentIndex].setpersonDOB(utilities::getStringFunction("DOB in format DD/MM/YYYY: "));
            break;
        case 4:
            studentList[studentIndex].setpersonGender(utilities::getStringFunction("Gender: ")[0]);
            break;
        case 5:
            studentList[studentIndex].setpersonContactNum(utilities::getStringFunction("Contact Number: "));
            break;
        case 6:
            studentList[studentIndex].setpersonAddress(utilities::getStringFunction("Address: "));
            break;
        case 7:
        {
            int subs = utilities::getNumberFunction("Number of subjects: ");

            for (int currentSub = 0; currentSub < subs; currentSub++)
            {
                studentList[studentIndex].addSubject();
            }
            break;
        }

        default:
            break;
        }
    }
    else
    {
        std::cout << "Student with ID does not exist" << std::endl;
    }
};

int personManager::findIndexofStudent(int studentID)
{
    for (int student = 0; student < sizeof(studentList) / sizeof(studentList[0]); student++)
    {
        if (studentList[student].getpersonID() == studentID)
        {
            return student;
        }
    }
    return -1;
};

// TEACHER //
//=================================================================================//

void personManager::addTeacher()
{
    teacher newTeacher = teacher();

    std::string userInput;

    std::cout << "Enter The Details of the new Teacher: " << std::endl;
    newTeacher.setpersonName(utilities::getStringFunction("Name: "));
    newTeacher.setpersonAge(utilities::getNumberFunction("Age: "));
    newTeacher.setpersonDOB(utilities::getStringFunction("DOB in format DD/MM/YYYY: "));
    newTeacher.setpersonGender(utilities::getStringFunction("Gender: ")[0]);
    newTeacher.setpersonContactNum(utilities::getStringFunction("Contact Number: "));
    newTeacher.setpersonAddress(utilities::getStringFunction("Address: "));
    newTeacher.setpersonID(currentTeacher + 1111);

    for (int TeacherIndex = 0; TeacherIndex < sizeof(teacherList) / sizeof(teacherList[0]); TeacherIndex++)
    {
        if (teacherList[TeacherIndex].getpersonID() == 0)
        {
            teacherList[TeacherIndex] = newTeacher;
            currentTeacher++;
            return;
        }
    }

    std::cout << "The school does not require teachers." << std::endl;
};

void personManager::deleteTeacherData()
{
    int TeacherID = utilities::getNumberFunction("Enter Teacher ID of the Teacher you wish to remove: ");
    int TeacherIndex = findIndexofTeacher(TeacherID);
    if (TeacherIndex >= 0)
    {
        char press;
        std::cout << "Are you sure you want to delete this Teachers data?" << std::endl;
        std::cout << teacherList[TeacherIndex].getpersonName() << std::endl;
        std::cout << "press C to confirm or anything else to cancel." << std::endl;
        std::cin >> press;
        if (press == 'c' || press == 'C')
        {
            for (TeacherIndex; TeacherIndex < sizeof(teacherList) / sizeof(teacherList[0]) - 1; TeacherIndex++)
            {
                teacherList[TeacherIndex] = teacherList[TeacherIndex + 1];
            }
            teacherList[sizeof(teacherList) / sizeof(teacherList[0]) - 1] = teacher();
        }
    }
    else
    {
        std::cout << "Entered ID does not exist" << std::endl;
    }
};
/**
 * @brief prints out all the Teachers and all of their data
 *
 */
void personManager::showTeacherList()
{
    system("cls");
    if (currentTeacher == 0)
    {
        std::cout << "There are no teachers currently hired." << std::endl;
        return;
    }
    for (int Teacher = 0; Teacher < sizeof(teacherList) / sizeof(teacherList[0]); Teacher++)
    {
        if (teacherList[Teacher].getpersonID() != 0)
        {
            std::cout << "\n\n";
            std::cout << "Teacher Name: " << teacherList[Teacher].getpersonName() << std::endl;
            std::cout << "Teacher Age: " << teacherList[Teacher].getpersonAge() << std::endl;
            std::cout << "Teacher Date of Birth " << teacherList[Teacher].getpersonDOB() << std::endl;
            std::cout << "Teacher Gender: " << teacherList[Teacher].getpersonGender() << std::endl;
            std::cout << "Teacher Contact Number: " << teacherList[Teacher].getpersonContactNum() << std::endl;
            std::cout << "Teacher Address: " << teacherList[Teacher].getpersonAddress() << std::endl;
            std::cout << "Teacher ID: " << teacherList[Teacher].getpersonID() << std::endl;
            std::cout << "\n\n";
        }
    }
};

void personManager::searchTeacherList()
{
    int TeacherID = utilities::getNumberFunction("Enter Teacher ID of the Teacher you want to search: ");
    int TeacherIndex = findIndexofTeacher(TeacherID);
    if (TeacherIndex >= 0)
    {
        std::cout << "\n\n";
        std::cout << "Teacher Name: " << teacherList[TeacherIndex].getpersonName() << std::endl;
        std::cout << "Teacher Age: " << teacherList[TeacherIndex].getpersonAge() << std::endl;
        std::cout << "Teacher Date of Birth " << teacherList[TeacherIndex].getpersonDOB() << std::endl;
        std::cout << "Teacher Gender: " << teacherList[TeacherIndex].getpersonGender() << std::endl;
        std::cout << "Teacher Contact Number: " << teacherList[TeacherIndex].getpersonContactNum() << std::endl;
        std::cout << "Teacher Address: " << teacherList[TeacherIndex].getpersonAddress() << std::endl;
        std::cout << "Teacher ID: " << teacherList[TeacherIndex].getpersonID() << std::endl;
        std::cout << "\n\n";
    }
    else
    {
        std::cout << "Teacher with ID does not exist" << std::endl;
    }
};

void personManager::updateTeacherList()
{
    int teacherID = utilities::getNumberFunction("Enter Teacher ID of the Teacher you wish to update: ");
    int teacherIndex = findIndexofTeacher(teacherID);
    if (teacherIndex >= 0)
    {
        std::cout << "1. Update Name" << std::endl;
        std::cout << "2. Update Age" << std::endl;
        std::cout << "3. Update DOB" << std::endl;
        std::cout << "4. Update Gender" << std::endl;
        std::cout << "5. Update Contact Number" << std::endl;
        std::cout << "6. Update Address" << std::endl;
        std::cout << "7. Update subjects" << std::endl;
        int option = utilities::getNumberFunction("Option: ");
        system("cls");
        switch (option)
        {
        case 1:
            teacherList[teacherIndex].setpersonName(utilities::getStringFunction("Name: "));
            break;
        case 2:
            teacherList[teacherIndex].setpersonAge(utilities::getNumberFunction("Age: "));
            break;
        case 3:
            teacherList[teacherIndex].setpersonDOB(utilities::getStringFunction("DOB in format DD/MM/YYYY: "));
            break;
        case 4:
            teacherList[teacherIndex].setpersonGender(utilities::getStringFunction("Gender: ")[0]);
            break;
        case 5:
            teacherList[teacherIndex].setpersonContactNum(utilities::getStringFunction("Contact Number: "));
            break;
        case 6:
            teacherList[teacherIndex].setpersonAddress(utilities::getStringFunction("Address: "));
            break;

        default:
            break;
        }
    }
    else
    {
        std::cout << "teacher with ID does not exist" << std::endl;
    }
};

int personManager::findIndexofTeacher(int teacherID)
{
    for (int teacher = 0; teacher < sizeof(teacherList) / sizeof(teacherList[0]); teacher++)
    {
        if (teacherList[teacher].getpersonID() == teacherID)
        {
            return teacher;
        }
    }
    return -1;
};
