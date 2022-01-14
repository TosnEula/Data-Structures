#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.h"
#include "Course.h"
#include "Records.h"
#include "Student.h"

int main()
{
    //Define variables to store values retrieved from the csv file
    //Refers to the student csv file
    std::string line,word,mainName;
    uint32_t mainNumCourse;
    double mainGpa;
    std::vector<uint32_t> bit32Nums;
    int iteration=0;

    //pointer for the file of students
    std::fstream file;


    //variables for the courses csv file.
    std::fstream courFile;

    std::string courLine, courWord, courName, courCode;
    uint32_t courUID;
    double courGrade;
    uint8_t courCreditHour;
    int courIteration;

    courFile.open("../Project_01/coursesDefault.csv", std::ios::in);
    //Implementation of course file does not start until line 81


    //Create the Record object to save the data to
    Records universityRecord;

    //open the .csv file
    //Depends on the location of "cmake-build-debug" folder
    file.open("../Project_01/default.csv", std::ios::in);


    //save the first line of the file to a variable called "line"
    while(std::getline(file, line))
    {
        //break up each fragment of the lines
        std::stringstream s(line);
        iteration = 0;
        bit32Nums.clear();
        //While the broken up line has a comma(,) seperating the next word, store it in the variable word
        while (std::getline(s, word, ',')) {
            if (iteration == 0 || iteration == 2 || iteration == 3) //only instances that the line will use int_32
            {
                //stoi converts string to integer
                bit32Nums.push_back(std::stoi(word, nullptr, 10));

            } else if (iteration == 4) {
                mainNumCourse = std::stoi(word, nullptr, 10);

            } else if (iteration == 5) {
                mainGpa = std::strtod(word.c_str(), nullptr);

            } else {
                mainName = word;
            }


            iteration++;
        }

        universityRecord.addStudent(bit32Nums[0], mainName, bit32Nums[1], bit32Nums[2], mainNumCourse, mainGpa);


    }


    while(std::getline(courFile, courLine))
    {
        std::stringstream cs(courLine);
        courIteration=0;
        while(std::getline(cs, courWord, ','))
        {
            if(courIteration == 0)
            {
                courUID = std::stoi(courWord, nullptr, 10);
            }
            else if(courIteration == 1)
            {
                courCode = courWord;
            }
            else if(courIteration == 2)
            {
                courName = courWord;
            }
            else if(courIteration == 3)
            {
                courCreditHour = std::stoi(courWord, nullptr,10);
            }
            else
            {
                courGrade = std::strtod(courWord.c_str(), nullptr);
            }
            courIteration++;
        }

        universityRecord.addCourse(courUID, courCode, courName, courCreditHour, courGrade);

    }

    //Variables for the main
    uint32_t guiUid, guiCourseTotal;
    std::string guiCourseCode, guiTitle, guiName;
    double guiGpa;
    uint32_t guiCreditHours;
    uint8_t guiAge;
    char choice='z';


   std::cout << "Welcome to FlPoly Simple Student Record System" << std::endl;
   std::cout << "----------------------------------------------" << std::endl;
   while (choice!='0') {
        std::cout << "Please select one of the following:" << std::endl;
        std::cout << "[1] Print all records" << std::endl;
        std::cout << "[2] Print the record for a single student" << std::endl;
        std::cout << "[3] Add a student" << std::endl;
        std::cout << "[4] Delete a student" << std::endl;
        std::cout << "[5] Add a course to a student" << std::endl;
        std::cout << "[6] Delete a course from a student." << std::endl;
        std::cout << "[0] Exit the program" << std::endl;


        std::cin >> choice;

        switch (choice) {
            //Print all records
            case '1':
                universityRecord.printAll();
                break;
             //Print the record of a single student
            case '2':
                std::cout << "Please give the UID of the student you would like to see:";
                std::cin >> guiUid;
                std::cout << std::endl;
                universityRecord.printSingle(guiUid);
                break;
            //Add a student to the record
            case '3':
                std::cout <<"Please give the UID of the student you would like to add:";
                std::cin >> guiUid;
                std::cout <<"Please give the name of the student:";
                std::cin >> guiName;
                std::cout <<"Please give the age of the student:";
                std::cin >> guiAge;
                std::cin.ignore(1,'\n');
                std::cout <<"Please give the amount of credit hours the student has:";
                std::cin >> guiCreditHours;
                std::cout <<"Please give the amount of courses the student is taking:";
                std::cin >> guiCourseTotal;
                std::cout <<"Please give the GPA of the student :";
                std::cin >> guiGpa;
                universityRecord.addStudent(guiUid,guiName,guiAge,guiCreditHours,guiCourseTotal,guiGpa);
                break;
            //Delete a student from the record
            case '4':
                std::cout<<"Please give the UID of the student you would like to remove: ";
                std::cin >> guiUid;
                universityRecord.deleteStudent(guiUid);
                break;
            //Add a course to the student
            case '5':
                std::cout << "Please give the UID of the student you would like to add a course to:";
                std::cin >> guiUid;
                std::cout << "Please list the course code of the course:";
                std::cin >> guiCourseCode;
                std::cout << "Please list the title of the course:";
                std::cin >> guiTitle;
                std::cout << "Please list the amount of credit hours this course is worth:";
                std::cin >> guiCreditHours;
                std::cout << "Please list grade earned in this course:";
                std::cin >> guiGpa;
                universityRecord.addCourse(guiUid,guiCourseCode,guiTitle,guiCreditHours, guiGpa);
                break;
            //Delete a course from a student
            case '6':
                std::cout<<"Please give the UID of the student you would like to remove: ";
                std::cin >> guiUid;
                std::cout<<"Please give the course code of the course you would like to delete: ";
                std::cin >> guiCourseCode;
                universityRecord.deleteCourse(guiUid, guiCourseCode);
                break;
            //end program
            case '0':

                break;
            default:
                std::cout << "Not a valid option" << std::endl;
        }
    }

}