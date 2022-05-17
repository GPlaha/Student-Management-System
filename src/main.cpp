#include <iostream>
#include <string>
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/person.h"
#include "../include/personManager.h"
#include "../include/subject.h"
#include "../include/utilities.h"

extern void ignoreCin(); // this finds the function that is anywhere in the project

int main()
{
    personManager pM;
    int option;
    while (true)
    {
        system("cls");
        std::cout << "Welcome to the School Manager" << std::endl;
        std::cout << "Please Select one of the following" << std::endl;
        std::cout << "1. Teachers" << std::endl;
        std::cout << "2. Students" << std::endl;
        std::cout << "3. Exit" << std::endl;
        option = utilities::getNumberFunction("Option: ");
        if (option == 1)
        {

            do
            {
                std::cout << "1. Enter details" << std::endl;
                std::cout << "2. Show details" << std::endl;
                std::cout << "3. Search Record" << std::endl;
                std::cout << "4. Update Record" << std::endl;
                std::cout << "5. Delete Record" << std::endl;
                std::cout << "6. Exit" << std::endl;

                option = utilities::getNumberFunction("Option: ");
                system("cls");
                switch (option)
                {
                case 1:
                {

                    system("cls");
                    pM.addTeacher();
                    break;
                }

                case 2:
                {
                    system("cls");
                    pM.showTeacherList();
                    break;
                }

                case 3:
                {
                    pM.searchTeacherList();
                    break;
                }

                case 4:
                {
                    pM.updateTeacherList();
                    break;
                }

                case 5:
                {
                    pM.deleteTeacherData();
                    break;
                }

                case 6:
                {
                    break;
                }

                default:
                {
                    std::cout << "Invalid input" << std::endl;
                }
                }

            } while (option != 6);
        }
        else if (option == 2)
        {

            do
            {
                std::cout << "1. Enter details" << std::endl;
                std::cout << "2. Show details" << std::endl;
                std::cout << "3. Search Record" << std::endl;
                std::cout << "4. Update Record" << std::endl;
                std::cout << "5. Delete Record" << std::endl;
                std::cout << "6. Exit" << std::endl;
                std::cout << "#########################" << std::endl;

                option = utilities::getNumberFunction("Option: ");
                system("cls");
                switch (option)
                {
                case 1:
                {

                    pM.addStudent();
                    break;
                }

                case 2:
                {

                    pM.showStudentList();
                    break;
                }

                case 3:
                {
                    pM.searchStudentList();
                    break;
                }

                case 4:
                {
                    pM.updateStudentList();
                    break;
                }

                case 5:
                {
                    pM.deleteStudentData();
                    break;
                }

                case 6:
                {
                    break;
                }

                default:
                {
                    std::cout << "Invalid input" << std::endl;
                }
                }

            } while (option != 6);
        }
        else if (option == 3)
        {
            return 0;
        }
        else
        {
            std::cout << "No valid input.. please try again" << std::endl;
        }
    }
}
