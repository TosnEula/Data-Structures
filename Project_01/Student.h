#include <iostream>
#include <array>
#include <string>
#include "Course.h"
#include "Person.h"

#ifndef Student_h
#define Student_h


class Student : public Person
{
   uint32_t totalCreditHours;
   uint32_t numberOfCourses;
   uint32_t uid;
   Course *courses; //Creates a course pointer which acts as the head of the singlely linked list
   Student *studNext; //Used in Records to point to the next student class in the list
   Student *studPrev; //Used in Records to point to the previous student class in the list
   double gpa;

public:
    Student(); //For testing purposes
    Student(uint32_t uid, const std::string &name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses, double gpa);

    Student *getStudPrev() const;
    void setStudPrev(Student *studPrev);

    Student *getStudNext() const;
    void setStudNext(Student *studNext);

    uint32_t getTotalCreditHours() const;
    void setTotalCreditHours(uint32_t totalCreditHours);

    uint32_t getNumberOfCourses() const;
    void setNumberOfCourses(uint32_t numberOfCourses);

    uint32_t getUid() const;
    void setUid(uint32_t uid);

    double getGpa() const;
    void setGpa(double gpa);

/*
    const std::string &getName() const;
    void setName(const std::string &name);

    uint8_t getAge() const;
    void setAge(uint8_t age);
*/
    //Adds a course to the singlely linked list
    void addCourse(std::string a_Code, std::string a_Title, uint8_t a_CreditHour, double a_grade);
    //Deletes a course from the singlely linked list
    void deleteCourse(std::string a_code);

    friend std::ostream& operator<< (std::ostream& os, Student& student);
};

#endif //Student_h