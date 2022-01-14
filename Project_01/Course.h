#include <iostream>
#include <array>
#include <string>

#ifndef Course_h
#define Course_h

class Course
{
std::string code,title;
double grade;
uint8_t creditHour;
Course *next; //Used in student, points to the next course object in the list
public:
    Course *getNext() const;

    void setNext(Course *next);

    //Defines all the variables in the course
    void setAll(std::string code, std::string title, double grade, uint8_t creditHour);

    const std::string &getCode() const;

    void setCode(const std::string &code);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    double getGrade() const;

    void setGrade(double grade);

    uint8_t getCreditHour() const;

    void setCreditHour(uint8_t creditHour);

    //Overloading the operator <<
    friend std::ostream& operator<< (std::ostream& os, Course& course);

};

#endif //Course_h