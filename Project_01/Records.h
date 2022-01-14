#include <iostream>
#include <array>
#include <string>
#include "Student.h"

#ifndef Records_h
#define Records_h
class Records
{

    uint32_t numberOfStudents;
    double averageGpa;
    Student *students; //student pointer for the doubly linked list, treated as the head of the list
public:
    Records();

    uint32_t getNumberOfStudents() const;
    void setNumberOfStudents(uint32_t numberOfStudents);

    double getAverageGpa() const;
    void calculateAverageGpa();

    //Adds a student to the back of the student doubly linked list
    void addStudent(uint32_t r_Uid, const std::string r_Name, uint8_t r_Age, uint32_t r_TotalCreditHours,
                    uint32_t r_NumberOfCourses, double r_Gpa);
    //Deletes a student from anywhere within the list
    void deleteStudent(uint32_t r_Uid);

    //prototype to print all the students
    void printAll();
    //Prototype to print only one student
    void printSingle(uint32_t r_uid);

    //adds a course to the back of singly linked list of the student
    void addCourse(uint32_t r_uid, std::string r_Code, std::string r_Title, uint8_t r_CreditHour,double r_Grade);
    void deleteCourse (uint32_t r_uid, std::string r_Code);

    friend std::ostream& operator<< (std::ostream& cos, Records& record);

};

#endif //Records_h